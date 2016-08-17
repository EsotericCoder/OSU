/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Player Class
 ************************************************************************/

#include "Player.hpp"

//Default constructor
Player::Player()
{
    alive = true;
    clownIsAlive = true;
    hasSledgehammer = false;
    hasKey = false;
    count = 0;
}

//Adds item to the backpack container
void Player::addItem(std::string item)
{
    if (item == "key") {
        backpack[count] = item;
        count++;
        hasKey = true;
    }else if (item == "sledgehammer"){
        backpack[count] = item;
        count++;
        hasSledgehammer = true;
    }
}