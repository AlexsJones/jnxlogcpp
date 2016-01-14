/*********************************************************************************
 *     File Name           :     src/appender/fileappender.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:33]
 *     Last Modified       :     [2016-01-14 19:53]
 *     Description         :      
 **********************************************************************************/

#ifndef __FILEAPPENDER_HPP__
#define __FILEAPPENDER_HPP__
#include "iappender.hpp"

using namespace jnxlogcpp;

namespace jnxlogcpp {
  class FileAppender : public IAppender {
    public:
      FileAppender();
      virtual void Emit(const stringstream &string);
  };
};
#endif
