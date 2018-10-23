//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_FIGTH_H
#define FIGHTSERVER_FIGTH_H

#include "Fightplay.h"
#include "FightBuild.h"
#include <map>
#include <memory>
#include <shared_mutex>

typedef std::shared_ptr<Fightplay> prt_Fight_play;
typedef std::shared_ptr<FightBuild>prt_Fight_build;
class Figth {


public:
    int fightid;
    std::map<int,prt_Fight_play> plyas_one; //队伍一的英雄
    std::map<int,prt_Fight_play> plyas_tow; //队伍二的英雄
    std::map<int,prt_Fight_build>build_one;//队伍一的建筑
    std::map<int,prt_Fight_build>build_tow;//队伍二的建筑
    std::shared_timed_mutex mutex_;//读写锁
    int times;
};


#endif //FIGHTSERVER_FIGTH_H
