//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_FIGHTBUILD_H
#define FIGHTSERVER_FIGHTBUILD_H

#include "AbsFight.h"

//建筑类
class FightBuild: public AbsFight {


public:
    FightBuild();
    FightBuild(int id, int code,std::string name, int hp, int atk, int mp, int def, float aspee, float arange,
    float eyerange, bool infrared,bool nottoatk, bool born,int bornTime);
    bool born_;//是否重生
    int bornTime_;//重生的时间
    bool nottoatk_;//是否会攻击
    bool infrared_;//是否反隐
};


#endif //FIGHTSERVER_FIGHTBUILD_H
