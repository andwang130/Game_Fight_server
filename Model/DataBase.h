//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DATABSE_H
#define LOGINSERVER_DATABSE_H

#include "Hero.h"
#include <map>


class SkillLeveData
{
public:
    SkillLeveData();
    SkillLeveData(int level,int times,int mp, float arange);
    int level_;//学习等级
    int times_;//冷却时间
    int mp_;//蓝耗
    float arang_;//范围


};

class SkillsDatamodl
{
public:
    int code_;
    std::vector<SkillLeveData> skillLevedata_;
    std::string name_;//技能名称
    std::string info_;//技能描述
    Skilltarget  skilltarget_;//作用目标
    SkillType skillType_;//技能释放方式

};

class SkillsData
{
public:
    void init();
    void create(int code,std::string name,std::string info,Skilltarget skilltarget,SkillType  skillType,std::vector<SkillLeveData> skillLevedata);

    static std::map<int,SkillsDatamodl> Skills_map;
};
class HeroData
{
public:
    static std::map<int,Hero> Hero_map;
    void init();

    void create(int code,std::string name,int atkBase,int defBase,int hpBase,int mpBase,int atkarr,int defarr,
    int hparr,int mparr, float speed, float aspeed, float arange, float eyerange,std::vector<int> skills);
};


#endif //LOGINSERVER_DATABSE_H
