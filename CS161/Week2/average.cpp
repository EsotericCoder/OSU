/*****************************************************************************
 * Author: William Kim
 * Date: 7/04/2015
 * Description: This program takes five numbers for users and computes 
 *              the average.
 ****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//Initiate the average
	double one, two, three, four, five, average;

	cout << "Please enter five numbers.\n";

	//Stores user inputs
	cin >> one;
	cin >> two;
	cin >> three;
	cin >> four;
	cin >> five;

	cout << "The average of those numbers is: ";

	//Calculate the average
	average = (one + two + three + four + five)/5;

	cout << average << "\n";
}	              
