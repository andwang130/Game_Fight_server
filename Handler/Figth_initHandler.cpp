//
// Created by wj_de on 18-10-22.
//

#include "Figth_initHandler.h"
#include "../protobuf_maegss/to_Fight.pb.h"
Figth_initHandler::Figth_initHandler(const CoonPrt &coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    port=8081;
    ip="127.0.0.1";

    switch(aProtocol_.coomd)
    {
        case Login_to_Fight::send::coomd::Fight_init:
        {
            init_fight();
            break;
        }
    }


}
void Figth_initHandler::init_fight()
{
    to_Figth::Figth_init figth_init;
    if(!figth_init.ParseFromString(aProtocol_.data))
    { return;}

    to_Figth::rq_Fight_init rq_fight_init;
    rq_fight_init.set_port(port);
    rq_fight_init.set_ip(ip);
    rq_fight_init.set_roomid(figth_init.roomid());


    Figth figth;
    figth.fightid=figth_init.roomid();
    for(int i=0;i<figth_init.plays_size();i++)
    {   to_Figth::Fight_play *fight_play=rq_fight_init.add_fight_plays();
        to_Figth::play play_=figth_init.plays(i);
        fight_play->set_index(play_.index());
        fight_play->set_play_id((play_.index()));


        prt_Fight_play prt_fight_play=play_init(play_.index(),play_.heroid(),play_.rolename());

        if(play_.ranks()==1)
        {
            figth.plyas_one[play_.index()]=prt_fight_play;
        }
        else if(play_.ranks()==2)
        {
            figth.plyas_tow[play_.index()]=prt_fight_play;
        }
    }

    std::string buf=rq_fight_init.SerializeAsString();
    tosend(10,1,1,buf);
}


//初始化箭塔
prt_Fight_build Figth_initHandler::tower_init(int id)
{




}

//获得一个play
prt_Fight_play Figth_initHandler::play_init(int playid,int herid,std::string name)
{

    Fightplay fightplay;
    fightplay.id_=playid;
    fightplay.role_name=name;

    Hero hero=HeroData::Hero_map[herid];

    fightplay.level_=1;
    fightplay.money_=0;
    fightplay.exp_=0;
    fightplay.name_=hero.name_;
    fightplay.equs_={0};
    fightplay.atk_=hero.atkBase_;
    fightplay.def_=hero.defBase_;
    fightplay.code_=hero.code_;
    fightplay.arange_=hero.arange_;
    fightplay.eyerange_=hero.eyerange_;
    fightplay.speed_=hero.speed_;
    fightplay.mp_=hero.mpBase_;
    fightplay.maxmp_=hero.mpBase_;
    fightplay.hp_=hero.hpBase_;
    fightplay.maxhp_=hero.hpBase_;
    fightplay.modleType_=ModleType::HUMAN;
    fightplay.aspee_=hero.aspeed_;
    fightplay.free_=1;

    std::vector<Skills> skills;
    for(int i:hero.skills_)
    {
        Skills skill;
        SkillsDatamodl skillsDatamodl=SkillsData::Skills_map[i];
        skill.arange_=skillsDatamodl.skillLevedata_[0].arang_;
        skill.code_=skillsDatamodl.code_;
        skill.level_=0;
        skill.info_=skillsDatamodl.info_;
        skill.times_=skillsDatamodl.skillLevedata_[0].times_;
        skill.nextLevle_=skillsDatamodl.skillLevedata_[1].level_;
        skill.skilltarget_=skillsDatamodl.skilltarget_;
        skill.skillType_=skillsDatamodl.skillType_;
        skill.name_=skillsDatamodl.name_;
        skills.push_back(skill);
    }


    fightplay.Skills_=skills;


    return std::make_shared<Fightplay>(fightplay);



}