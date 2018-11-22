#ifndef IPUSHCALLBACK_H
#define IPUSHCALLBACK_H

#include <QPushButton>

//Courtesy of http://newty.de/jakubik/callback.pdf

class IPushCallBack
{
public:
    virtual  ~IPushCallBack() {}
    virtual void notifyButtonPushed(QPushButton *b) = 0;
};

#endif // IPUSHCALLBACK_H
