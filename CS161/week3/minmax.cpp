/********************************************************************
 * Author:William Kim
 * Date:7/12/15
 * Description: This program finds the min and max
 * *****************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//Initialize
	int counter, input, num, min, max;
	counter = 0;
	//Prompt user 
	cout << "How many integers would you like to enter?" << endl;
	cin >> input;
	cout << "Please enter " << input << " integers." << endl;
	//While loop to get number and determine min and max
	while(input > counter)
	{
		cin >> num;
		if(counter == 0){
			min = num;
			max = num;
		}else if(num > max){
			max = num;
		}else if(num < min){
			min = num;
		}
		counter++;
	}
	//Output min and max
	cout << "Min: " << min << "\nMax: " << max << endl;
	return 0;
}



