//
// Created by wj_de on 18-10-22.
//

#include "FightBuild.h"

FightBuild::FightBuild(int id, int code,std::string name, int hp, int atk, int mp, int def, float aspee, float arange,
                       float eyerange, bool infrared,bool nottoatk, bool born,int bornTime)
{
    id_=id;
    code_=code;
    hp_=hp;
    maxhp_=hp;
    mp_=mp;
    maxmp_=mp;
    atk_=atk;
    def_=def;
    aspee_=aspee;
    arange_=arange;
    eyerange_=eyerange;
    infrared_=infrared;
    nottoatk_=nottoatk;
    born_=born;
    bornTime_=bornTime;
    name_=name;

}