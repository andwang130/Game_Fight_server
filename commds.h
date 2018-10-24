//
// Created by wj on 18-10-5.
//

#include <sys/user.h>

#ifndef LOGINSERVER_COMMDS_H
#define LOGINSERVER_COMMDS_H



#include <iostream>
#include "Net/Tcpcoonetion.h"

typedef ZL::Net::TcpcoontionPrt CoonPrt;
struct protocol_
{
    int8_t fin;
    int16_t model;
    int16_t model2;
    int32_t coomd;
    std::string data;
    std::string  get_byte()
    {


        int len=13+data.size();
        std::string new_string;
        new_string.resize(len);
        char buf[len];
        memset(buf,0,len);
        int index=0;
        memcpy(&*new_string.begin(),&fin, sizeof(fin));

        index+= sizeof(fin);
        //本机字节序转换网络字节序
        int bodySize=htobe32(data.size());
        memcpy(&*new_string.begin()+index,&bodySize, sizeof(bodySize));
        index+= sizeof(len);
        model=htobe16(model);
        memcpy(&*new_string.begin()+index,&model, sizeof(model));
        index+= sizeof(model);

        model2=htobe16(model2);
        memcpy(&*new_string.begin()+index,&model2, sizeof(model2));
        index+= sizeof(model2);


        coomd=htobe32(coomd);
        memcpy(&*new_string.begin()+index,&coomd, sizeof(coomd));
        index+= sizeof(coomd);
        memcpy(&*new_string.begin()+index,&*data.begin(),data.size());

        return std::move(new_string);

    }
};


//聊天模块
namespace Login_to_Fight
{
    const short level1=10;
    namespace send
    {
        const short level2=1;
        namespace coomd
        {

            const int Fight_init=1; //发送给所有任

        }

    }
}
namespace play_init
{
    const short level1=11;
    namespace send
    {
        const short level2=1;
        namespace coomd
        {
            const int to_fight=1; //用户第一次进入战斗服务器，创建一个该连接对应的ID类
            const int to_fight_code=2;  //ID类建立后的返回码

            const int get_fight_info=3; //客户端请求获得战场信息
        }const int get_info_code=4; //客户端请求获得战场信息

    }
}


#endif //LOGINSERVER_COMMDS_H