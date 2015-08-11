/********************************************************************
 * Author: William Kim
 * Date: 7/19/2015
 * Description: This function demonstrates the hailstone sequence
 * *****************************************************************/

using namespace std;

int hailstone(int x)
{
	int counter = 0;
	bool isOne = false;

	while(!isOne)
	{
		if(x==1)
			isOne = true;
		else if(x % 2 == 0){
			x = x / 2;
			counter++;
		}else{
			x = ( x * 3 ) + 1;
			counter++;
		}
	}	
	return counter;
}
