#include "ioappender.hpp"
#include <iostream>

using namespace std;

IOAppender::IOAppender(): BaseAppender("IOappender")
{

}
IOAppender::~IOAppender()
{

}
void IOAppender::Emit(const stringstream& string)
{
    cout << string << endl;
}
