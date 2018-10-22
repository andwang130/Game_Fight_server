//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_INTERMEDIARY_H
#define LOGINSERVER_INTERMEDIARY_H

#endif //LOGINSERVER_INTERMEDIARY_H
//中间类，根据指令调用handler
#include "commds.h"
#include "Net/Tcpcoonetion.h"
#include "Handler/Figth_initHandler.h"
using namespace ZL;
using namespace ZL::Net;
inline void intermeadiary(const TcpcoontionPrt connprt,protocol_ &aProtocol_)
{
    std::cout<<aProtocol_.data<<std::endl;
    switch (aProtocol_.model)
    {
        case Login_to_Fight::level1:
        {
            Figth_initHandler figth_initHandler(connprt,aProtocol_);
            break;
        }

    }

}