/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Encryption class
 *****************************************************************************************/

#include "Encryption.hpp"

Encryption::Encryption(int userKey)
{
    key = userKey;
}

char Encryption::transform(char ch)
{
    return ch + key;
}