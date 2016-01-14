/*********************************************************************************
 *     File Name           :     src/logger/configuration.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:15]
 *     Last Modified       :     [2016-01-14 20:40]
 *     Description         :      
 **********************************************************************************/

#ifndef __CONFIGURATION_HPP__
#define __CONFIGURATION_HPP__
#include "iappender.hpp"
#include <initializer_list>

using namespace jnxlogcpp;
using namespace std;

namespace jnxlogcpp {
  class Configuration {

    public:
      Configuration( initializer_list<IAppender> appender_list); 
      Configuration();
      ~Configuration();
      void AddAppender(const IAppender &appender);
  };
};
#endif
