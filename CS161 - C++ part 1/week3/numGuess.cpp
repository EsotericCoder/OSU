/*******************************************************************
 * Author: William Kim
 * Date: 7/12/15
 * Description: This program prompts user to guess a number
 * ****************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//Initialize variables
	int counter = 1;
	int number;
	bool correctGuess = false;
	//Prompt user and store 
	cout << "Enter the number for the player to guess." << endl;
	cin >> number;
	//While loop to keep asking until guess is correct
	while(correctGuess == false)
	{
		//if-else statement to determing the correct output
		int guess;
		cout << "Enter your guess." << endl;
		cin >> guess;
		if(guess == number)
		{
			cout << "You guess it in " << counter << " tries." << endl;
			correctGuess = true;
		}else if(guess > number){
			cout << "Too high - try again." << endl;
			counter++;
		}else{
			cout << "Too low - try again." << endl;
			counter++;
		}
	}
	return 0;
	
}
 
