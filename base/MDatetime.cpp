//
// Created by wj_de on 18-9-1.
//

#include "MDatetime.h"
using namespace Datetime;
std::string Datetime::get_timeGMT()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%a, %d %b %Y %H:%M:%S GMT",localtime(&timep) );
    return tmp;
}

std::string Datetime::get_dateTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );
    return tmp;
}
std::string Datetime::get_date()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d",localtime(&timep) );
    return tmp;
}
int Datetime::get_time()
{
    time_t timep;
    time (&timep);
    return timep;
}
