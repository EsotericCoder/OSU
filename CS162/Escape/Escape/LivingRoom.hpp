/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: LivingRoom Header file
 ************************************************************************/

#ifndef LivingRoom_hpp
#define LivingRoom_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class LivingRoom : public Space
{
public:
    LivingRoom(Player *p);
    int option();
};

#endif /* LivingRoom_hpp */
