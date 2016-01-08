/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Creature Class
 ************************************************************************/

#include "Creature.hpp"

Creature::Creature()
{
}


int Creature::rollDice(int sides)
{
    int rolledDice = (rand() % sides) + 1;
    return rolledDice;
}
