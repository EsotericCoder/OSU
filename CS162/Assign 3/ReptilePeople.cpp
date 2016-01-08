/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: ReptilePeople Class
 ************************************************************************/


#include "ReptilePeople.hpp"

int ReptilePeople::attack()
{
    int roll[3] = { 0, 0, 0 };
    for (int i = 0; i < aNum; i++) {
        roll[i] = rollDice(aSides);
    }
    return roll[0] + roll[1] + roll[2];
}

int ReptilePeople::defense()
{
    int roll[3] = {0, 0, 0};
    for(int i = 0; i < dNum; i++) {
        roll[i] = rollDice(dSides);
    }
    return roll[0] + roll[1] + roll[2];
}