/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/22/2015
 ** Description: Item class
 *****************************************************************************************/

#include "Item.hpp"

//************************************************************************
//Constructors
//************************************************************************
Item::Item(){
    this->name = "";
    this->unit = "";
    this->quantity = 0;
    this->price = 0.0;
}

Item::Item(string name, string unit, int quantity, double price){
    this->name = name;
    this->unit = unit;
    this->quantity = quantity;
    this->price = price;
}
//************************************************************************
//This method returns the total prices for this item
//************************************************************************
double Item::extendedPrice(){
    return quantity * price;
}