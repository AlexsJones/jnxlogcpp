/*********************************************************************************
*     File Name           :     src/logger/logger.cpp
*     Created By          :     anon
*     Creation Date       :     [2016-01-14 17:48]
*     Last Modified       :     [2016-01-14 18:19]
*     Description         :
**********************************************************************************/

#include "logger.hpp"
#include <iostream>

using namespace std;
using namespace jnxlogcpp;

Logger::Logger(void)
{

}
Logger::Logger(const Configuration& config): _configuration(config)
{

}
Logger::~Logger(void)
{

};

void Logger::Write(string t)
{
  for(auto appender : _configuration.GetAppenders()) {
    
    
  }
}
