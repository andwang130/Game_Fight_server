//
// Created by wj_de on 18-10-21.
//

#ifndef FIGHTSERVER_TCPCLIENT_H
#define FIGHTSERVER_TCPCLIENT_H

#include "Channel.h"
#include "Tcpcoonetion.h"
#include "Callbacks.h"
#include "Socket.h"
using namespace ZL::Net;
class Tcpclient {

public:
    Tcpclient(Eventloop *loop,char *ip,int port,std::string name);
    void start();

    void send(const std::string &message);
    void set_MessageCallback(const MessageCallback &cb);


    void set_WriteCompleteCallback(const WriteCompleteCallback &cb );

    void set_ConnectionCallback(const ConnectionCallback &cb);

    void set_ThreadInitCallback(const ThreadInitCallback &cb);


    void set_removeCallback_(const removeCallback &cb);
    //Acceptor接到新的连接调用的函数
    //CloseCallback调用

private:

    void clientwriteCompleteCallback(const TcpcoontionPrt & tcpcoontionPrt);
    void clientconnectionCallback(const TcpcoontionPrt & tcpcoontionPrt);
    void clientremoveCallback(const TcpcoontionPrt & tcpcoontionPrt);
    void clientMessageCallback(const TcpcoontionPrt &tcpcoontionPrt, Buffer *buffer, int tiems);
    Eventloop *loop_;
    std::string name_;
    MessageCallback messageCallback_;
    CloseCallback closeCallback_;
    WriteCompleteCallback writeCompleteCallback_;
    ConnectionCallback connectionCallback_;
    ThreadInitCallback threadInitCallback_;
    removeCallback removeCallback_;
    std::shared_ptr<Channel> channel_;
    Socket socket_;
    std::shared_ptr<Tcpcoonetion> prt_coon;
};


#endif //FIGHTSERVER_TCPCLIENT_H
