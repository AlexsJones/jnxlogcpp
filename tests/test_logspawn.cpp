/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-14 18:22]
 *     Description         :      
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "logger.hpp"
using namespace std;
using namespace jnxlogcpp;

void test_create_logger(){

  Logger l;

  assert(&l != NULL);
}

void test_create_logger_configuration() {

  Configuration c;

  Logger l(c);
}

int main(int argc, char **argv) {
  cout << "Running " << argv[0] << endl;
  test_create_logger();
  return 0;
}
