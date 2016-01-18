/*********************************************************************************
 *     File Name           :     src/appender/fileappender.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:33]
 *     Last Modified       :     [2016-01-15 08:20]
 *     Description         :
 **********************************************************************************/

#ifndef __FILEAPPENDER_HPP__
#define __FILEAPPENDER_HPP__
#include "baseappender.hpp"

using namespace jnxlogcpp;

namespace jnxlogcpp
{
class FileAppender : public BaseAppender
{
public:
    FileAppender();
    ~FileAppender();
    virtual void Emit(const stringstream& string);
};
};
#endif
