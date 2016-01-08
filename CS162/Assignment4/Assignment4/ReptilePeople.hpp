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
    
public:
    ReptilePeople(){
        strength = 18;
        armor = 7;
        aNum = 3;
        aSides = 6;
        dNum = 1;
        dSides = 6;
    };
    void regenerate();
};

#endif /* ReptilePeople_hpp */
