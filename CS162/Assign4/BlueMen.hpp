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
public:
    BlueMen(){
        strength = 12;
        armor = 3;
        aNum = 2;
        aSides = 10;
        dNum = 3;
        dSides = 6;
    };
};

#endif /* BlueMen_hpp */
