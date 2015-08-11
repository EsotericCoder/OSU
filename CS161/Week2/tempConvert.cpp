/*****************************************************************************
 * Author: William Kim
 * Date: 7/4/15
 * Description: This program converts Celsius into Fahrenheit
 * **************************************************************************/

#include<iostream>

using namespace std;

int main(){

	//Intialize variable
	double celsius, fahrenheit;

	//Output and input for Celsius temp
	cout << "Please enter a Celsius temperature.\n";
	cin >> celsius;
	
	//Calculate Celsius to Fahrenheit
	fahrenheit = ((9.0/5.0) * celsius) + 32;

	//Output Fahrenheit temp
	cout << "The equivalent Fahrentheit temperature is: \n";
	cout << fahrenheit << "\n";

}
