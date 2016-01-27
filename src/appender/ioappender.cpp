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
