//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_CONFIG_H
#define LOGINSERVER_CONFIG_H

#include "dbinteface/mysqlpool.h"
#include "base/MDatetime.h"

static const int port=3306;
static const char *db="Gamedb";
static const char *ip="127.0.0.1";
static const char *user="root";
static const char *pswd="WANGJING123";
static const int max_size=10;



extern mysqlpp::ConnectionPool * mysqlPool;




#endif //LOGINSERVER_CONFIG_H