/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Creature Class
 ************************************************************************/

#include "Creature.hpp"

//Constructor
Creature::Creature()
{
    strength = 0;
    armor = 0;
    aNum = 0;
    aSides = 0;
    dNum = 0;
    dSides = 0;
}

//Attack rolls dice aNum number of times for total attack points
int Creature::attack()
{
    int roll[3] = { 0, 0, 0 };
    for (int i = 0; i < aNum; i++) {
        roll[i] = rollDice(aSides);
    }
    return roll[0] + roll[1] + roll[2];
}

//Defense rolls dice dNum number of times for total defense points
int Creature::defense()
{
    int roll[3] = {0, 0, 0};
    for(int i = 0; i < dNum; i++) {
        roll[i] = rollDice(dSides);
    }
    return roll[0] + roll[1] + roll[2];
}

//Regenerates strength of winners 4 points
void Creature::regenerate()
{
    setStrength(getStrength() + 4);
}

//Rolls Dice
int Creature::rollDice(int sides)
{
    int rolledDice = (rand() % sides) + 1;
    return rolledDice;
}
