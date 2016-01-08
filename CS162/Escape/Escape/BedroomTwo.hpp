/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: BedroomTwo Header file
 ************************************************************************/

#ifndef BedroomTwo_hpp
#define BedroomTwo_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class BedroomTwo : public Space
{
public:
    BedroomTwo(Player *p);
    int option();
};
#endif /* BedroomTwo_hpp */
