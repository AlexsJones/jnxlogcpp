jnxlogcpp
========

A fast multi-appender logger in C++.



##A note on compilers

The new C++11 compilers are a pain to install on `Debian` systems as the GNU library versions often contradict the compiler version. I recommend you ensure you use `g++-4.9` and `clang++3.5` there are also some guides on getting C++11 up and running for linux systems [here](http://unix.stackexchange.com/questions/242876/upgrading-gcc-on-debian-wheezy-to-support-c-11-features). OS/X users are on their own sorry!

##Deps
```
cmake
g++-4.9
clang++-3.5
```

##Example
```
#include <jnxlogcpp_headers/logger.hpp>
//Shorthand for loading in our appender headers
JNXLOGCPP_HEADERS
//Create appenders
static IOAppender o;
//FileAppender is an example of a constructor that takes params
static FileAppender f("temp.log");
//Load these into the configuration list
Configuration c({&o, &f});
//Init the logger and away you go!
//No De-init required
JNXLOGCPP_INIT(c)
  int main(int argc, char **argv){

    for(int x = 0; x < 100; ++x){
      JNXLOG_INFO("Hello from the logger\n");
    }
    return 0;
  }
```
