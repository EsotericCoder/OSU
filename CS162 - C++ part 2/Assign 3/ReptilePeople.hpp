/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: ReptilePeople header
 ************************************************************************/

#ifndef ReptilePeople_hpp
#define ReptilePeople_hpp

#include <stdio.h>
#include "Creature.hpp"

class ReptilePeople : public Creature
{
private:
    int strength;
    int armor;
    int aNum;
    int aSides;
    int dNum;
    int dSides;
public:
    ReptilePeople(){
        strength = 18;
        armor = 7;
        aNum = 3;
        aSides = 6;
        dNum = 1;
        dSides = 6;
    };
    int attack();
    int defense();
    void setStrength(int newStrength){strength = newStrength;};
    int getStrength(){ return strength;};
    int getArmor(){ return armor;};
};

#endif /* ReptilePeople_hpp */
