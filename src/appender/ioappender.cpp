#include "ioappender.hpp"
#include <iostream>

using namespace std;

IOAppender::IOAppender(): BaseAppender("IOappender")
{

}
IOAppender::~IOAppender()
{

}
void IOAppender::Emit(const stringstream& s)
{
  cout << s.str() << endl;
}
void IOAppender::AddAppenderInfo(const AppenderInfo appender) {

  _appenderInfo = appender;
}
