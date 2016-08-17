/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/1/2015
 ** Description: LoadedDie class
 *****************************************************************************************/

#include "LoadedDie.hpp"

LoadedDie::LoadedDie(){
    numberOfSides = 6;
}

int LoadedDie::rollLoadedDice(){
    int roll = (rand() % numberOfSides) + 1; //Generates a random number 1-6
    switch (roll) {
        case 1:
        case 2:
        case 3:
        case 4:
            roll += 2;
            break;
        case 5:
            roll++;
            break;
        default:
            break;
    }
    return roll;
}