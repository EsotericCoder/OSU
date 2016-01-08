/******************************************************************************************
 ** Author: William Kim
 ** Date: 8/9/2015
 ** Description: Items class 
 *****************************************************************************************/

#include "Item.hpp"
#include <string>


//Default constructor
Item::Item(){
    name = "";
    price = 0.0;
    quantity = 0;
}
//Constructor with 3 parameters
Item::Item(string newName, double newPrice, int newQuantity){
    name = newName;
    price = newPrice;
    quantity = newQuantity;
}


//Getters and Setters
void Item::setName(string newName){ name = newName; }

void Item::setPrice(double newPrice){ price = newPrice; }

void Item::setQuantity(int newQuantity){ quantity = newQuantity; }

string Item::getName(){ return name; }

double Item::getPrice(){ return price; }

int Item::getQuantity(){ return quantity; }