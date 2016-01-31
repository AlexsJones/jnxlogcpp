/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-31 21:38]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "ioappender.hpp"
#include "fileappender.hpp"
#include "configuration.hpp"
#include "logger.hpp"
#include <vector>
#include <memory>
#include <thread>
using namespace std;

Configuration c( { make_shared<IOAppender>(), 
    make_shared<FileAppender>("temp.log") });
Logger l(c);
void test_log_emit_sync()

{
  for(int x = 10; 0 < x; --x) {
    stringstream ss;
    ss << "Thread ";
    ss << this_thread::get_id();
    ss << " says ";
    ss << x;
    ss << "\n";
    l.Write(INFO,__FILE__,__FUNCTION__,__LINE__,ss.str().c_str());

    cout << ss.str();
  }

}
void test_log_emit_async() {

  vector<thread> thrs;
  
  for(int x = 0; x < 10; ++x) {
    thrs.push_back(thread(test_log_emit_sync));
  }
  for(auto& th : thrs) {
    th.join();
  }
}

int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;
  test_log_emit_sync();

  test_log_emit_async();
  return 0;
}
