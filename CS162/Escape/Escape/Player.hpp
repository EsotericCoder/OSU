/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Player Header file
 ************************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>

class Player
{
private:
    bool alive;                                         //Player alive status
    bool clownIsAlive;                                  //Clown alive status
    bool hasKey;                                        //Player has key
    bool hasSledgehammer;                               //Player has sledgehammer
    bool escaped;                                       //Player has escaped
    std::string backpack[2];                            //Backpack container to hold a max of two items
    int count;                                          //count to determine if countainer index
public:
    Player();
    void addItem(std::string item);                     //Add Item function
    void killedClown(){ clownIsAlive = false;};         //Player killed the clown
    void dies(){ alive = false;};                       //Player dies
    void escapes(){escaped = true;};                    //Player escapes
    bool getAliveStatus(){ return alive;};              //Get player is dead or alive
    bool getClownStatus(){ return clownIsAlive;};       //Get clown is dead or alive
    bool getKey(){ return hasKey;};                     //Get if player has key
    bool getSledgehammer(){return hasSledgehammer;};    //Get if player has  sledgehammer
    bool getEscaped() {return escaped;};                //Get if player has escaped
    
};

#endif /* Player_hpp */
