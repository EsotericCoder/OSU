/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: TheShadow header
 ************************************************************************/

#ifndef TheShadow_hpp
#define TheShadow_hpp

#include <stdio.h>
#include "Creature.hpp"

class TheShadow : public Creature
{
private:
    int strength;
    int armor;
    int aNum;
    int aSides;
    int dNum;
    int dSides;
public:
    TheShadow(){
        strength = 12;
        armor = 0;
        aNum = 2;
        aSides = 10;
        dNum = 1;
        dSides = 6;
    };
    int attack();
    int defense();
    void setStrength(int newStrength){strength = newStrength;};
    int getStrength(){ return strength;};
    int getArmor(){ return armor;};
};
#endif /* TheShadow_hpp */
