/******************************************************************************************
 ** Author: William Kim
 ** Date: 11/15/2015
 ** Description: Die Header
 *****************************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    public:

        Die ();

//printNumber defines the value of a die roll, and prints it to screen, it is then
//called to collect a history of all rolls.

        int printNumber (int sides);
};

#endif
