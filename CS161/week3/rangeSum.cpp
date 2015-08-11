/********************************************************************
 * Author:William Kim
 * Date:7/12/15
 * Description:This program finds the sum of the values in the range
 * of two numbers
 * *****************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//Initialize
	int num1, num2, sum;
	//Prompt user and get input
	cout << "Please enter two integers." << endl;
	cin >> num1;
	cin >> num2;
	//If-else to determine sum
	if(num1 == num2)
	{
		sum = num1;
	}else if(num1 > num2){
		while(num2<=num1)
		{
			sum += num2;
			num2++;
		}
	}else{
		while(num1<=num2)
		{
			sum += num1;
			num1++;
		}
	}
	//Output message
	cout << "The some of the values in that range is:\n" << sum << endl; 
	return 0;
}
