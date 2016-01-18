/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-14 18:03]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "ioappender.hpp"
#include "configuration.hpp"
#include "logger.hpp"
using namespace std;


void test_log_emit()
{
  IOAppender appender;
  
  Configuration c( { appender } );
  
  Logger l(c);
  
  l.Write("Hello from logger");
}

int main(int argc, char** argv)
{
    cout << "Running " << argv[0] << endl;
    test_log_emit();

    return 0;
}
