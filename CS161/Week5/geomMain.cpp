
#include "geomMain.h"
#include "LineSegment.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;
int main()
{
    cout << "This is an example of point" << endl;
    Point p1(-1.5, 0.0);
    Point p2(1.5, 4.0);
    double dist = p1.distanceTo(p2);
    cout << dist << endl;
    
    Point p3(4.3, 7.52);
    Point p4(-17.0, 1.5);
    LineSegment ls1(p3, p4);
    double length = ls1.length();
    double slope = ls1.slope();
    
    cout << "Length: " << length << endl;
    cout << "Slope: " << slope << endl;
    return 0;
};