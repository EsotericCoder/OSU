/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Hallway Class
 ************************************************************************/

#include "Hallway.hpp"

Hallway::Hallway(Player *p)
{
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;
}

int Hallway:: option(){
    int userChoice = 0;
    
    //Hallway menu choice
    while (!(userChoice == 1||userChoice==2||userChoice==3||userChoice ==4)) {
        int closetChoice = 0;
        cout << "\n-Hallway-\n" << endl;
        cout << "Enter 1 to enter Bedroom One" << endl;
        cout << "Enter 2 to enter Bedroom Two" << endl;
        cout << "Enter 3 to enter Kitchen" << endl;
        cout << "Enter 4 to enter Living Room" << endl;
        cout << "Enter 5 to check the Closet" << endl;
        cin >> userChoice;
        //Closet menu choice
        if(userChoice == 5 && !player->getSledgehammer()){
            while (closetChoice != 2) {
                cout << "\nThere is a sledgehammer in the closet!" << endl;
                cout << "Enter 1 to pick up the sledgehammer" << endl;
                cout << "Enter 2 to close closet" << endl;
                cin  >> closetChoice;
                if (closetChoice == 1) {
                    player->addItem("sledgehammer");
                    cout << "Sledgehammer added to backpack" << endl;
                    closetChoice = 2;
                }else if(closetChoice == 2){
                    cout << "Closing closet door" << endl;
                }
            }
        }else if(userChoice == 5 && player->getSledgehammer()){
            cout << "\nCloset is empty, closing closet door." << endl;
        }
        
    }
    if (userChoice == 1) {
        return 1;                               //Return 1 for Space 1
    }else if (userChoice == 2){
        return 2;                               //Return 2 for Space 2
    }else if (userChoice == 3){
        return 3;                               //Return 3 for Space 3
    }else{
        return 4;                               //Return 4 for Space 4
    }
}