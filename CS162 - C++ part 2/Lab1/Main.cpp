/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/1/2015
 ** Description: Main class
 *****************************************************************************************/
#include <string>
#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"

using namespace std;

int main(){
    int numberOfRolls;
    
    cout << "Enter the number of Rolls." << endl;
    cin >> numberOfRolls;
    
    Die die = Die();
    LoadedDie loadedDie = LoadedDie();
    
    cout << "Die rolled " << numberOfRolls << " times: ";
    for(int i = 0; i < numberOfRolls; i++){
        cout << die.rollDice() << " ";
    }
    cout << endl;
    
    cout << "Loaded die rolled " << numberOfRolls << " times: ";
    for(int i = 0; i < numberOfRolls; i++){
        cout << loadedDie.rollLoadedDice() << " ";
    }
    cout << endl;
    
    return 0;
}
