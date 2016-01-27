/*********************************************************************************
 *     File Name           :     /home/anon/Code/jnxlogcpp/src/appender/baseappender.cpp
 *     Created By          :     anon
 *     Creation Date       :     [2016-01-15 08:15]
 *     Last Modified       :     [2016-01-27 09:01]
 *     Description         :
 **********************************************************************************/
#include "baseappender.hpp"

using namespace jnxlogcpp;

BaseAppender::BaseAppender(string name): Name(name)
{

}

BaseAppender::~BaseAppender(void) 
{

}
void BaseAppender::Emit(const stringstream& s)
{

}
void BaseAppender::AddAppenderInfo(const AppenderInfo appender) {

}
