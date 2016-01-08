/************************************************************************
 ** Author: William Kim
 ** Date: 11/20/2015
 ** Description: Game Class
 ************************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Goblin.hpp"
#include "BlueMen.hpp"
#include "TheShadow.hpp"
#include "ReptilePeople.hpp"
#include "Queue.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Game
{
    
public:
    //Initialize
    Queue *player1;
    Queue *player2;
    Queue *losers;
    int numOfCreatures;
    int p1lose;
    int p2lose;
    int roundCount;
    
    struct winner {
        int team;
        string name;
        string creature;
    };

    winner *firstPlace;
    winner *secondPlace;
    winner *thirdPlace;
    
    Game(){
        player1 = new Queue();
        player2 = new Queue();
        losers = new Queue();
        firstPlace = new winner();
        secondPlace = new winner();
        thirdPlace = new winner();
        numOfCreatures = 0;
        p1lose = 0;
        p2lose = 0;
        roundCount = 1;
    }
    
    void intro(){
        //Prompt user for number of fighters
        cout << "Enter the number of fighters: ";
        cin >> numOfCreatures;
        cout << endl;
    }
    
    void lineup(int player){
        for (int i = 0; i < numOfCreatures; i++) {
            
            int creatureSelection = 0;
            string fightersName = "";
            
            cout << "Player " << player << " Character " << i+1 << " Selection" << endl;
            cout << "1. Barbarian" << endl;
            cout << "2. Blue Men" << endl;
            cout << "3. Goblin" << endl;
            cout << "4. Reptile People" << endl;
            cout << "5. The Shadow" << endl;
            cin >> creatureSelection;
            cout << "\nFighters name: ";
            cin >> fightersName;
            cout << "\n" << endl;
            
            switch (creatureSelection) {
                case 1:
                {
                    Barbarian *barb = new Barbarian();
                    if (player == 1) {
                        player1->add(fightersName, "Barbarian", barb);
                    }else if(player ==2){
                        player2->add(fightersName, "Barbarian", barb);
                    }
                    break;
                }
                case 2:
                {
                    BlueMen *blueMen = new BlueMen();
                    if (player == 1) {
                        player1->add(fightersName, "Blue Men", blueMen);
                    }else if (player == 2){
                        player2->add(fightersName, "Blue Men", blueMen);
                    }
                    break;
                }
                case 3:
                {
                    Goblin *goblin = new Goblin();
                    if (player == 1) {
                        player1->add(fightersName, "Goblin", goblin);
                    }else if (player == 2){
                        player2->add(fightersName, "Goblin", goblin);
                    }
                    break;
                }
                case 4:
                {
                    ReptilePeople *rep = new ReptilePeople();
                    if (player == 1) {
                        player1->add(fightersName, "Reptile People", rep);
                    }else if (player == 2){
                        player2->add(fightersName, "Reptile People", rep);
                    }
                    break;
                }
                case 5:
                {
                    TheShadow *shadow = new TheShadow();
                    if (player == 1) {
                        player1->add(fightersName, "Shadow", shadow);
                    }else if (player == 2){
                        player2->add(fightersName, "Shadow", shadow);
                    }
                    break;
                }
                    
            }
        }
    }
    
    void battle(){
        int turn = 0; //Players turn selection
        
        //Loop until one players lineup is completely defeated
        while (p1lose < numOfCreatures && p2lose < numOfCreatures) {
            Creature *player1fighter = player1->front->creature;
            Creature *player2fighter = player2->front->creature;
            
            cout << "Round - " << roundCount << endl;
            cout << "Player 1 Fighter - Name: " << player1->front->name << "; ";
            cout << "Creature: " << player1->front->creatureType << endl;
            cout << "Player 2 Fighter - Name: " << player2->front->name << "; ";
            cout << "Creature: " << player2->front->creatureType << endl;
            
            //Fight until one fighter dies
            while (player1fighter->getStrength() > 0 && player2fighter->getStrength() > 0) {
                int attack = 0;
                int armor = 0;
                int defense = 0;
                int strength = 0;
                
                //Player 1's turn
                if (turn == 0) {
                    attack = player1fighter->attack();
                    defense = player2fighter->defense();
                    attack = attack - defense;
                    
                    //if attack will do more damage then opponents defense get armor and strenght
                    if(attack > 0){
                        armor = player2fighter->defense();
                        strength = player2fighter->getStrength();
                        
                        //if attack can get past armor, do damage
                        if(attack > armor){
                            attack = attack - armor;
                            strength = strength - attack;
                            //set opponents new strenght after attack
                            player2fighter->setStrength(strength);
                            // if Player 2's character dies then move them to loser pile
                            // and place Player 1's character back in the lineup and regenerate
                            // health
                            if (strength <= 0) {
                                losers->addBack(player2->front);
                                player2->remove();
                                player1fighter->regenerate();
                                //Place winner
                                if (firstPlace->creature == "") {
                                    firstPlace->name = player1->front->name;
                                    firstPlace->creature = player1->front->creatureType;
                                    firstPlace->team = 1;
                                }else if(secondPlace->creature == ""){
                                    secondPlace->name = player1->front->name;
                                    secondPlace->creature = player1->front->creatureType;
                                    secondPlace->team = 1;
                                }else if(thirdPlace->creature == "" && numOfCreatures > 2){
                                    thirdPlace->name = player1->front->name;
                                    thirdPlace->creature = player1->front->creatureType;
                                    thirdPlace->team = 1;
                                }
                                player1->addBack(player1->front);
                                player1->remove();
                                cout << "Player 1 wins\n" << endl;
                                p2lose++;
                                roundCount++;
                            }
                        }
                        
                    }
                    turn = 1;
                    
                //Player 2's turn
                }else if (turn == 1){
                    attack = player2fighter->attack();
                    defense = player1fighter->defense();
                    attack = attack - defense;
                    
                    //if attack will do more damage then opponents defense get armor and strenght
                    if(attack > 0){
                        armor = player1fighter->defense();
                        strength = player1fighter->getStrength();
                        
                        //if attack can get past armor, do damage
                        if(attack > armor){
                            attack = attack - armor;
                            strength = strength - attack;
                            //set opponents new strenght after attack
                            player1fighter->setStrength(strength);
                             
                            // if Player 1's character dies then move them to loser pile
                            // and place Player 2's character back in the lineup and regenerate
                            // health
                            if (strength <= 0) {
                                losers->addBack(player1->front);
                                player1->remove();
                                player2fighter->regenerate();
                                //Place winner
                                if (firstPlace->creature == "") {
                                    firstPlace->name = player2->front->name;
                                    firstPlace->creature = player2->front->creatureType;
                                    firstPlace->team = 2;
                                }else if(secondPlace->creature == ""){
                                    secondPlace->name = player2->front->name;
                                    secondPlace->creature = player2->front->creatureType;
                                    secondPlace->team = 2;
                                }else if(thirdPlace->creature == "" && numOfCreatures > 2){
                                    thirdPlace->name = player2->front->name;
                                    thirdPlace->creature = player2->front->creatureType;
                                    thirdPlace->team = 2;
                                }
                                player2->addBack(player2->front);
                                player2->remove();
                                cout << "Player 2 wins\n" << endl;
                                p1lose++;
                                roundCount++;
                            }
                        }
                    }
                    turn = 0;
                }
            }
        }
        
    }
    
    
    //Determines the winner or loser
    void printWinner(){
        if (p1lose < p2lose) {
            cout << "Player 1 Wins the Tournament!\n" << endl;
        }else{
            cout << "Player 2 Wins the Tournament!\n" << endl;
        }
    }
    
    //Print first, second, and thirdplace
    void printFinal(){
        if(firstPlace->creature != ""){
            cout << "FIRST PLACE - name: " << firstPlace->name << " team: " << firstPlace->team << " creature: " << firstPlace->creature << endl;
        }
        if (secondPlace->creature != "") {
            cout << "SECOND PLACE - name: " << secondPlace->name << " team: " << secondPlace->team << " creature: " << secondPlace->creature << endl;
        }
        if (thirdPlace->creature != "") {
            cout << "THIRD PLACE - name: " << thirdPlace->name << " team: " << thirdPlace->team << " creature: " << thirdPlace->creature << endl;
        }
        cout << "\n" << endl;
    }
    
    //Prints out loser pile
    void printLoser(){
        cout << "GAME LOSERS" << endl;
        for (int i = 0; i < (p1lose + p2lose); i++) {
            cout << "Name: " << losers->front->name << " Creature: " << losers->front->creatureType << endl;
            losers->remove();
        }
        cout << "\n" << endl;
    }
    
};




int main()
{
    srand((int)time(NULL));
    
    Game *game = new Game();
    game->intro();
    game->lineup(1);
    game->lineup(2);
    game->battle();
    game->printFinal();
    game->printLoser();
    game->printWinner();
}