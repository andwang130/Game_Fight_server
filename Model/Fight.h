//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_FIGTH_H
#define FIGHTSERVER_FIGTH_H

#include "Fightplay.h"
#include <map>
#include <memory>
typedef std::shared_ptr<Fightplay> prt_Fight_play;
class Figth {


public:
    int fightid;

    std::map<int,prt_Fight_play> plyas_;

    int times;
};


#endif //FIGHTSERVER_FIGTH_H
