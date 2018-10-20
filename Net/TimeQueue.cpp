//
// Created by wj on 18-10-12.
//

#include "TimeQueue.h"
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
TimeQueue * TimeQueue::timeQueue_= nullptr;
TimeQueue::TimeQueue()
{


}
TimeQueue::~TimeQueue()
{

}
void TimeQueue::addTimer(const timerPrt &timer)
{

    {
        std::lock_guard<std::mutex> lk(mutex_);
        timermMap_[timer->get_fd()]=timer;
    }





}

void TimeQueue::deleteTimer(const timerPrt &timer)
{
    {
        std::lock_guard<std::mutex> lk(mutex_);
        timermMap_.erase(timer->get_fd());
    }



}


TimeQueue * TimeQueue::getTimeQueue()
{
    if(timeQueue_== nullptr)
    {
        timeQueue_=new TimeQueue();
        return timeQueue_;
    }
    else
    {
        return  timeQueue_;
    }
}

