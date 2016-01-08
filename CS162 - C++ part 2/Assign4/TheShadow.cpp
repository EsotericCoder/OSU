/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: TheShadow header
 ************************************************************************/

#include "TheShadow.hpp"

//Overload defense
int TheShadow::defense()
{
    int roll = 0;
    int x = (rand() % 2) + 1; //50/50 chance of attack
    
    //If 1 then an actual defense is rolled.
    if(x == 1){
        roll = rollDice(dSides);
    //If 2 then defense will return a high number that will block all attacks.
    }else if(x == 2){
        roll = 100;
    }
    
    return roll;
}