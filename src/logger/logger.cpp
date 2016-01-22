/*********************************************************************************
 *     File Name           :     src/logger/logger.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 17:48]
 *     Last Modified       :     [2016-01-22 18:16]
 *     Description         :
 **********************************************************************************/

#include "logger.hpp"
#include <stdarg.h>
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
const string Logger::EnumToString(LoggerState state) {

  switch(state) {
    case INFO:
      return string("INFO");
      break;
    case DEBUG:
      return string("DEBUG");
      break;
    case WARN:
      return string("WARN");
      break;
    case ERROR:
      return string("ERROR");
      break;
  }
}
const string Logger::CurrentDateTime() {
  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

  return buf;
}

void Logger::Write(const stringstream& ss) {

  for(auto *appender : _configuration.GetAppenders()) {
    appender->Emit(ss);
  }
}
void Logger::Write(LoggerState state, const char *file, 
    const char *function, int line, const char *format, ...) {
  stringstream ss;
  ss << "[" << EnumToString(state) << "]";
  ss << "[" << CurrentDateTime() << "]";
  ss << "[" << file << ":" << function << ":" << line << "]";

  char msgbuffer[2048];
  va_list ap;
  va_start(ap,format);
  vsprintf(msgbuffer,format,ap);
  va_end(ap);
  
  ss << msgbuffer;

  Write(ss);
}
