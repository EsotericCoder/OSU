/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Barbarian header
 ************************************************************************/

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include <stdio.h>
#include "Creature.hpp"

class Barbarian : public Creature
{
protected:
    int strength;
    int armor;
    int aNum;
    int aSides;
    int dNum;
    int dSides;
public:
    Barbarian(){
        this->strength = 12;
        this->armor = 0;
        this->aNum = 2;
        this->aSides = 6;
        this->dNum = 2;
        this->dSides = 6;
    };
    int attack();
    int defense();
    void setStrength(int newStrength){strength = newStrength;};
    int getStrength(){ return strength;};
    int getArmor(){ return armor;};
};



#endif /* Barbarian_hpp */
