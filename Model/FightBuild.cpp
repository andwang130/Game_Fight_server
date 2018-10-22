//
// Created by wj_de on 18-10-22.
//

#include "FightBuild.h"

FightBuild::FightBuild(int id, int code, int hp, int atk, int mp, int def, float aspee, float arange,
                       float eyerange)
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

}