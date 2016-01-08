/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Original header
 *****************************************************************************************/

#ifndef Original_hpp
#define Original_hpp

#include <stdio.h>
#include "Filter.hpp"

class Original : public Filter
{
public:
    Original();
    char transform( char ch );
    
};

#endif /* Original_hpp */
