/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/1/2015
 ** Description: LoadedDie header file
 *****************************************************************************************/

#ifndef LoadedDie_hpp
#define LoadedDie_hpp
#include <stdlib.h>

class LoadedDie
{
private:
    int numberOfSides;
public:
    LoadedDie();
    int rollLoadedDice();
};

#endif
