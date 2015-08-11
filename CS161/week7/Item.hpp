/******************************************************************************************
 ** Author: William Kim
 ** Date: 8/9/2015
 ** Description: Item header file
 *****************************************************************************************/

#ifndef _Item_hpp
#define _Item_hpp
#include <string>
using namespace std;
class Item
{
    private:
        string name;
        double price;
        int quantity;
    public:
    Item();
    Item(string newName, double newPrice, int newQuantity);
    void setName(string newName);
    void setPrice(double newPrice);
    void setQuantity(int quantity);
    string getName();
    double getPrice();
    int getQuantity();
    
};

#endif