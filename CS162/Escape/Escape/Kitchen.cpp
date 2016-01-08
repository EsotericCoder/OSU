/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: Kitchen Class
 ************************************************************************/

#include "Kitchen.hpp"

Kitchen::Kitchen(Player *p)
{
    space1 = NULL;
    space2 = NULL;
    space3 = NULL;
    space4 = NULL;
    player = p;
}

int Kitchen::option(){
    int userChoice = 0;
    while (!(userChoice == 1||userChoice==2)) {
        int fridgeChoice = 0;
        //Kitchen Main menu
        cout << "\n-Kitchen-\n" << endl;
        cout << "Enter 1 to enter Hallway" << endl;
        cout << "Enter 2 to enter Living Room" << endl;
        cout << "Enter 3 to check Refridgerator" << endl;
        cin >> userChoice;
        //Refridgerator Menu
        if(userChoice == 3){
            while (fridgeChoice != 2) {
                int headChoice = 0;
                cout << "\nThere is a severed head in refridgerator!\n" << endl;
                cout << "Enter 1 inspect severed head" << endl;
                cout << "Enter 2 to close Refridgerator" << endl;
                cin  >> fridgeChoice;
                //Severed Head menu
                if (fridgeChoice == 1 && !player->getKey()) {
                    while (headChoice != 1) {
                        if (!player->getKey()) {
                            cout << "\nThere is a Key hidden in the mouth!" << endl;
                            cout << "Enter 1 to put head back" << endl;
                            cout << "Enter 2 to take the key" << endl;
                        }
                        cin >> headChoice;
                        if (headChoice == 2 && !player->getKey()) {
                            player->addItem("key");
                            cout << "Key added to backpack" << endl;
                            headChoice = 1;
                        }
                    }
                }else if (fridgeChoice == 1 && player->getKey()){
                    cout << "\nSevered head is empty!\n" << endl;
                }else if(fridgeChoice == 2){
                    cout << "Closing refridgerator\n" << endl;
                }
            }
        }
        
    }
    if (userChoice == 1) {
        return 1;                   //return 1 for Space 1
    }else{
        return 2;                   //return 2 for Space 2
    }
}