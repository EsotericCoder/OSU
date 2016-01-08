/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: BedroomOne Header file
 ************************************************************************/

#ifndef BedroomOne_hpp
#define BedroomOne_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class BedroomOne : public Space
{
public:
    BedroomOne(Player *p);
    int option();
};
#endif /* BedroomOne_hpp */
