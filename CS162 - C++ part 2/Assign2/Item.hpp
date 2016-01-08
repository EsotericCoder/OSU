/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/22/2015
 ** Description: Item header file
 *****************************************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Item
{
    string name;            //item name
    string unit;            //i.e. can, box, pounds, or ounces
    int quantity;           //number to buy
    double price;           //unit price
    
    public :
    Item();
    Item(string name, string unit, int quantity, double price);
    string getName(){ return name; };
    string getUnit(){ return unit; };
    int getQuantity(){ return quantity; };
    double getPrice(){ return price; };
    
    void setName(string name){ this->name = name;};
    void setUnit(string unit){ this->unit = unit;};
    void setQuantity(int quantity){ this->quantity = quantity; };
    void setPrice(double price){this->price = price; };
    double extendedPrice();
    
}; //End Item Class

#endif /* Item_hpp */
