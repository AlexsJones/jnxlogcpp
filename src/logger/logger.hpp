/*********************************************************************************
 *     File Name           :     src/logger/logger.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-14 18:35]
 *     Description         :      
 **********************************************************************************/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include "configuration.hpp"
namespace jnxlogcpp{
 class Logger {

    public:
      Logger();

      Logger(const Configuration &config);

      ~Logger();
  };
};
#endif
