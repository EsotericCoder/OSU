/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Kitchen Header file
 ************************************************************************/

#ifndef Kitchen_hpp
#define Kitchen_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class Kitchen : public Space
{
public:
    Kitchen(Player *p);
    int option();
};

#endif /* Kitchen_hpp */
