/*********************************************************************************
 *     File Name           :     test/test_example.c
 *     Created By          :     anon
 *     Creation Date       :     [2015-12-17 13:15]
 *     Last Modified       :     [2016-01-22 15:28]
 *     Description         :
 **********************************************************************************/
#include <assert.h>
#include <iostream>
#include "logger.hpp"
#include "ioappender.hpp"
using namespace std;
using namespace jnxlogcpp;


void test_create_logger()
{

    Logger l;

    assert(&l != NULL);
}
void test_create_logger_configuration()
{

    Configuration c;
    Logger l(c);
}

static IOAppender a;
static Configuration c({&a});
JNXLOGCPP_INIT(c);

void test_global_logger() {

  JNXLOG_DEBUG("Global logger");
}
int main(int argc, char** argv)
{
    cout << "Running " << argv[0] << endl;
    test_create_logger();

    test_global_logger();
    return 0;
}
