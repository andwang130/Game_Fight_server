#include <iostream>
#include "Net/TcpServer.h"
#include "Net/Tcpcoonetion.h"
#include <assert.h>
#include "commds.h"
#include "intermediary.h"
#include "config.h"
#include "Model/DataBase.h"
using namespace std;
using namespace ZL;
using namespace ZL::Net;
class test
{
public:
    test(Eventloop *loop,inetAddress &address,std::string name):tcpServer(new TcpServer(loop,address,name))
    {
        tcpServer->set_MessageCallback(std::bind(&test::on_meassgcallback,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3));
        tcpServer->set_ConnectionCallback(std::bind(&test::on_cooncallback,this,std::placeholders::_1));
        tcpServer->set_ThreadInitCallback(std::bind(&test::on_theradinback,this,std::placeholders::_1));
        tcpServer->set_removeCallback_(std::bind(&test::on_removeCallback,this,std::placeholders::_1));
    }
    void start()
    {
        tcpServer->set_threadnumber(4);
        tcpServer->start();
    }

private:

    //断开连接回调函数
    void on_removeCallback(const TcpcoontionPrt &coon)
    {

        std::cout<<coon->get_name()<<"下线了"<<std::endl;
    }
    //建立连接回调函数
    void on_cooncallback(const TcpcoontionPrt &coon)
    {

    }
    //收到消息回调函数
    void on_meassgcallback(const TcpcoontionPrt &coon,Buffer*buffer,int m)
    {
        protocol_ aProtocol;
        if(buffer->readableBytes()>=13)
        {
            int8_t types=buffer->readInt8();
            int32_t len=buffer->readInt32();
            aProtocol.model=buffer->readInt16();
            aProtocol.model2=buffer->readInt16();
            aProtocol.coomd=buffer->readInt32();
            cout<<"body长度"<<len<<endl;
            cout<<"缓存区长度"<<buffer->readableBytes()<<endl;
            if(buffer->readableBytes()>=len)
            {

                aProtocol.data=buffer->retrieveAsString(len);
                buffer->shrink(0);
                intermeadiary(coon,aProtocol);
            }
        }


    }
    //触发可写事件的回调函数
    void on_writecallback(const TcpcoontionPrt &coon)
    {
        cout<<coon->get_name()<<endl;

    }
    //线程启动回调函数
    void on_theradinback(const Eventloop *loop)
    {

    }
    std::shared_ptr<TcpServer> tcpServer;
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    inetAddress address("0.0.0.0",8081);
    Eventloop loop;
    test new_test(&loop,address,"Figth_server");
    new_test.start();

    return 0;
}