/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/22/2015
 ** Description: List class
 *****************************************************************************************/

#include "List.hpp"



//************************************************************************
//This method will add a new item
//************************************************************************
void List::addItem(string name, string unit, int quantity, double price){
    if (itemcount == 0) {
        items[itemcount] = Item(name, unit, quantity, price);
        itemcount++;
        cout << "Item was added successfully!" << endl;
    }else{
        bool notAdded = true;
        for (int i = 0; i < itemcount; i++) {
            if(items[i].getName() == name && notAdded) {
                notAdded = false;
                cout << name << " was already added to the list. Please try again." << endl;
            }else if (notAdded){
                items[itemcount] = Item(name, unit, quantity, price);
                itemcount++;
                notAdded = false;
                cout << "Item was added successfully!" << endl;
            }
        }
    }
}

//************************************************************************
//This method will take a item name and loop through the list to find it and delete
//************************************************************************
void List::removeItem(string name){
    for (int i = 0;i < itemcount; i++) {
        if(items[i].getName() == name){
            items[i].setName("");
            items[i].setUnit("");
            items[i].setQuantity(0);
            items[i].setPrice(0.0);
        }
    }
}

//************************************************************************
//This method will display all the items in the list and the total
//************************************************************************
void List::display(){
    cout << "Grocery List: " << endl;
    cout << fixed << showpoint << setprecision(2);
    double total = 0.0; // total counter
    //Loop throught and display each item
    for (int i = 0; i < itemcount; i++) {
        if (items[i].getName() != "") {     // If statement to skip empty array elements
            cout << "Item: " << items[i].getName() << " , Quantity: " << items[i].getQuantity();
            cout << " " << items[i].getUnit() << " , Price: " << items[i].getPrice();
            cout << ", Extended Price: "<< items[i].extendedPrice()<< endl;
            total += items[i].extendedPrice();   // Calculate total cost of all goods
        }
    }
    cout << "Total: " << total << endl;             // Display total
}

//************************************************************************
// Overloaded operator == *
//************************************************************************
bool operator==(string a, string b)
{
    return a == b;
}


int main(){
    
    int userSelection = 0;
    int menuSelection = 0;
    
    do{
        cout << "Welcome to Will's Grocery Store" << endl;
        cout << "- Enter 1 to create a new shopping list." << endl;
        cout << "- Enter 2 to exit" << endl;
        cin >> userSelection;
    }while(userSelection != 1 && userSelection !=2);
    
    if (userSelection == 1) {
        List list;
        do{
            cout << "- Enter 1 to add a new item" << endl;
            cout << "- Enter 2 to delete a item" << endl;
            cout << "- Enter 3 to display list" << endl;
            cout << "- Enter 4 to quit" << endl;
            cin >> menuSelection;
        
            if (menuSelection == 1) {
                string name = "";
                string unit = "";
                int quantity = 0;
                double price = 0.0;
                cin.ignore();
                cout << "Enter item name: ";
                getline(cin,name);
                cout << endl << "Enter unit: ";
                cin >> unit;
                cout << endl << "Enter quanitity: ";
                cin >> quantity;
                cout << endl << "Enter price: ";
                cin >> price;
                cout << endl;
                list.addItem(name,unit, quantity,price);

            }else if (menuSelection == 2) {
                string name;
                cin.ignore();
                cout << "Enter the item name you would like to remove: ";
                getline(cin,name);
                cout << endl;
                list.removeItem(name);
                cout << "Item has been removed." << endl;
            
            }else if (menuSelection == 3){
                list.display();
            }
        }while (menuSelection != 4);
        
    }
    
}
