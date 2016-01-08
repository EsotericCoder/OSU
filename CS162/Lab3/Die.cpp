/******************************************************************************************
 ** Author: William Kim
 ** Date: 11/15/2015
 ** Description: Die class
 *****************************************************************************************/

#include "Die.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

    Die::Die ()
    {
    
    }


//printNumber defines the value of a die roll, and prints it to the screen, it is then
//called to collect a history of all rolls.

    int Die::printNumber (int sides)
    {
        int returnvalue = rand()%sides+1;
        return returnvalue;
    }
