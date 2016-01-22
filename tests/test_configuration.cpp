/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-22 14:20]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "configuration.hpp"
#include "fileappender.hpp"
using namespace std;
using namespace jnxlogcpp;

void test_create_configuration()
{

  FileAppender f;
  Configuration c( { &f } );

  for(auto *appender : c.GetAppenders()) {
    assert(appender->Name == "FileAppender");
  }
}

int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;

  test_create_configuration();

  return 0;
}
