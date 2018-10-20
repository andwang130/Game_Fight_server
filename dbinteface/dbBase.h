//
// Created by wj on 18-10-9.
//

#ifndef LOGINSERVER_DBBASE_H
#define LOGINSERVER_DBBASE_H

#include "../config.h"
class dbBase {
public:
    dbBase();
    ~dbBase();
protected:
    mysqlpp::Connection *coon;

};


#endif //LOGINSERVER_DBBASE_H
