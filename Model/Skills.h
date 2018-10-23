//
// Created by wj_de on 18-10-22.
//

#ifndef FIGHTSERVER_SKILLS_H
#define FIGHTSERVER_SKILLS_H

#include <iostream>
//技能作用目标
enum Skilltarget
{
    SELF_tar,//自身
    FH,//友方英雄
    FH_B,//友方非建筑
    FH_ALL,//友方全部单位
    EH,//敌方英雄
    EH_B,//敌方非建筑
    ESN,//敌方非建筑和中立
    EH_ALL,//敌方全部
};
enum SkillType
{
    SELF,//以自己为圆心
    TAGGET,//以目标为圆心
    Position,//鼠标位置为圆心
    PASSIVE,//被动技能
};
class Skills {

public:
    Skills();
    Skills(int code, int level,int nextLevle,int times,std::string name,std::string info,Skilltarget skilltarget,SkillType skillType);
    int id;
    int code_;//唯一编号
    int level_;//等级
    int nextLevle_;//升级需要等级
    int times_;//冷却时间
    float arange_;//施法距离
    std::string name_;//技能名称
    std::string info_;//技能描述
    Skilltarget  skilltarget_;//作用目标
    SkillType skillType_;//技能释放方式
};


#endif //FIGHTSERVER_SKILLS_H
