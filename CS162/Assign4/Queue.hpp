/****************************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: Queue Header
 ***************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <string>
#include "Creature.hpp"

class Queue
{
    //Struct node that holds figher info
    struct fighter
    {
        std::string name;
        std::string creatureType;
        Creature *creature;
        fighter *next;
    };
    
public:
    Queue();
    ~Queue();
    void add(std::string n, std::string t, Creature *c);
    void addBack(fighter *f);
    void remove();
    
    fighter *front,*rear;
    
};

#endif /* Queue_hpp */
