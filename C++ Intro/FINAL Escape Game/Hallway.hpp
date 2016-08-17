/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Hallway Header file
 ************************************************************************/

#ifndef Hallway_hpp
#define Hallway_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class Hallway : public Space
{
public:
    Hallway(Player *p);
    int option();
};

#endif /* Hallway_hpp */
