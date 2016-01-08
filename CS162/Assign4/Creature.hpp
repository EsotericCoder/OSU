/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Creature header
 ************************************************************************/

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class Creature
{
protected:
    int strength;
    int armor;
    int aNum;
    int aSides;
    int dNum;
    int dSides;
public:
    Creature();
    virtual int attack();
    virtual int defense();
    virtual void regenerate();
    virtual void setStrength(int newStrength){strength = newStrength;};
    virtual int getStrength(){ return strength;};
    virtual int getArmor(){ return armor;};
    virtual int rollDice(int sides);
};

#endif /* Creature_hpp */
