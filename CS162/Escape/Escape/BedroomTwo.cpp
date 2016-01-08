/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: BedroomTwo Class
 ************************************************************************/

#include "BedroomTwo.hpp"

BedroomTwo::BedroomTwo(Player *p)
{
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;
}

int BedroomTwo::option(){
    int userChoice = 0;
    
    while(userChoice != 1)
    {
        cout << "\n-Bedroom Two-\n" << endl;
        if (player->getClownStatus()){
            cout << "The killer clown is sleeping on the bed!"<< endl;
        }
        cout << "Enter 1 to leave room" << endl;
        cout << "Enter 2 check out window" << endl;
        if (player->getClownStatus()) {
            cout << "Enter 3 KILL the clown" << endl;
        }
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
                        cout << "Unable to open the window..." << endl;
                    }
                }
            }
        }else if(userChoice == 3 && player->getClownStatus()){
            if (player->getSledgehammer() ) {
                cout << "\nYou slowly sneak up on the sleeping clown with your sledgehammer ";
                cout << "raised. Holding your breath and trying not to make a sound. Then ";
                cout << "you repeatedly strike the clown in the head. The clown is now dead!" << endl;
                player->killedClown();  //clown is dead
                
            }else{
                cout << "\nYou attack the clown with your bare hands but all this does is wake ";
                cout << "the clown up and he kills you!" << endl;
                player->dies();
                return 9;               //Player dies
            }
        }
    }
    return 1;   //Leave Room
}