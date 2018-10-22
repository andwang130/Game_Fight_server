//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_ABSFIGHT_H
#define FIGHTSERVER_ABSFIGHT_H

#include <iostream>

//各物体的基础类，都有这些属性

//建筑拥有减伤
enum ModleType {
    BUILD,  //建筑
    HUMAN,  //生物
};


class AbsFight {
public:
    int id_; //在场景中的编号
    int code_; //模型编号
    std::string name_; //名称
    ModleType  modleType_;
    int hp_;//当前血量
    int maxhp_;//最大血量
    int mp_;//当前蓝量
    int maxmp_;//最大蓝量
    int atk_;//攻击
    int def_;//防御
    float speed_;//移动速度
    float aspee_;//攻击速度
    float arange_;//攻击范围
    float eyerange_;//视野范围
};


#endif //FIGHTSERVER_ABSFIGHT_H
