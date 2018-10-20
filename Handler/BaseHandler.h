//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_BASEHANDLER_H
#define LOGINSERVER_BASEHANDLER_H

#include "../commds.h"
#include "../Net/Tcpcoonetion.h"
#include "../Model/DataBase.h"
#include "../config.h"
class BaseHandler {

public:
    BaseHandler(const CoonPrt coonPrt,protocol_ &aProtocol);

protected:

    const CoonPrt coonPrt_;
    protocol_ aProtocol_;
    void tosend(int mode1,int mode2,int coomd,std::string &data);
    void tosend(int mode1,int mode2,int coomd,std::string &data,const CoonPrt &coonPrt);
    void protoc(int mode1, int mode2, int coomd, std::string &data,std::string &buf);
};


#endif //LOGINSERVER_BASEHANDLER_H
