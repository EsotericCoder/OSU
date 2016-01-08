/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/22/2015
 ** Description: List Header
 *****************************************************************************************/

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "Item.hpp"

using namespace std;

class List
{
    private:
    int itemcount;
    Item items[100];
    
    public :
    List(){
        this->itemcount = 0;
    };
    void addItem(string, string, int, double);
    void removeItem(string);
    void display();
    friend bool operator==(Item a, string b);
}; //End List Class

#endif /* List_hpp */
