/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Filter header
 *****************************************************************************************/

#ifndef Filter_hpp
#define Filter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Filter
{
public:
    Filter();
    void doFilter(ifstream &in, ofstream &out);
    virtual char transform( char ch ) = 0;
};

#endif /* Filter_hpp */
