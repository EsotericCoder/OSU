/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Encryption header
 *****************************************************************************************/

#ifndef Encryption_hpp
#define Encryption_hpp

#include <stdio.h>
#include "Filter.hpp"

class Encryption : public  Filter
{
private:
    int key;
public:
    Encryption(int userKey);
    char transform( char ch );
    
};

#endif /* Encryption_hpp */
