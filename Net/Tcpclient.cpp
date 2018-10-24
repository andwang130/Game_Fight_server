#include "Tcpclient.h"

Tcpclient::Tcpclient(Eventloop *loop,char *ip, int port,std::string name):socket_(ip,port)
        ,loop_(loop)
        ,name_(name)
{

}

void Tcpclient::start()
{
    socket_.Connect();
    prt_coon=TcpcoontionPrt(new Tcpcoonetion(loop_,socket_.get_fd(),name_));
    prt_coon->set_messageCallback(std::bind(&Tcpclient::clientMessageCallback,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
    prt_coon->set_writecallback(std::bind(&Tcpclient::clientwriteCompleteCallback,this,std::placeholders::_1));
    prt_coon->set_closecallback(std::bind(&Tcpclient::clientremoveCallback,this,std::placeholders::_1));
    prt_coon->set_coonCallback(std::bind(&Tcpclient::clientconnectionCallback,this,std::placeholders::_1));
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
void Tcpclient::clientMessageCallback(const TcpcoontionPrt &tcpcoontionPrt, Buffer *buffer, int tiems)
{
    if(messageCallback_)
    {
        messageCallback_(tcpcoontionPrt,buffer,tiems);
    }
}
void Tcpclient::clientwriteCompleteCallback(const TcpcoontionPrt & tcpcoontionPrt)
{
    if(writeCompleteCallback_)
    {
        writeCompleteCallback_(tcpcoontionPrt);
    }
}
void Tcpclient::clientconnectionCallback(const TcpcoontionPrt & tcpcoontionPrt)
{
    if(connectionCallback_)
    {
        connectionCallback_(tcpcoontionPrt);
    }

}

void Tcpclient::clientremoveCallback(const TcpcoontionPrt & tcpcoontionPrt)
{
    if(removeCallback_)
    {
        removeCallback_(tcpcoontionPrt);
    }
}