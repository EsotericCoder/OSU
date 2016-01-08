/******************************************************************************************
 ** Author: William Kim
 ** Date: 11/15/2015
 ** Description: Game class
 *****************************************************************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//Game class is where the game will be played. It will determine who is the winner
//loser, or draw. Also it will output who won the GAME.
class Game
{
public:
    
    //Initialize
    int player1roll;
    int player2roll;
    int player1win;
    int player2win;
    
    //The Play method will loop the user selected amount of games and call Die or
    //Loaded die. Then it will determine the winner, loser, or draw.
    void play(int numGames, int sides, string player1Die, string player2Die){
        
        Die die;
        LoadedDie loaded;
        
        //Loop that plays each game
        for (int i = 0; i < numGames; i++) {
            
            //Determines winner, loser, or draw for the rounds
            if(player1Die == "L" && player1Die =="L"){
                player1roll = loaded.printNumber(sides);
                player2roll = loaded.printNumber(sides);
            }else if(player1Die == "L" && player1Die == "D"){
                player1roll = loaded.printNumber(sides);
                player2roll = die.printNumber(sides);
            }else if(player1Die == "D" && player1Die == "D"){
                player1roll = die.printNumber(sides);
                player2roll = die.printNumber(sides);
            }else if(player1Die == "D" && player1Die == "L"){
                player1roll = die.printNumber(sides);
                player2roll = loaded.printNumber(sides);
            }
            
            //Output the round results
            cout << "Game: " << i+1 << endl;
            cout << "Player 1 rolled :" << player1roll << endl;
            cout << "Player 2 rolled :" << player2roll << endl;
            
            if(player1roll > player2roll){
                player1win++;
                cout << "Player 1 wins this round." << endl;
            }else if(player2roll > player1roll){
                player2win++;
                cout << "Player 2 wins this round." << endl;
            }else{
                cout << "This round was a Draw." << endl;
            }
            
            
        
        }
        
        //Determines the game winner, loser, or draw
        if(player1win > player2win){
            cout << "Player 1 Wins the GAME." << endl;
        }else if(player2win > player1win){
            cout << "Player 2 Wins the GAME." << endl;
        }else if(player1win == player2win){
            cout << "Game is a Draw." << endl;
        }
        
        cout << "Player 1 has " << player1win << "wins." << endl;
        cout << "Player 2 has " << player2win << "wins." << endl;
    }
    
    
    
    

};

int main()
{

    srand(time(0));
    //Initialize Variables
    int sidesinput;
    int rollnumber;
    string player1Die;
    string player2Die;

    //Prompt user
    cout << "please enter an integer number for sides of the die:" << endl;
    cin >> sidesinput;
    

    cout << "please enter an integer number for number of rolls:" << endl;
    cin >> rollnumber;

    
    cout << "Player 1 die selection, D for normal die and L for loaded die: " << endl;
    cin >> player1Die;
    
    cout << "Player 2 die selection, D for normal die and L for loaded die: " << endl;
    cin >> player2Die;
    
    //Create Instance of Game and then call play
    Game game;
    game.play(rollnumber, sidesinput, player1Die, player2Die);



}
