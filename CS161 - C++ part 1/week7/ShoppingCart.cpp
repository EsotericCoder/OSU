/******************************************************************************************
 ** Author: William Kim
 ** Date: 8/9/2015
 ** Description: Shopping cart class
 *****************************************************************************************/

#include "ShoppingCart.hpp"

ShoppingCart::ShoppingCart(){
    items = new Item[100]();
    arrayEnd = 0;
}

void ShoppingCart::addItem(Item* newItem){
    items[arrayEnd] = *newItem;
    arrayEnd++;
}

double ShoppingCart::totalPrice(){
    double total = 0;
    for(int i = 0; i <= arrayEnd ; i++){
        total += items[i].getPrice() * items[i].getQuantity();
    }
    return total;
}