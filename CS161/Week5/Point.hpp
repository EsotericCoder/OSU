/******************************************************************************************
 ** Author: William Kim
 ** Date: 7/26/2015
 ** Description: Point header file
 *****************************************************************************************/

#ifndef _Point_hpp
#define _Point_hpp

class Point
{
private :
    double x;
    double y;
public :
    Point();
    Point(double xNum, double yNum);
    void setXCoord(double xNum);
    void setYCoord(double yNum);
    double getXCoord();
    double getYCoord();
    double distanceTo(Point p2);
};

#endif
