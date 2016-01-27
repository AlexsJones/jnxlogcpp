/*********************************************************************************
 *     File Name           :     src/logger/logger.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-27 17:58]
 *     Description         :
 **********************************************************************************/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include "configuration.hpp"
#include "iappender.hpp"
#include <jnxc_headers/jnx_ipc_socket.h>
#include <thread>

using namespace jnxlogcpp;

namespace jnxlogcpp
{

  enum LoggerState {
    INFO,
    DEBUG,
    WARN,
    ERROR,
    HALT
  };

  class Logger
  {

    private:

      thread *listener_thread = NULL;

      volatile bool b_shutdown;

      volatile bool b_is_running;

      jnx_ipc_socket *ipc_writer;

      jnx_ipc_listener *ipc_listener;

      Configuration _configuration;

      const string EnumToString(LoggerState state);

      const string CurrentDateTime(void);

      void Write(const stringstream& ss);
    public:
      Logger(Configuration config);

      ~Logger();

      void Write(LoggerState state, const char *file, 
          const char *function, int line, const char *format, ...);

      void Write(LoggerState state, const char *file, 
          const char *function, int line, const char *format,const char* buff);

      void ListenerCallback(const jnx_uint8 *payload, jnx_size br, int c);

      void MainLoop(void);

      void Shutdown(void);

      void StartAsyncListener() {
        listener_thread =  new thread([this] { this->MainLoop(); });
      };
  };
};
#define JNXLOGCPP_INIT(configuration)\
  static jnxlogcpp::Logger logger(configuration);\

#define JNXLOGCPP_FILEAPPENDER(X)\
  new FileAppender(X)

#define JNXLOGCPP_IOAPPENDER\
  new IOAppender()

#define JNXLOGCPP_CONFIGURATION_BEGIN\
  Configuration c({

#define JNXLOGCPP_CONFIGURATION_END\
      });
#define JNXLOG_INFO(FORMAT, ...)\
  logger.Write(INFO,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_DEBUG(FORMAT, ...)\
  logger.Write(DEBUG,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_WARN(FORMAT, ...)\
  logger.Write(WARN,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_ERROR(FORMAT, ...)\
  logger.Write(ERROR,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_HALT(FORMAT, ...)\
  logger.Write(HALT,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);\
  exit(1);
#define JNXLOGCPP_HEADERS 
#include <jnxlogcpp_headers/fileappender.hpp>
#include <jnxlogcpp_headers/ioappender.hpp>
#include <iostream>
#endif
