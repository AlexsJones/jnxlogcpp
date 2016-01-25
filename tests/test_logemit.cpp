/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-25 19:35]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "ioappender.hpp"
#include "configuration.hpp"
#include "logger.hpp"
using namespace std;

void test_log_emit_sync()
{
  IOAppender appender;

  Configuration c( { &appender } );

  Logger l(c);

  l.StartAsyncListener();

  cout << "Starting write..." << endl;
  for(int x = 0; x < 100; ++x) {
    l.Write(INFO,__FILE__,__FUNCTION__,__LINE__,"Count %d\n",x);
  }

}
int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;
  test_log_emit_sync();

  return 0;
}
