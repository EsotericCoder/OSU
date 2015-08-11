/*******************************************************************
 * Author: William Kim
 * Date: 7/4/15
 * Description: This program outputs how many of each type of coin
 *		would represent that amount with the fewest total
 *		number of coins.
 *****************************************************************/

#include<iostream>

using namespace std;

int main(){
	
	//Initialize variables
	int total, quarter, dime, nickle, penny;

	//Get user input
	cout << "Please enter an amount in cents less than a dollar.\n";
	cin >> total;

	//Calculate the number of coins
	quarter = total / 25;
	total = total % 25;
	dime = total / 10;
	total = total % 10;
	nickle = total / 5;
	total = total % 5;
	penny = total / 1;

	//Output the number of coins
	cout << "Your change will be:\n";
	cout << "Q: " << quarter << "\n";
	cout << "D: " << dime << "\n";
	cout << "N: " << nickle << "\n";
	cout << "P: " << penny << "\n";

}
