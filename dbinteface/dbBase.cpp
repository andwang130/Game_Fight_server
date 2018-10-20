//
// Created by wj on 18-10-9.
//

#include "dbBase.h"
dbBase::dbBase()
{
    //从连接池获取一个连接
    coon=mysqlPool->grab();
}
dbBase::~dbBase()
{
    //收回一个连接
    mysqlPool->release(coon);
}