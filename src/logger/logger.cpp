/*********************************************************************************
 *     File Name           :     src/logger/logger.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-22 11:51]
 *     Description         :
 **********************************************************************************/

#include "logger.hpp"
#include <iostream>

using namespace std;
using namespace jnxlogcpp;

Logger::Logger(void)
{

}
Logger::Logger(Configuration config):_configuration(config)
{

}
Logger::~Logger(void)
{

};
void Logger::Write(string t)
{
  /*  for(auto appender : _configuration->GetAppenders()) {


      }
      */
}
