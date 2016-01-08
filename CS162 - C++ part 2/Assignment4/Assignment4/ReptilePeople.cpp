/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: ReptilePeople Class
 ************************************************************************/


#include "ReptilePeople.hpp"

//Overload regenerate to lower regenerated strength
void ReptilePeople::regenerate()
{
    setStrength(getStrength() + 2);
}