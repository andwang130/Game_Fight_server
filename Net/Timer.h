//
// Created by wj on 18-10-12.
//

#ifndef NET_TIMER_H
#define NET_TIMER_H
#include <iostream>
#include <functional>
#include <sys/timerfd.h>
#include <memory>
#include "Channel.h"
#include "TimeQueue.h"
using namespace ZL::Net;
typedef  std::function<void()> TimerCallback;
class Timer
{
public:
    Timer(Eventloop *loop,const TimerCallback &cb, itimerspec itimerspec__,int NumofTimes__);
    void stop();
    int get_fd();
    struct itimerspec itimerspec_;
    int NumofTimes;
    int index_;
    bool start;
private:

        void readcallback(int x);
        std::shared_ptr<Channel> channel_;
        int timeFd;
        TimerCallback timerCallback_;
};


#endif //_TIMER_H
