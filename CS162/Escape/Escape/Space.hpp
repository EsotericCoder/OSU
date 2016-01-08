/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Space Header file
 ************************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Player.hpp"

using namespace std;

class Space
{
protected:
    Space *space1,*space2,*space3,*space4;              //four space pointers
    Player *player;                                     //player pointer
    
public:
    Space();                                            //default constructor
    Space(Player *p);                                   //constructor to set player pointer
    virtual int option() = 0;                           //action function
    virtual Space* getSpace(int i);                     //gets the next space
    //Sets the available space pointers
    virtual void addSpace(Space *one, Space *two, Space *three, Space *four);
};
#endif /* Space_hpp */
