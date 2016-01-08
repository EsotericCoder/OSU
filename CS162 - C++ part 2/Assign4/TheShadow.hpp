/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: TheShadow header
 ************************************************************************/

#ifndef TheShadow_hpp
#define TheShadow_hpp

#include <stdio.h>
#include "Creature.hpp"
#include <stdlib.h>

class TheShadow : public Creature
{
    
public:
    TheShadow(){
        strength = 12;
        armor = 0;
        aNum = 2;
        aSides = 10;
        dNum = 1;
        dSides = 6;
    };
    int defense();
};
#endif /* TheShadow_hpp */
