/*********************************************************************************
 *     File Name           :     src/logger/configuration.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:15]
 *     Last Modified       :     [2016-01-28 08:42]
 *     Description         :
 **********************************************************************************/

#ifndef __CONFIGURATION_HPP__
#define __CONFIGURATION_HPP__
#include "baseappender.hpp"
#include <initializer_list>
#include <list>
#include <memory>

using namespace jnxlogcpp;
using namespace std;

namespace jnxlogcpp
{
  class Configuration
  {
    private:

    list<shared_ptr<BaseAppender>> _appenders;

    void SetupAppenders(initializer_list<shared_ptr<BaseAppender>> appender_list);

    void AddAppender(shared_ptr<BaseAppender> appender);
    
    public:
    Configuration();
    
    Configuration(initializer_list<shared_ptr<BaseAppender>> appender_list);
    
    ~Configuration();
    
    string IpcSocketPath;

    int MaxConnections;
    
    list<shared_ptr<BaseAppender>> GetAppenders();
  };
};
#endif
