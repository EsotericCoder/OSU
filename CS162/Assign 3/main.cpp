/************************************************************************
 ** Author: William Kim
 ** Date: 11/8/2015
 ** Description: Main Class
 ************************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Goblin.hpp"
#include "BlueMen.hpp"
#include "TheShadow.hpp"
#include "ReptilePeople.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;


int main()
{
    srand ( time(NULL) );
    
    Barbarian *barb1 = new Barbarian();
    Barbarian *barb2 = new Barbarian();
    Goblin *gob1 = new Goblin();
    Goblin *gob2 = new Goblin();
    BlueMen *man1 = new BlueMen();
    BlueMen *man2 = new BlueMen();
    TheShadow *ghost1 = new TheShadow();
    TheShadow *ghost2 = new TheShadow();
    ReptilePeople *rep1 = new ReptilePeople();
    ReptilePeople *rep2 = new ReptilePeople();
    
    
    //Barbarian 1 attacks Barbarian 2
    cout << "Barbarian 1 vs Barbarian2" << endl;
    int damage = 0;
    int barb1attack = barb1->attack();
    cout << "ATTACK: " << barb1attack << endl;
    int barb2defense = barb2->defense();
    cout << "DEFENSE: " << barb2defense << endl;
    barb1attack = barb1attack - barb2defense;
    if (barb1attack > 0) {
        int barb2armor = barb2->getArmor();
        cout << "DEFENDERS ARMOR: " << barb2armor << endl;
        int barb2strength = barb2->getStrength();
        cout << "DEFENDERS STRENGTH: " << barb2strength << endl;
        if(barb1attack > barb2armor){
            barb1attack = barb1attack - barb2armor;
            cout << "Damage to strength " << barb1attack << endl;
            
        }
        if (barb2defense > 0) {
            damage = barb2strength - barb1attack;
            barb2->setStrength(damage);
            cout << "Barb 2 was damaged new strength is " << damage << endl;
        }else{
            cout << "Barb 2 is dead" << endl;
        }
    }else{
        cout << "No damage occured" << endl;
    }

    
    
    
}