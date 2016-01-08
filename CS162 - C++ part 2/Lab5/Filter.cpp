/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: Filter class
 *****************************************************************************************/

#include "Filter.hpp"


Filter::Filter()
{
    
}

void Filter::doFilter(std::ifstream &in, std::ofstream &out)
{
    char ch;
    char transformedCh;
    out.clear();
    in.clear();
    
    in.seekg( 0L, ios::beg ); //set to beginning of doc
    in.get(ch);//get the first char
    
    //Loop until there is no more characters in doc
    while (!in.fail()) {
        transformedCh = transform(ch); //transform the character
        out.put(transformedCh); //outputs the transformed character
        in.get(ch); //gets the next character
    }
    
}