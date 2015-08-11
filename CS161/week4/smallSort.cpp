/********************************************************************
 * Author: William Kim
 * Date: 7/19/2015
 * Description: This function sorts a set of numbers
 * ****************************************************************/

using namespace std;

void smallSort(int &a, int &b, int &c)
{
	int tempHolder;
	if(a < b){	
		if(b < c){
			//Do nothing
		}else if(c > a){
			tempHolder = c;
			c = b;
			b = tempHolder;
		}else if(c < a){
			tempHolder = a;
			a = c;
			c = b;
			b = tempHolder;
		}
	}else if(b < a){
		if(c > a){
			tempHolder = a;
			a = b;
			b = tempHolder;
		}else if(c < b){
			tempHolder = a;
			a = c;
			c = tempHolder;
		}else if(c > b){
			tempHolder = a;
			a = b;
			b = c;
			c = tempHolder;
		}			
	}
}

