/*********************************************************************************
 *     File Name           :     src/logger/configuration.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:15]
 *     Last Modified       :     [2016-01-25 08:25]
 *     Description         :
 **********************************************************************************/

#ifndef __CONFIGURATION_HPP__
#define __CONFIGURATION_HPP__
#include "baseappender.hpp"
#include <initializer_list>
#include <list>

using namespace jnxlogcpp;
using namespace std;

namespace jnxlogcpp
{
  class Configuration
  {
    list<BaseAppender*> _appenders;
    private:
    void AddAppender(BaseAppender* appender);
    public:
    Configuration();
    
    Configuration(initializer_list<BaseAppender*> appender_list);
    
    ~Configuration();
    
    list<BaseAppender*> GetAppenders();
    
    string IpcSocketPath;

    int MaxConnections;
  };
};
#endif
