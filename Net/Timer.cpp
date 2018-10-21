//
// Created by wj on 18-10-12.
//

#include "Timer.h"
#include <unistd.h>
Timer::Timer(Eventloop *loop,const TimerCallback &cb, itimerspec itimerspec__,int NumofTimes__):
timerCallback_(cb),
itimerspec_(itimerspec__)
{
    timeFd=timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK);
    if(timeFd==-1)
    {
        std::cout<<"timeFd"<<timeFd<<std::endl;
        return ;
    }
    //添加到队列中，防止对象被析构了，无法调用回调函数

    if(itimerspec_.it_interval.tv_sec==0&&itimerspec_.it_interval.tv_nsec==0)
    {
        NumofTimes=1;
    }
    else
    {
        NumofTimes=NumofTimes__;
    }
    index_=0;

    int ret=timerfd_settime(timeFd,0,&itimerspec_,0);
    if(ret==-1)
    {
        std::cout<<"timeFd_eero"<<ret<<std::endl;
        return ;
    }
    Channel channel(loop,timeFd);

    channel_=std::make_shared<Channel>(channel);
    channel_->setreadCallbck(std::bind(&Timer::readcallback,this,std::placeholders::_1));

    TimeQueue * timeQueue=TimeQueue::getTimeQueue();
    timeQueue->addTimer(this);
    start=true;
    //开启监听
    channel_->enableReading();

}
void Timer::readcallback(int x)
{
    int64_t i=0;

    read(timeFd,&i, sizeof(i));
    index_++;
    timerCallback_();
    if(index_==NumofTimes)
    {

        stop();
    }
}

void Timer::stop()
{
    channel_->remove();
    itimerspec TimerSpec={0};
    int ret=timerfd_settime(timeFd,0,&TimerSpec,0);
    ::close(timeFd);
    TimeQueue * timeQueue=TimeQueue::getTimeQueue();
    timeQueue->deleteTimer(this);
}

int Timer::get_fd()
{
    return timeFd;
}