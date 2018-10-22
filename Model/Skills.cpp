//
// Created by wj_de on 18-10-22.
//

#include "Skills.h"
Skills::Skills(int code, int level,int nextLevle,int times,std::string name,std::string info,Skilltarget skilltarget,SkillType skillType)
{
    code_=code;
    level_=level;
    nextLevle_=nextLevle;
    times_=times;
    name_=name;
    info_=info;
    skilltarget_=skilltarget;
    skillType_=skillType;

}
