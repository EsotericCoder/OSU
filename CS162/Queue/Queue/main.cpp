/*****************************************************
 ** Author: William Kim
 ** Date: 11/18/2015
 ** Description: main Class
 *****************************************************/

#include <stdio.h>
#include "Queue.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    //Initialize
    Queue *q = new Queue();
    int menuChoice = 0;
    
    do{
        //Menu choices
        cout << "Enter 1 to Enter a Value" << endl;
        cout << "Enter 2 to Remove a Value" << endl;
        cout << "Enter 3 to Display the Queue" << endl;
        cout << "Enter 4 to Quit Program" << endl;
        cin >> menuChoice; //User menu selection
        
        //Add to queue
        if (menuChoice == 1) {
            int number = -1;
            //input validation
            while (number < 0) {
                cout << "\nEnter a positive integer: ";
                cin >> number;
            }
            //Add to queue
            cout << "Adding " << number << " to queue.\n" << endl;
            q->addBack(number);
            
            //Remove from queue
        }else if(menuChoice ==2){
            int removed = q->getFront();
            if (removed >= 0) {
                cout << "\n" << removed << " was removed from queue." << endl;
                q->removeFront();
            }else{
                cout << "Queue is Empty." << endl;
            }
            
            
            //Display queue
        }else if(menuChoice == 3){
            int output = 0;
            //Loop to output until sentinel is reached
            while (output >= 0) {
                output = q->getFront();
                //output
                if (output >= 0) {
                    q->removeFront();
                    cout << output << " ";
                }
                
            }
            cout << endl;
        }
        
    }while( menuChoice != 4 );
    
    return 0;
    
}