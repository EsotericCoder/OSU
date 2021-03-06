/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Goblin header
 ************************************************************************/

#ifndef Goblin_hpp
#define Goblin_hpp

#include <stdio.h>
#include "Creature.hpp"

class Goblin : public Creature
{
    
public:
    Goblin(){
        strength = 8;
        armor = 3;
        aNum = 2;
        aSides = 6;
        dNum = 1;
        dSides = 6;
    };
    void regenerate();
};
#endif /* Goblin_hpp */
