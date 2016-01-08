/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Upper header
 *****************************************************************************************/

#ifndef Upper_hpp
#define Upper_hpp

#include <stdio.h>
#include "Filter.hpp"

class Upper : public  Filter
{
public:
    Upper();
    char transform( char ch );
    
};

#endif /* Upper_hpp */
