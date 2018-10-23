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


    prt_fight figth;
    figth->fightid=figth_init.roomid();
    build_init(figth);
    for(int i=0;i<figth_init.plays_size();i++)
    {   to_Figth::Fight_play *fight_play=rq_fight_init.add_fight_plays();
        to_Figth::play play_=figth_init.plays(i);
        fight_play->set_index(play_.index());
        fight_play->set_play_id((play_.index()));


        prt_Fight_play prt_fight_play=play_init(play_.index(),play_.ranks(),play_.heroid(),play_.rolename());

        if(play_.ranks()==1)
        {
            figth->plyas_one[play_.index()]=prt_fight_play;
        }
        else if(play_.ranks()==2)
        {
            figth->plyas_tow[play_.index()]=prt_fight_play;
        }
    }
    FightData::get_FightData()->add_fight(figth->fightid,figth);
    std::string buf=rq_fight_init.SerializeAsString();
    tosend(10,1,1,buf);
}


//初始化箭塔
void Figth_initHandler::build_init(prt_fight &figth)
{


        //一队
        FightBuild fighttower_1(11,1,"低级箭塔",600,60,0,15,70,600,600, true, true, false,0); //一塔
        FightBuild fighttower_2(12,2,"中级箭塔",800,60,0,15,70,600,600, true, true, false,0);//二塔
        FightBuild fighttower_3(13,3,"高级箭塔",1200,120,0,15,120,600,600, true, true, false,0);//三塔
        figth->build_one[fighttower_1.id_]=std::make_shared<FightBuild>(fighttower_1);
        figth->build_one[fighttower_2.id_]=std::make_shared<FightBuild>(fighttower_2);
        figth->build_one[fighttower_3.id_]=std::make_shared<FightBuild>(fighttower_3);

        //二队
        FightBuild fighttower_4(14,4,"低级箭塔",600,60,0,15,70,600,600, true, true, false,0); //一塔
        FightBuild fighttower_5(15,5,"中级箭塔",800,90,0,15,900,600,600, true, true, false,0);//二塔
        FightBuild fighttower_6(16,6,"高级箭塔",1200,120,0,15,120,600,600, true, true, false,0);//三塔
        figth->build_tow[fighttower_4.id_]=std::make_shared<FightBuild>(fighttower_4);
        figth->build_tow[fighttower_5.id_]=std::make_shared<FightBuild>(fighttower_5);
        figth->build_tow[fighttower_6.id_]=std::make_shared<FightBuild>(fighttower_6);

//        //兵营
//        FightBuild fight_camp1(17,4,"兵营",1200,0,0,20,0,0,600,false, false, true,120);//兵营
//        figth->build_one[17]=std::make_shared<FightBuild>(fight_camp1);
//        FightBuild fight_camp2(18,4,"兵营",1200,0,0,20,0,0,600,false, false, true,120);//兵营
//        figth->build_one[18]=std::make_shared<FightBuild>(fight_camp2);
//
//        //基地
//        FightBuild fight_base1(19,4,"基地",1200,0,0,15,0,0,600,false, false, false,0);//兵营
//        figth->build_one[19]=std::make_shared<FightBuild>(fight_base1);
//        FightBuild fight_base2(20,4,"基地",1200,0,0,15,0,0,600,false, false, false,0);//兵营
//        figth->build_one[20]=std::make_shared<FightBuild>(fight_base2);
}

//获得一个play
prt_Fight_play Figth_initHandler::play_init(int playid,int ranks,int herid,std::string name)
{

    Fightplay fightplay;
    fightplay.id_=playid;
    fightplay.role_name=name;

    Hero hero=HeroData::Hero_map[herid];

    fightplay.level_=1;
    fightplay.money_=0;
    fightplay.ranks=ranks;
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
        skill.id=i;
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