/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/1/2015
 ** Description: Die header file
 *****************************************************************************************/

#ifndef Die_hpp
#define Die_hpp
#include <stdlib.h>


class Die
{
    private:
        int numberOfSides;
    public:
        Die();
        int rollDice();
};

#endif
