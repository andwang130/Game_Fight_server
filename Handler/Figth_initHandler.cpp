//
// Created by wj_de on 18-10-22.
//

#include "Figth_initHandler.h"
#include "../protobuf_maegss/to_Fight.pb.h"
Figth_initHandler::Figth_initHandler(const CoonPrt &coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    port=8081;
    ip="127.0.0.1";

    switch(aProtocol_.coomd)
    {
        case Login_to_Fight::send::coomd::Fight_init:
        {
            init_fight();
            break;
        }
    }


}
void Figth_initHandler::init_fight()
{
    to_Figth::Figth_init figth_init;
    if(!figth_init.ParseFromString(aProtocol_.data))
    { return;}

    to_Figth::rq_Fight_init rq_fight_init;
    rq_fight_init.set_port(port);
    rq_fight_init.set_ip(ip);
    rq_fight_init.set_roomid(figth_init.roomid());

    for(int i=0;i<figth_init.plays_size();i++)
    {   to_Figth::Fight_play *fight_play=rq_fight_init.add_fight_plays();
        to_Figth::play play_=figth_init.plays(i);
        fight_play->set_index(play_.index());
        fight_play->set_play_id((play_.index()));
    }

    std::string buf=rq_fight_init.SerializeAsString();
    tosend(10,1,1,buf);
}