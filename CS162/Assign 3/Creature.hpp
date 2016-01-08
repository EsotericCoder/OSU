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
public:
    Creature();
    virtual int attack()=0;
    virtual int defense()=0;
    virtual void setStrength(int newStrength)=0;
    virtual int getStrength()=0;
    virtual int getArmor()=0;
    virtual int rollDice(int sides);
};

#endif /* Creature_hpp */
