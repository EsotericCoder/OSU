/******************************************************************************************
 ** Author: William Kim
 ** Date: 11/15/2015
 ** Description: LoadedDie class
 *****************************************************************************************/

#include "LoadedDie.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


 //printNumber defines the value of a crooked die roll, and prints it to screen, it is then
 //used to collect a history of all rolls.

// program adds half of the difference between the roll number and maximum possible roll
//to the actual roll.

    int LoadedDie::printNumber (int sides)
    {

        int returnvalue = rand()%sides+1;

        if (returnvalue == sides)
            {
                return returnvalue;
            }

        else
            {
                
                return returnvalue + ((sides-returnvalue)/2);
            }
    }


