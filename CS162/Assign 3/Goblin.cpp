/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Barbarian header
 ************************************************************************/

#include "Goblin.hpp"

int Goblin::attack()
{
    int roll[3] = { 0, 0, 0 };
    for (int i = 0; i < aNum; i++) {
        roll[i] = rollDice(aSides);
    }
    return roll[0] + roll[1] + roll[2];
}

int Goblin::defense()
{
    int roll[3] = {0, 0, 0};
    for(int i = 0; i < dNum; i++) {
        roll[i] = rollDice(dSides);
    }
    return roll[0] + roll[1] + roll[2];
}