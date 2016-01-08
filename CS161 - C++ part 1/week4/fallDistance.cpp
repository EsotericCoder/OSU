/********************************************************************
*Author: William Kim
*Date: 7/19/2015
*Description: This function calculates the distance an object falls
********************************************************************/
using namespace std;

double fallDistance(int seconds)
{
	const double GRAVITY = 9.8;
	double distance = (1.0/2.0) * GRAVITY * (seconds * seconds);
	return distance;
}
