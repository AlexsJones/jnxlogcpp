/*********************************************************************************
 *     File Name           :     src/logger/configuration.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:15]
 *     Last Modified       :     [2016-01-27 11:52]
 *     Description         :
 **********************************************************************************/

#ifndef __CONFIGURATION_HPP__
#define __CONFIGURATION_HPP__
#include "baseappender.hpp"
#include "appenderinfo.hpp"
#include <initializer_list>
#include <list>

using namespace jnxlogcpp;
using namespace std;

namespace jnxlogcpp
{
  class Configuration
  {
    private:

    const AppenderInfo _appenderInfo;

    list<BaseAppender*> _appenders;

    void SetupAppenders(initializer_list<BaseAppender*> appender_list);

    void AddAppender(BaseAppender* appender);
    
    public:
    Configuration();
    
    Configuration(initializer_list<BaseAppender*> appender_list);
    
    Configuration(initializer_list<BaseAppender*> appender_list, AppenderInfo 
        appenderinfo);
    
    ~Configuration();
    
    string IpcSocketPath;

    int MaxConnections;
    
    list<BaseAppender*> GetAppenders();
  };
};
#endif
