//
// Created by wj on 18-10-12.
//

#ifndef NET__TIMEQUEUE_H
#define NET__TIMEQUEUE_H
#include <sys/epoll.h>
#include <map>
#include <memory>
#include <mutex>
#include <vector>
#include <thread>
//定时任务队列
class Timer;
typedef std::shared_ptr<Timer> timerPrt;
typedef std::map<int,Timer *> timermMap;
class TimeQueue {
public:
    static TimeQueue * getTimeQueue();
    ~TimeQueue();
    void addTimer(Timer * timer);
    void deleteTimer(Timer * timer);
private:
    std::mutex mutex_;
    TimeQueue();
    static TimeQueue * timeQueue_;

    timermMap timermMap_;
    std::vector<struct epoll_event> epoolEvents;
};


#endif //IMEQUES_TIMEQUEUE_H
