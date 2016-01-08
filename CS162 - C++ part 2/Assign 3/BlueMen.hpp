/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: BlueMen header
 ************************************************************************/

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Creature.hpp"

class BlueMen : public Creature
{
private:
    int strength;
    int armor;
    int aNum;
    int aSides;
    int dNum;
    int dSides;
public:
    BlueMen(){
        strength = 12;
        armor = 3;
        aNum = 2;
        aSides = 10;
        dNum = 3;
        dSides = 6;
    };
    int attack();
    int defense();
    void setStrength(int newStrength){strength = newStrength;};
    int getStrength(){ return strength;};
    int getArmor(){ return armor;};
};

#endif /* BlueMen_hpp */
