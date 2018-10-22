//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_HERO_H
#define FIGHTSERVER_HERO_H

#include <vector>
#include "Skills.h"
class Hero {

public:
    Hero(){};
    Hero(int code,std::string name,int atkbase,int defbase,int hpbase,int mpbase,int atkarr,int intdefarr,int defarr,
         float speed, float aspeed, float arange, float eyerange,std::vector<Skills> skills);
    int code_;
    std::string name_;
    int atkBase_;//基础攻击
    int defBase_;//基础防御
    int hpBase_;//基础血量
    int mpBase_;//基础蓝量
    int atkarr_;//攻击成长
    int defarr_;//防御成长
    int hparr_;//血量成长
    int mparr_;//蓝量成长
    float speed_;//移动速度
    float aspeed_;//攻击速度
    float arange_;//攻击范围
    float eyerange_;//视野范围
    std::vector<int> skills_;

};


#endif //FIGHTSERVER_HERO_H
