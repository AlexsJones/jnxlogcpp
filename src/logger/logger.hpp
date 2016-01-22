/*********************************************************************************
 *     File Name           :     src/logger/logger.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-22 11:50]
 *     Description         :
 **********************************************************************************/

#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include "configuration.hpp"
#include "iappender.hpp"

using namespace jnxlogcpp;

namespace jnxlogcpp
{
  class Logger
  {

    private:
      Configuration _configuration;
    public:
      Logger();

      Logger(Configuration config);

      ~Logger();

      void Write(string s);
  };
};
#endif
