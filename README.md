jnxlogcpp
========

A fast async multi-appender logger in C++ that uses unix interprocess comms.

- Simplicity
- No memory management required.
- Supports system types.
- Asynchronous logging and multi-thread friendly.

##Usage

Once the logger has been initialized (see example) use like so:

`JNXLOG_INF0("Some sort of data with formatting %d %zu\n",1,391);`

##Platforms

Currently tested on `Debian/Ubuntu` both require installed build libraries for clang/gcc.
It should work on OS/X with `brew` for library support.

##Installation

```bash
git clone https://git@github.com/AlexsJones/jnxlogcpp.git
cd jnxlogcpp && cmake . && make && sudo make install
```

###A note on compilers

The new C++11 compilers are a pain to install on `Debian` systems as the GNU library versions often contradict the compiler version. I recommend you ensure you use `g++-4.9` and `clang++3.5` there are also some guides on getting C++11 up and running for linux systems [here](http://unix.stackexchange.com/questions/242876/upgrading-gcc-on-debian-wheezy-to-support-c-11-features). OS/X users are on their own sorry!

###Deps
```
cmake
g++-4.9
clang++-3.5
```

###Example

```cpp
#include <jnxlogcpp_headers/logger.hpp>
JNXLOGCPP_CONFIGURATION_BEGIN
JNXLOGCPP_FILEAPPENDER("temp.log"),
JNXLOGCPP_IOAPPENDER
JNXLOGCPP_CONFIGURATION_END
JNXLOGCPP_INIT(c)

int main(int argc, char **argv){

   for(int x = 0; x < 100; ++x){
      JNXLOG_INFO("Hello from the logger\n");
      JNXLOG_DEBUG("Hello from the logger\n");
      JNXLOG_WARN("Hello from the logger\n");
      JNXLOG_ERROR("Hello from the logger\n");

      //Halts program
      //JNXLOG_HALT("Hello from the logger\n");
    }
    //No De-init required
    return 0;
  }
```
Output for both the temp file and console should be:
```
[INFO][2016-01-27.14:51:41][main.cpp:main:21]Hello from the logger
[DEBUG][2016-01-27.14:51:41][main.cpp:main:21]Hello from the logger
[WARN][2016-01-27.14:51:41][main.cpp:main:21]Hello from the logger
[ERROR][2016-01-27.14:51:41][main.cpp:main:21]Hello from the logger
```

The makefile for this example

```Makefile
all:
    g++-4.9 *.cpp -o main -ljnxlogcpp -std=gnu++11 -lstdc++ -ljnxc -pthread
```

