//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_FIGHT_PLAY_H
#define FIGHTSERVER_FIGHT_PLAY_H

#include "Skills.h"
#include "AbsFight.h"
#include <vector>

//玩家类，拥有基础AbsFight属性外的其他属性
class Fightplay: public AbsFight {
public:
    int level_;//等级
    int  exp_; //经验
    int free_; //技能点
    int money_;//金钱
    std::string role_name;//用户名称
    std::vector<int >equs_;//装备
    std::vector<Skills> Skills_;//技能
    int ranks;
};


#endif //FIGHTSERVER_FIGHT_PLAY_H
