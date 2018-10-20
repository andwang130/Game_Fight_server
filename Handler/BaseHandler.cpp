//
// Created by wj on 18-10-5.
//

#include "BaseHandler.h"
BaseHandler::BaseHandler(const CoonPrt coonPrt,protocol_ &aProtocol):
coonPrt_(coonPrt),
aProtocol_(aProtocol)
{

}

void BaseHandler::tosend(int mode1, int mode2, int coomd, std::string &data)
{

    std::string buf;
    protoc(mode1,mode1,coomd,data,buf);
    coonPrt_->sendloop(buf);
}
void BaseHandler::tosend(int mode1, int mode2, int coomd, std::string &data,const CoonPrt &coonPrt)
{

    std::string buf;
    protoc(mode1,mode1,coomd,data,buf);
    coonPrt->sendloop(buf);
}
void  BaseHandler::protoc(int mode1, int mode2, int coomd, std::string &data,std::string &buf)
{
    protocol_ newprotocol;
    newprotocol.model=mode1;
    newprotocol.model2=mode2;
    newprotocol.coomd=coomd;
    newprotocol.fin=0;
    newprotocol.data=data;
    buf=newprotocol.get_byte();
}
