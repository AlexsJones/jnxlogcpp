/*********************************************************************************
 *     File Name           :     src/logger/logger.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-25 09:04]
 *     Description         :
 **********************************************************************************/

#include "logger.hpp"
#include <stdarg.h>
#include <iostream>
#include <jnxc_headers/jnxtypes.h>
#include <jnxc_headers/jnxfile.h>
using namespace std;
using namespace jnxlogcpp;

Logger::Logger(Configuration config):_configuration(config)
{

  jnx_char *socketPath = (jnx_char*)_configuration.IpcSocketPath.c_str();

  if(jnx_file_exists(socketPath)) {
   jnx_file_recursive_delete(socketPath,1); 
  }

  jnx_ipc_socket *socket = jnx_socket_ipc_create(socketPath);

  ipc_listener = jnx_socket_ipc_listener_create(socket,100);
}
Logger::~Logger(void)
{
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

  for(auto *appender : _configuration.GetAppenders()) {
    appender->Emit(ss);
  }
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
