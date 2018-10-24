//
// Created by wj_de on 18-10-23.
//

#ifndef FIGHTSERVER_PLAYININTHANDELR_H
#define FIGHTSERVER_PLAYININTHANDELR_H

#include "BaseHandler.h"
#include "../protobuf_maegss/to_Fight.pb.h"
class PlayinintHandelr: public BaseHandler {
public:
    PlayinintHandelr(const CoonPrt &coonPrt,protocol_ &aProtoco);
    //用户进入战斗服务器
    void playtoFight();
    //客户端获得战场数据
    void getfigth();
    //获得play
    void get_play(to_Figth::fight_info &fight_info,prt_fight &prtFight);
    //获得build
    void get_build(to_Figth::fight_info &fight_info,prt_fight &prtFight);

};


#endif //FIGHTSERVER_PLAYININTHANDELR_H
