/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: TheShadow header
 ************************************************************************/

#include "TheShadow.hpp"

int TheShadow::attack()
{
    int roll[3] = { 0, 0, 0 };
    for (int i = 0; i < aNum; i++) {
        roll[i] = rollDice(aSides);
    }
    return roll[0] + roll[1] + roll[2];
}

int TheShadow::defense()
{
    int roll[3] = {0, 0, 0};
    for(int i = 0; i < dNum; i++) {
        roll[i] = rollDice(dSides);
    }
    return roll[0] + roll[1] + roll[2];
}