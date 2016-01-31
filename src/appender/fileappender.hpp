/*********************************************************************************
 *     File Name           :     src/appender/fileappender.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:33]
 *     Last Modified       :     [2016-01-29 17:46]
 *     Description         :
 **********************************************************************************/

#ifndef __FILEAPPENDER_HPP__
#define __FILEAPPENDER_HPP__
#include "baseappender.hpp"
#include <mutex>
using namespace jnxlogcpp;
using namespace std;

namespace jnxlogcpp
{
  class FileAppender : public BaseAppender
  {
    public:

      FileAppender(string logpath);

      ~FileAppender();

      virtual void Emit(const stringstream& string);

    private:

      mutex *locker;

      string _logPath; 
  };
};
#endif
