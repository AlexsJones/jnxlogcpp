/*********************************************************************************
 *     File Name           :     src/logger/logger.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-22 15:35]
 *     Description         :
 **********************************************************************************/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include "configuration.hpp"
#include "iappender.hpp"

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
      Configuration _configuration;

      const string EnumToString(LoggerState state);
      
      const string CurrentDateTime();
    public:
      Logger();

      Logger(Configuration config);

      ~Logger();

      void Write(const stringstream& ss);

      void Write(LoggerState state, const char *file, 
          const char *function, int line, string s);
  };
};


#define JNXLOGCPP_INIT(configuration)\
  static jnxlogcpp::Logger logger(configuration);

#define JNXLOG_INFO(val)\
  logger.Write(INFO,__FILE__,__FUNCTION__,__LINE__,val)
#define JNXLOG_DEBUG(val)\
  logger.Write(DEBUG,__FILE__,__FUNCTION__,__LINE__,val)
#define JNXLOG_WARN(val)\
  logger.Write(WARN,__FILE__,__FUNCTION__,__LINE__,val)
#define JNXLOG_ERROR(val)\
  logger.Write(ERROR,__FILE__,__FUNCTION__,__LINE__,val)

#endif
