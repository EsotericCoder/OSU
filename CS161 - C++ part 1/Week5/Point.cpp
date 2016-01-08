/******************************************************************************************
 ** Author: William Kim
 ** Date: 7/26/2015
 ** Description: Input points and finds the distance between two points
 *****************************************************************************************/

#include <cmath>
#include "Point.hpp"
#include "LineSegment.hpp"


/***********************************************************************************
**Description: Default constructor, initializes point to (0,0)
**
***********************************************************************************/
Point::Point()
{
    x = 0;
    y = 0;
}

/***********************************************************************************
**Description: This constructor takes two doubles as a parameters and sets them to x
** and y.
***********************************************************************************/
Point::Point(double xNum, double yNum)
{
    x = xNum;
    y = yNum;
}
    
/***********************************************************************************
**Description: Sets the x coordinate
**
***********************************************************************************/
void Point::setXCoord(double xNum)
{   x = xNum; }
    
/***********************************************************************************
**Description: Sets the y coordinate
**
***********************************************************************************/
void Point::setYCoord(double yNum)
{   y = yNum; }

/***********************************************************************************
**Description: Gets the x coordinate
**
***********************************************************************************/
double Point::getXCoord()
{   return x; }
    
/***********************************************************************************
**Description: Gets the y coordinate
**
***********************************************************************************/
double Point::getYCoord()
{   return y; }
    
/***********************************************************************************
**Description: Calculates the distance from one point to another
**
***********************************************************************************/
double Point::distanceTo(Point p2)
{
    double p1x = getXCoord();
    double p1y = getYCoord();
    double p2x = p2.getXCoord();
    double p2y = p2.getYCoord();
    double distance = sqrt((p2x - p1x) * (p2x - p1x) + (p2y - p1y) * (p2y - p1y));
    return distance;
}

