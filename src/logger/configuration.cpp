/*********************************************************************************
*     File Name           :     /home/anon/Code/jnxlogcpp/src/logger/configuration.cpp
*     Created By          :     anon
*     Creation Date       :     [2016-01-14 18:15]
*     Last Modified       :     [2016-01-15 08:30]
*     Description         :      
**********************************************************************************/

#include "configuration.hpp"
#include <iostream>

using namespace jnxlogcpp;

Configuration::Configuration( initializer_list<BaseAppender> appender_list) { 

#ifndef RELEASE
  cout << "initializer_list length:" << appender_list.size() << endl;
   initializer_list<BaseAppender>::iterator it;
   
   for(it = appender_list.begin(); it != appender_list.end(); ++it) {
    cout << "Adding: " << (*it).Name << endl; 
   }
  
#endif

}
Configuration::Configuration() {

}
Configuration::~Configuration() {

}
void Configuration::AddAppender(const BaseAppender &appender) {

}
