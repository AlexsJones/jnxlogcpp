/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-24 20:52]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "ioappender.hpp"
#include "configuration.hpp"
#include "logger.hpp"
#include <chrono>
#include <thread>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;


void test_log_emit_sync()
{
  IOAppender appender;

  Configuration c( { &appender } );

  Logger l(c);
  auto start = Clock::now();
  for(int x = 0; x < 10; ++x) {
    l.Write(INFO,__FILE__,__FUNCTION__,__LINE__,"Count %d",x);
  }
  auto update = Clock::now();
  std::cout << "Emit took: " 
    << std::chrono::duration_cast<std::chrono::nanoseconds>(update - start).count()
    << " nanoseconds" << std::endl;
}
int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;
  test_log_emit_sync();

  return 0;
}
