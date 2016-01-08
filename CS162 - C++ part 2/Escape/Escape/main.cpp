/************************************************************************
 ** Author: William Kim
 ** Date: 12/06/2015
 ** Description: main Class
 ************************************************************************/

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Space.hpp"
#include "BedroomOne.hpp"
#include "BedroomTwo.hpp"
#include "Hallway.hpp"
#include "Kitchen.hpp"
#include "LivingRoom.hpp"
#include <time.h>

int main() {
    //Initialize the House
    Player *p = new Player();
    BedroomOne *b1 = new BedroomOne(p);
    BedroomTwo *b2 = new BedroomTwo(p);
    Hallway *h = new Hallway(p);
    Kitchen *k = new Kitchen(p);
    LivingRoom *lr = new LivingRoom(p);
    Space *currentRoom = b1;
    b1->addSpace(h, NULL, NULL, NULL);
    b2->addSpace(h, NULL, NULL, NULL);
    k->addSpace(h, lr, NULL, NULL);
    lr->addSpace(h, k, NULL, NULL);
    h->addSpace(b1, b2, k, lr);
    int userChoice = 0;
    int roomChoice = 0;
    time_t now, start;
    double seconds = 0;
    
    // Starting menu
    while (userChoice != 1) {
        //Intro
        cout << "---ESCAPE---" << endl;
        cout << "Enter 1 to start the game" << endl;
        cout << "Enter 2 to see HINT" << endl;
        cin >> userChoice;
        if (userChoice == 2) {
            cout << "\n*HINT*\nTo win the game you must find the key in the severed ";
            cout << "head or smash open the window with a sledgehammer. You have 60 ";
            cout << "seconds.\n" << endl;
        }
    }
    time(&start);                             //Start time
    
    //The Beginning
    cout << "\nYou suddenly wake up. The last thing you remember was walking home ";
    cout << "when you noticed a creepy clown running up and you and knocking you out.\n" << endl;
    
    //Loop the game
    while (roomChoice != 10 && roomChoice != 9 && seconds <= 60) {
        roomChoice = currentRoom->option();
        if (roomChoice == 1 || roomChoice == 2 || roomChoice == 3 || roomChoice == 4) {
            currentRoom = currentRoom->getSpace(roomChoice);
        }
        time(&now);                           //Current time
        seconds = difftime(now, start);       //How many seconds have passed
    }
    
    //The End
    if (roomChoice == 9) {
        cout << "\nYou Lose!" << endl;
    }else if(roomChoice == 10){
        cout << "\nYOU ESCAPED! CONGRATS!" << endl;
    }else{
        cout << "\nThe clown woke up and killed you!\nYou Lose!"<< endl;
    }
    
    
    
    
}
