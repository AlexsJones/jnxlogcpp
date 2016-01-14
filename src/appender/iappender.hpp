/*********************************************************************************
*     File Name           :     src/appender/iappender.hpp
*     Created By          :     anon
*     Creation Date       :     [2016-01-14 18:27]
*     Last Modified       :     [2016-01-14 18:38]
*     Description         :      
**********************************************************************************/

#ifndef __IAPPENDER_HPP__
#define __IAPPENDER_HPP__
#include <sstream>

using namespace std;

class IAppender {

  public:
    virtual void Emit(const stringstream &string) =0;
};



#endif
