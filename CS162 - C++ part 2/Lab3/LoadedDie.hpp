/******************************************************************************************
 ** Author: William Kim
 ** Date: 11/15/2015
 ** Description: LoadedDie Header
 *****************************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die
{
    public:

 //printNumber defines the value of a die roll, and prints it to screen, it is then
 //used to collect a history of all rolls.

        int printNumber (int sides);


};

#endif
