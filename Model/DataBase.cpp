//
// Created by wj_de on 18-10-10.
//
#include "DataBase.h"
std::map<int,SkillsDatamodl> SkillsData::Skills_map;
std::map<int,Hero> HeroData::Hero_map;
SkillLeveData::SkillLeveData(int level,int times,int mp, float arange)
{
    level_=level;
    times_=times;
    mp_=mp;
    arang_=arange;
}

void SkillsData::init()
{
    std::vector<SkillLeveData> fw_skiill={SkillLeveData(1,30,100,300),SkillLeveData(3,50,150,300),SkillLeveData(7,70,200,300)};
    create(0,"欺诈宝珠","消耗 65/70/75/80/85法力 \\n冷却7/7/7/7/7 \\n射程 880 \\n效果 阿狸放出宝珠，造成40/65/90/115/140(+0.35)魔法伤害，随后将其收回，造成40/65/90/115/140(+0.35)真实伤害。",Skilltarget::EH,SkillType::Position,fw_skiill);
}
void SkillsData::create(int code,std::string name,std::string info,Skilltarget skilltarget,SkillType  skillType,std::vector<SkillLeveData> skillLevedata)
{
    SkillsDatamodl skillsDatamodl;
    skillsDatamodl.code_=code;
    skillsDatamodl.info_=info;
    skillsDatamodl.name_=name;
    skillsDatamodl.skilltarget_=skilltarget;
    skillsDatamodl.skillType_=skillType;
    skillsDatamodl.skillLevedata_=skillLevedata;
    Skills_map[code]=skillsDatamodl;
}
void HeroData::init()
{
    create(0,"魅惑魔女",30,5,600,300,5,1,10,5,275,120,600,600,{1,2,3,4});
}
void HeroData::create(int code,std::string name,int atkBase,int defBase,int hpBase,int mpBase,int atkarr,int defarr,
            int hparr,int mparr, float speed, float aspeed, float arange, float eyerange,std::vector<int> skills)
{
    Hero hero;
    hero.code_=code;
    hero.name_=name;
    hero.atkBase_=atkBase;
    hero.atkarr_=atkarr;
    hero.defBase_=defBase;
    hero.defarr_=defBase;
    hero.hpBase_=hpBase;
    hero.hparr_=hparr;
    hero.mpBase_=mpBase;
    hero.mparr_=mparr;
    hero.speed_=speed;
    hero.arange_=arange;
    hero.eyerange_=eyerange;
    hero.aspeed_=aspeed;
    hero.skills_=skills;
    Hero_map[code]=hero;
}