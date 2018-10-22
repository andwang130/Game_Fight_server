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
    int port;
    std::string ip;
};


#endif //FIGHTSERVER_FIGTH_INITHANDLER_H
