/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/1/2015
 ** Description: Die class
 *****************************************************************************************/

#include "Die.hpp"

Die::Die(){
    numberOfSides = 6;
}

int Die::rollDice(){
    int roll = (rand() % numberOfSides) + 1; //Generates a random number 1-6
    return roll;
}