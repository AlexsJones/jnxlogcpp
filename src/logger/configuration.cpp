/*********************************************************************************
 *     File Name           :     /home/anon/Code/jnxlogcpp/src/logger/configuration.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:15]
 *     Last Modified       :     [2016-01-28 08:49]
 *     Description         :
 **********************************************************************************/

#include "configuration.hpp"
#include <iostream>
#include <list>

using namespace jnxlogcpp;
using namespace std;

void Configuration::SetupAppenders(initializer_list<shared_ptr<BaseAppender>> appender_list) {
#ifndef RELEASE
  cout << "initializer_list length:" << appender_list.size() << endl;
#endif
  initializer_list<shared_ptr<BaseAppender>>::iterator it;

  for (it = appender_list.begin(); it != appender_list.end(); ++it) {
#ifndef RELEASE
    cout << "Adding: " << (*it)->Name << endl;
#endif

    AddAppender(*it);
  }
}
Configuration::Configuration(initializer_list<shared_ptr<BaseAppender>> appender_list):
  IpcSocketPath(".jnxlogcpp-tmp"),MaxConnections(100) {

    SetupAppenders(appender_list);
  }
Configuration::Configuration():IpcSocketPath(".jnxlogcpp-tmp"),
  MaxConnections(100) {

  }
Configuration::~Configuration()
{
}
void Configuration::AddAppender(shared_ptr<BaseAppender> appender)
{
  _appenders.push_back(appender);
#ifndef RELEASE
  cout << "_appenders length:" << _appenders.size() << endl;
#endif
}
list<shared_ptr<BaseAppender>> Configuration::GetAppenders() {

  return _appenders;
}
