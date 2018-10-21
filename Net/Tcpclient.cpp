//
// Created by wj_de on 18-10-21.
//

#include "Tcpclient.h"

Tcpclient::Tcpclient(Eventloop *loop,char *ip, int port,std::string name):socket_(ip,port)
,loop_(loop),
name_(name)
{
    socket_.Connect();
}

void Tcpclient::start()
{
    prt_coon=TcpcoontionPrt(new Tcpcoonetion(loop_,socket_.get_fd(),name_));
    prt_coon->set_messageCallback(messageCallback_);
    prt_coon->set_writecallback(writeCompleteCallback_);
    prt_coon->set_closecallback(removeCallback_);
    prt_coon->set_coonCallback(connectionCallback_);
    prt_coon->connectEstablished();


}
void Tcpclient::send(const std::string &message)
{
    prt_coon->sendloop(message);
}
void Tcpclient::set_MessageCallback(const MessageCallback &cb)
{
    messageCallback_=cb;
}

//void set_CloseCallback(const CloseCallback &cb);

void Tcpclient::set_WriteCompleteCallback(const WriteCompleteCallback &cb )
{
    writeCompleteCallback_=cb;
}

void Tcpclient::set_ConnectionCallback(const ConnectionCallback &cb)
{
    connectionCallback_=cb;
}

void Tcpclient::set_ThreadInitCallback(const ThreadInitCallback &cb)
{
    threadInitCallback_=cb;
}
void Tcpclient::set_removeCallback_(const removeCallback &cb)
{
    removeCallback_=cb;
}
