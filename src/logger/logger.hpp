/*********************************************************************************
 *     File Name           :     src/logger/logger.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-25 09:02]
 *     Description         :
 **********************************************************************************/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include "configuration.hpp"
#include "iappender.hpp"
#include <jnxc_headers/jnx_ipc_socket.h>

using namespace jnxlogcpp;

namespace jnxlogcpp
{

  enum LoggerState {
    INFO,
    DEBUG,
    WARN,
    ERROR
  };

  class Logger
  {

    private:
    
      jnx_ipc_listener *ipc_listener;
      
      Configuration _configuration;

      const string EnumToString(LoggerState state);
      
      const string CurrentDateTime();
      
      void Write(const stringstream& ss);
    public:
      Logger(Configuration config);

      ~Logger();

      void Write(LoggerState state, const char *file, 
          const char *function, int line, const char *format, ...);
      
      void Write(LoggerState state, const char *file, 
          const char *function, int line, const char *format,const char* buff);
  };
};
#define JNXLOGCPP_INIT(configuration)\
  static jnxlogcpp::Logger logger(configuration);

#define JNXLOG_INFO(FORMAT, ...)\
  logger.Write(INFO,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_DEBUG(FORMAT, ...)\
  logger.Write(DEBUG,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_WARN(FORMAT, ...)\
  logger.Write(WARN,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);
#define JNXLOG_ERROR(FORMAT, ...)\
  logger.Write(ERROR,__FILE__,__FUNCTION__,__LINE__,FORMAT, ##__VA_ARGS__);

#endif
