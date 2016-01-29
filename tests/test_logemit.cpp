/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-29 11:57]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "ioappender.hpp"
#include "fileappender.hpp"
#include "configuration.hpp"
#include "logger.hpp"
#include <memory>
using namespace std;

Configuration c( { make_shared<IOAppender>(), 
    make_shared<FileAppender>("temp.log") });
Logger l(c);
void test_log_emit_sync()

{

  cout << "Starting write..." << endl;
  for(int x = 0; x < 100; ++x) {
    l.Write(INFO,__FILE__,__FUNCTION__,__LINE__,"Count %d\n",x);
  }

}
void test_log_emit_async() {

  for(int x = 0; x < 10; ++x) {
    new thread(test_log_emit_sync);
  }
}

int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;
  test_log_emit_sync();

  test_log_emit_async();
  return 0;
}
