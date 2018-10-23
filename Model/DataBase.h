//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DATABSE_H
#define LOGINSERVER_DATABSE_H

#include "Hero.h"
#include <map>
#include <shared_mutex>
#include "../Net/Tcpcoonetion.h"
#include "Fight.h"
typedef ZL::Net::TcpcoontionPrt CoonPrt;
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

//储存一个链接对对应的战场ID，和角色id
//在第一次用户需要传入战场ID和角色ID进行初始，
//之后的就不用传递这两个ID了
class play_ids
{
public:
     play_ids();
     play_ids(int fid,int pid);
     int fightid_;
     int playid_;
};
class PlayFIghtData
{
private:
    PlayFIghtData();
    std::shared_timed_mutex mutex_;
    std::map<CoonPrt,play_ids> play_id_map;
    static PlayFIghtData * playFIghtData;
public:
    static PlayFIghtData *get_PlayFIghtData();
    void add_play(const CoonPrt coonPrt,int fightid,int playid);
    play_ids get_play(const CoonPrt coonPrt);
    void remove_play(const CoonPrt coonPrt);
};

typedef std::shared_ptr<Figth> prt_fight;
class FightData
{
private:
    FightData();
    std::shared_timed_mutex mutex_;
    static FightData *fightData;
    std::map<int,prt_fight> fight_map;
public:
    static FightData * get_FightData();
    void add_fight(int id,prt_fight prt_fight1);
    prt_fight get_fight(int id);
    void remove_fight(int id);
};




#endif //LOGINSERVER_DATABSE_H
