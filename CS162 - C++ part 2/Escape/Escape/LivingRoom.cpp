/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: LivingRoom Class
 ************************************************************************/

#include "LivingRoom.hpp"

LivingRoom::LivingRoom(Player *p)
{
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;
}


int LivingRoom::option(){
    int userChoice = 0;
    //Living room menu
    while(!(userChoice == 1 || userChoice == 2))
    {
        cout << "\n-Living Room-\n"<< endl;
        cout << "Enter 1 to enter Hallway" << endl;
        cout << "Enter 2 to enter Kitchen" << endl;
        cout << "Enter 3 to open Front Door" << endl;
        cin >> userChoice;
        if (userChoice == 3) {
            if (player->getKey()) {
                cout << "\nYou opened the door with the key and escaped to freedom!" << endl;
                player->escapes();
                return 10;                  //player escapes and wins the game
            }else{
                cout << "\nThe door is locked..." << endl;
            }
        }
    }
    if (userChoice == 1) {
        return 1;                           //Return 1 for Space 1
    }else{
        return 2;                           //Return 2 for Space 2
    }
}