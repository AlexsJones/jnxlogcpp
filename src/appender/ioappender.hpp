#ifndef IOAPPENDER_H
#define IOAPPENDER_H
#include "baseappender.hpp"

class IOAppender : public BaseAppender
{
public:
    IOAppender();
    ~IOAppender();
    virtual void Emit(const stringstream& string);
};

#endif // IOAPPENDER_H
