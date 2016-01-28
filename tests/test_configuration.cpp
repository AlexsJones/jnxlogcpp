/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-28 08:54]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "configuration.hpp"
#include "fileappender.hpp"
#include <memory>
using namespace std;
using namespace jnxlogcpp;

void test_create_configuration()
{

  auto f = make_shared<FileAppender>("temp.log");

  Configuration c( { f } );

  for(auto appender : c.GetAppenders()) {
    assert(appender->Name == "FileAppender");
  }
}

int main(int argc, char** argv)
{
  cout << "Running " << argv[0] << endl;

  test_create_configuration();

  return 0;
}
