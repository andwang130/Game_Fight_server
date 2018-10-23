//
// Created by wj_de on 18-10-23.
//

#include "PlayinintHandelr.h"
#include "../protobuf_maegss/to_Fight.pb.h"
PlayinintHandelr::PlayinintHandelr(const CoonPrt &coonPrt, protocol_ &aProtoco):BaseHandler(coonPrt,aProtoco)
{

    switch (aProtoco.coomd)
    {
        case play_init::send::coomd::to_fight:
        {
            playtoFight();
            break;
        }
        case play_init::send::coomd::get_fight_info:
        {
            getfigth();
            break;
        }
    }
}
void PlayinintHandelr::playtoFight()
{
    to_Figth::play_inti play_inti_;

    if(!play_inti_.ParseFromString(aProtocol_.data))
    {
        return;
    }

    int fightid=play_inti_.fight_id();
    int playid=play_inti_.play_id();

    PlayFIghtData::get_PlayFIghtData()->add_play(coonPrt_,fightid,playid);

    prt_fight fight=FightData::get_FightData()->get_fight();
    if(fight== nullptr)
    { return;}

    prt_Fight_play prt_play;
    //读锁
    {
        std::shared_lock<std::shared_timed_mutex> lw(fight->mutex_,std::defer_lock);
        auto ite1=fight->plyas_one.find(playid);
        if(ite1==fight->plyas_one.end())
        {
            auto ite2=fight->plyas_tow.find(playid);
            if(ite2==fight->plyas_tow.end())
            {
                return;
            } else
            {
                prt_play=ite2->second;
            }
        }
        else{
            prt_play=ite1->second;
        }

    }
    //写锁
    {
        std::unique_lock<std::shared_timed_mutex> lr(fight->mutex_,std::defer_lock);
        fight->plyas_[coonPrt_]=prt_play;
    }

    tosend(11,1,play_init::send::coomd::to_fight_code,"");
}
void getfigth()
{

    play_ids play_ids_=PlayFIghtData::get_PlayFIghtData()->get_play();
    //返回的值是-1，不在当中，直接return
    if(play_ids_.fightid_==-1)
    {
        return;
    }

    prt_fight fight=FightData::get_FightData()->get_fight(play_ids_.fightid_);
    //该战场不存在，直接return
    if(fight== nullptr)
    { return;}

    std::shared_lock<std::shared_timed_mutex> lr(fight,std::defer_lock);
    to_Figth::fight_info fight_info_;
    get_play(fight_info_,fight);
    get_build(fight_info_,fight);
}
void PlayinintHandelr::get_play(to_Figth::fight_info &fight_info,prt_fight &prtFight)
{

    for(auto ite:prtFight->plyas_one)
    {
      prt_Fight_play play=ite.second;
      to_Figth::fplay *fplay_=fight_info.add_fplays();
      fplay_->set_id(play->id_);
      fplay_->set_hp(play->id_);
      fplay_->set_maxhp(play->maxhp_);
      fplay_->set_mp(play->mp_);
      fplay_->set_maxmp(play->maxmp_);
      fplay_->set_name(play->name_);
      fplay_->set_rolename(play->role_name);
      fplay_->set_speed(play->speed_);
      fplay_->set_level(play->level_);
      fplay_->set_code(play->code_);
      fplay_->set_atk(play->atk_);
      fplay_->set_exp(play->exp_);
      fplay_->set_free(play->free_);
      fplay_->set_eyerange(play->eyerange_);
      fplay_->set_aspee(play->aspee_);
      fplay_->set_arange(play->arange_);
      fplay_->set_modletype(play->modleType_);
      for(int i=0;i<play->equs_.size();i++)
      {
          to_Figth::equ *equ_=fplay_->add_equs();
          equ_->set_id(play->equs_[i]);
      }
      for(int i=0;i<play->Skills;i++)
      {
          to_Figth::skill *skill_=fplay_->add_skills();
          skill_->set_info(play->Skills_[i].info_);
          skill_->set_level(play->Skills_[i].level_);
          skill_->set_nextlevle(play->Skills_[i].nextLevle_);
          skill_->set_skilltarget(play->Skills_[i].skilltarget_);
          skill_->set_skilltype(play->Skills_[i].skillType_);
          skill_->set_times(play->Skills_[i].times_);
          skill_->set_name(play->Skills_[i].name_);
          skill_->set_code(play->Skills_[i].code_);
          skill_->set_arange(play->Skills_[i].arange_);
      }

    }
    for(auto ite:prtFight->plyas_tow)
    {

        prt_Fight_play play=ite.second;
        to_Figth::fplay *fplay_=fight_info.add_fplays();
        fplay_->set_id(play->id_);
        fplay_->set_hp(play->id_);
        fplay_->set_maxhp(play->maxhp_);
        fplay_->set_mp(play->mp_);
        fplay_->set_maxmp(play->maxmp_);
        fplay_->set_name(play->name_);
        fplay_->set_rolename(play->role_name);
        fplay_->set_speed(play->speed_);
        fplay_->set_level(play->level_);
        fplay_->set_code(play->code_);
        fplay_->set_atk(play->atk_);
        fplay_->set_exp(play->exp_);
        fplay_->set_free(play->free_);
        fplay_->set_eyerange(play->eyerange_);
        fplay_->set_aspee(play->aspee_);
        fplay_->set_arange(play->arange_);
        fplay_->set_modletype(play->modleType_);
        for(int i=0;i<play->equs_.size();i++)
        {
            to_Figth::equ *equ_=fplay_->add_equs();
            equ_->set_id(play->equs_[i]);
        }
        for(int i=0;i<play->Skills;i++)
        {
            to_Figth::skill *skill_=fplay_->add_skills();
            skill_->set_info(play->Skills_[i].info_);
            skill_->set_level(play->Skills_[i].level_);
            skill_->set_nextlevle(play->Skills_[i].nextLevle_);
            skill_->set_skilltarget(play->Skills_[i].skilltarget_);
            skill_->set_skilltype(play->Skills_[i].skillType_);
            skill_->set_times(play->Skills_[i].times_);
            skill_->set_name(play->Skills_[i].name_);
            skill_->set_code(play->Skills_[i].code_);
            skill_->set_arange(play->Skills_[i].arange_);
        }
    }
}
void PlayinintHandelr::get_build(to_Figth::fight_info &fight_info,prt_fight &prtFight)
{
    for(auto ite:prtFight->build_one)
    {
        prt_Fight_build fbuild=ite.second;
        to_Figth::build *pbuild=fight_info.add_builds();
        pbuild->set_id(fbuild->id_);
        pbuild->set_code(fbuild->code_);
        pbuild->set_eyerange(fbuild->eyerange_);
    }
    for(auto ite:prtFight->build_tow)
    {

    }
}