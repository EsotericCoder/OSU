/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: BedroomOne Class
 ************************************************************************/

#include "BedroomOne.hpp"

BedroomOne::BedroomOne(Player *p)
{
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;
}

int BedroomOne::option(){
    int userChoice = 0;
    
    while(userChoice != 1)
    {
        cout << "\n-Bedroom One-\n\nThis room is covered in blood!"<< endl;
        cout << "Enter 1 to leave room" << endl;
        cout << "Enter 2 check out window" << endl;
        cin >> userChoice;
        if (userChoice == 2) {
            while (userChoice != 1) {
                cout << "\nThe window is nailed shut and boarded up..." << endl;
                cout << "Enter 1 to leave the room" << endl;
                cout << "Enter 2 to try and escape" << endl;
                cin >> userChoice;
                if (userChoice == 2) {
                    if (player->getSledgehammer() && !player->getClownStatus()) {
                        cout << "\nUses sledgehammer to smash through the window and escapes!" << endl;
                        player->escapes();
                        return 10;               //Player escape and wins the game
                    }else if(!player->getSledgehammer() && player->getClownStatus()){
                        cout << "\nYou made too much noise and the clown wakes up and kills you!" << endl;
                        player->dies();
                        return 9;               //Player dies
                            
                    }else{
                        cout << "\nUnable to open the window..." << endl;
                    }
                }
            }
        }
    }
    return 1;   //Leave Room
}

