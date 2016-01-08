/******************************************************************************************
 ** Author: William Kim
 ** Date: 7/26/2015
 ** Description: Line segments header
 *****************************************************************************************/

#ifndef _LineHeader_hpp
#define _LineHeader_hpp
#include "Point.hpp"

class LineSegment
{
private:
    Point p1;
    Point p2;
public:
    LineSegment(Point first, Point second);
    void setEnd1(Point one);
    void setEnd2(Point two);
    Point getEnd1();
    Point getEnd2();
    double length();
    double slope();
};

#endif
