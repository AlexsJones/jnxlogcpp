/*********************************************************************************
 *     File Name           :     src/logger/logger.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-31 21:48]
 *     Description         :
 **********************************************************************************/

#include "logger.hpp"
#include <stdarg.h>
#include <iostream>
#include <jnxc_headers/jnxtypes.h>
#include <jnxc_headers/jnxfile.h>
#include <jnxc_headers/jnx_ipc_socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
using namespace jnxlogcpp;

#define MAXBUFFER 1024
Logger::Logger(Configuration config):_configuration(config), b_shutdown(false)
{

  jnx_char *socketPath = (jnx_char*)_configuration.IpcSocketPath.c_str();
  
  thread_writer_sockets = make_shared<unordered_map<string,jnx_ipc_socket*> >();

  locker = make_shared<mutex>();

  if(jnx_file_exists(socketPath)) {
    jnx_file_recursive_delete(socketPath,1); 
  }

  jnx_ipc_socket *socket = jnx_socket_ipc_create(socketPath);

  jnx_ipc_socket *ipc_writer = jnx_socket_ipc_create(socketPath);

  stringstream ss;
  ss << this_thread::get_id();
  
  thread_writer_sockets->insert(make_pair(ss.str(),ipc_writer)); 

  ipc_listener = jnx_socket_ipc_listener_create(socket,100);

  StartAsyncListener();
}
Logger::~Logger(void)
{
  if(!b_shutdown) {
    Shutdown();
  }
  
  unordered_map<string,jnx_ipc_socket*>::iterator it;
  
  for(it = thread_writer_sockets->begin(); 
      it != thread_writer_sockets->end(); ++it) {
    
    jnx_ipc_socket_destroy(&(*it).second);
  }

  if(ipc_listener != NULL) {
    jnx_socket_ipc_listener_destroy(&ipc_listener);
  }
};
const string Logger::EnumToString(LoggerState state) {

  switch(state) {
    case INFO:
      return string("INFO");
      break;
    case DEBUG:
      return string("DEBUG");
      break;
    case WARN:
      return string("WARN");
      break;
    case ERROR:
      return string("ERROR");
      break;
    case HALT:
      return string("HALT");
      break;
    default:
      return string("INFO");
  }
}
const string Logger::CurrentDateTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  return buf;
}

void Logger::Write(const stringstream& ss) {

  stringstream sa;
  sa << this_thread::get_id();
  
  auto it = thread_writer_sockets->find(sa.str()); 

  if(it == thread_writer_sockets->end()) {
    lock_guard<mutex> guard(*locker);
    jnx_char *socketPath = (jnx_char*)_configuration.IpcSocketPath.c_str();
  
    jnx_ipc_socket *socket = jnx_socket_ipc_create(socketPath);

    jnx_ipc_socket *ipc_writer = jnx_socket_ipc_create(socketPath);

    thread_writer_sockets->insert(make_pair(ss.str(),ipc_writer)); 
    
    jnx_socket_ipc_send(ipc_writer,(jnx_uint8*)ss.str().c_str(),ss.str().size());
    cout << "Created new socket " 
      << socket << "for unseen thread " << this_thread::get_id() << endl;
    return;
  }
    jnx_socket_ipc_send(it->second,(jnx_uint8*)ss.str().c_str(),ss.str().size());
}
void Logger::Write(LoggerState state, const char *file, 
    const char *function, int line, const char *format, ...) {
  stringstream ss;
  ss << "[" << EnumToString(state) << "]";
  ss << "[" << CurrentDateTime() << "]";
  ss << "[" << file << ":" << function << ":" << line << "]";

  char msgbuffer[2048];
  va_list ap;
  va_start(ap,format);
  vsprintf(msgbuffer,format,ap);
  va_end(ap);
  ss << msgbuffer;
  Write(ss);
}
void Logger::ListenerCallback(const jnx_uint8 *payload, jnx_size br, int c) {

  char *p = strdup((char*)payload);
  for(auto appender : _configuration.GetAppenders()) {
    stringstream ss;
    ss << p;
    appender->Emit(ss);
  }
  free(p);
}
void Logger::Shutdown(void) {
  b_shutdown = true;
  listener_thread->join();
}
void Logger::MainLoop(void) {

  jnx_ipc_listener *listener = ipc_listener;
  while(b_shutdown != true) {
    if(listener == NULL) {
#if DEBUG
      cout << "Listener is null, avoiding" << endl;
#endif
      return;
    }
    jnx_int rv = poll(listener->ufds,listener->nfds,listener->poll_timeout);
    if (rv == -1) {
      perror("jnx IPC socket poll"); // error occurred in poll()
    } else if (rv == 0) {
      /* Timeout reached */
    }
    jnx_int i, current_size = listener->nfds;
    jnx_int close_conn = 0, compress_array = 0;
    for(i=0;i<current_size;++i) {
      if(listener->ufds[i].revents == 0) {
        continue;
      }
      if(listener->ufds[i].fd == listener->socket->socket) {
        int new_fd = -1;
        do{
          new_fd = accept(listener->socket->socket,NULL,NULL);
          if(new_fd < 0) {
            if(errno != EWOULDBLOCK) {
              JNXFAIL("jnx IPC socket could not accept");
              exit(0);
            }
            break;
          }
          listener->ufds[listener->nfds].fd = new_fd;
          listener->ufds[listener->nfds].events = POLLIN;
          listener->nfds++;
        }while(new_fd != -1);
      }else {
        jnx_size rc = 0;
        close_conn = 0;
        compress_array = 0;
        char buffer[MAXBUFFER];
        bzero(buffer,MAXBUFFER);
        rc = recv(listener->ufds[i].fd,buffer,MAXBUFFER,0);
        if(rc < 0) {
          if(errno != EWOULDBLOCK){
            perror("jnx IPC socket recv() failed");
            close_conn = 1;   
          }
        }
        if(rc == 0) {
          close_conn = 1;
        }
        if(rc > 0) {
          jnx_uint8 *outbuffer = (jnx_uint8*)malloc((rc + 1) * sizeof(jnx_uint8));
          memset(outbuffer,0,rc + 1);
          memcpy(outbuffer,buffer,rc);
          ListenerCallback(outbuffer,rc,listener->ufds[i].fd);
          free(outbuffer);
        }
        if(close_conn) {
          close(listener->ufds[i].fd);
          listener->ufds[i].fd = -1;
          compress_array = 1;
        }
        if(compress_array) {
          compress_array = 0;
          jnx_int j;
          for(j=i;j<listener->nfds;++j) {
            if(j+1 < listener->nfds) {
              listener->ufds[j] = listener->ufds[j+1];
            } 
          }
          listener->nfds--;
        }
      }
    }
  }
}
