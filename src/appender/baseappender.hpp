/*********************************************************************************
 *     File Name           :     src/appender/baseappender.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-15 08:13]
 *     Last Modified       :     [2016-01-27 14:45]
 *     Description         :
 **********************************************************************************/

#ifndef __BASEAPPENDER_HPP__
#define __BASEAPPENDER_HPP__
#include "iappender.hpp"

using namespace jnxlogcpp;

namespace jnxlogcpp
{
  class BaseAppender : public IAppender
  {
    public:
      BaseAppender(string name);

      ~BaseAppender();

      virtual void Emit(const stringstream& s);

      const string Name;
  };
};
#endif
