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
    create(1,"欺诈宝珠","消耗 65/70/75/80/85法力 \\n冷却7/7/7/7/7 \\n射程 880 \\n效果 阿狸放出宝珠，造成40/65/90/115/140(+0.35)魔法伤害，随后将其收回，造成40/65/90/115/140(+0.35)真实伤害。",Skilltarget::EH,SkillType::Position,fw_skiill);
    create(2,"欺诈宝珠","消耗 65/70/75/80/85法力 \\n冷却7/7/7/7/7 \\n射程 880 \\n效果 阿狸放出宝珠，造成40/65/90/115/140(+0.35)魔法伤害，随后将其收回，造成40/65/90/115/140(+0.35)真实伤害。",Skilltarget::EH,SkillType::Position,fw_skiill);
    create(3,"欺诈宝珠","消耗 65/70/75/80/85法力 \\n冷却7/7/7/7/7 \\n射程 880 \\n效果 阿狸放出宝珠，造成40/65/90/115/140(+0.35)魔法伤害，随后将其收回，造成40/65/90/115/140(+0.35)真实伤害。",Skilltarget::EH,SkillType::Position,fw_skiill);
    create(4,"欺诈宝珠","消耗 65/70/75/80/85法力 \\n冷却7/7/7/7/7 \\n射程 880 \\n效果 阿狸放出宝珠，造成40/65/90/115/140(+0.35)魔法伤害，随后将其收回，造成40/65/90/115/140(+0.35)真实伤害。",Skilltarget::EH,SkillType::Position,fw_skiill);

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
    create(1,"魅惑魔女",30,5,600,300,5,1,10,5,275,120,600,600,{1,2,3,4});
    create(2,"魅惑魔女",30,5,600,300,5,1,10,5,275,120,600,600,{1,2,3,4});
    create(3,"魅惑魔女",30,5,600,300,5,1,10,5,275,120,600,600,{1,2,3,4});
    create(4,"魅惑魔女",30,5,600,300,5,1,10,5,275,120,600,600,{1,2,3,4});
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
play_ids::play_ids()
{

}
play_ids::play_ids(int fid,int pid):
fightid_(fid),
playid_(pid)
{

}

PlayFIghtData * PlayFIghtData::playFIghtData= new PlayFIghtData();
PlayFIghtData::PlayFIghtData()
{

}
PlayFIghtData *PlayFIghtData::get_PlayFIghtData()
{

    return playFIghtData;


}

void PlayFIghtData::add_play(const CoonPrt coonPrt,int fightid,int playid)
{
    //使用独占锁，写锁操作
    std::unique_lock<std::shared_timed_mutex> lhs(mutex_, std::defer_lock);

    play_ids play_ids1(fightid,playid);
    play_id_map[coonPrt]=play_ids1;
}
play_ids PlayFIghtData::get_play(const CoonPrt coonPrt)
{
    //读锁
    std::shared_lock<std::shared_timed_mutex> lhs(mutex_,std::defer_lock);

    auto play_id_=play_id_map.find(coonPrt);
    if(play_id_==play_id_map.end())
    {
        return play_ids(-1,-1);
    }
    else
    {
        return play_id_->second;
    }
}
void PlayFIghtData::remove_play(const CoonPrt coonPrt)
{
    std::unique_lock<std::shared_timed_mutex> lhs(mutex_, std::defer_lock);

    play_id_map.erase(coonPrt);
}





FightData *FightData::fightData=new FightData();
FightData::FightData()
{

}
FightData * FightData::get_FightData()
{
    return fightData;
}
void FightData::add_fight(int id,prt_fight prt_fight1)
{
    std::unique_lock<std::shared_timed_mutex> lhs(mutex_,std::defer_lock);
    fight_map[id]=prt_fight1;
}

prt_fight FightData::get_fight(int id)
{
    std::shared_lock<std::shared_timed_mutex> lhs(mutex_,std::defer_lock);
    auto prt_fight1=fight_map.find(id);
    if(prt_fight1==fight_map.end())
    {
        return nullptr;
    }
    else
    {
        return prt_fight1->second;
    }
}

void FightData::remove_fight(int id)
{
    std::unique_lock<std::shared_timed_mutex> lhs(mutex_,std::defer_lock);
    fight_map.erase(id);
}