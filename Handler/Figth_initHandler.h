//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_FIGTH_INITHANDLER_H
#define FIGHTSERVER_FIGTH_INITHANDLER_H

#include "BaseHandler.h"
class Figth_initHandler: public BaseHandler  {
public:
     Figth_initHandler(const CoonPrt &coonPrt,protocol_ &aProtocol);
private:

    //战场初始化
    void init_fight();
    //play初始化
    prt_Fight_play play_init(int playid,int ranks,int herid,std::string name);
    void build_init(prt_fight &figth);
    int port;
    std::string ip;
};


#endif //FIGHTSERVER_FIGTH_INITHANDLER_H
