/*********************************************************************************
 *     File Name           :     src/appender/iappender.hpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-14 18:27]
 *     Last Modified       :     [2016-01-22 14:13]
 *     Description         :
 **********************************************************************************/

#ifndef __IAPPENDER_HPP__
#define __IAPPENDER_HPP__
#include <sstream>

using namespace std;

namespace jnxlogcpp
{
class IAppender
{
public:
    IAppender() {};
    virtual void Emit(const stringstream& s) = 0;
};
};


#endif
