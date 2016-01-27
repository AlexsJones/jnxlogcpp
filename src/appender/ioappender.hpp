#ifndef IOAPPENDER_H
#define IOAPPENDER_H
#include "baseappender.hpp"

class IOAppender : public BaseAppender
{
  public:
    IOAppender();

    ~IOAppender();

    virtual void Emit(const stringstream& string);

    virtual void AddAppenderInfo(const AppenderInfo appender);
  private:
    AppenderInfo _appenderInfo;
};

#endif // IOAPPENDER_H
