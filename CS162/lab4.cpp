/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/22/2015
 ** Description: lab4 class
 *****************************************************************************************/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*This method reverses a string by first check if there is a string. If the strings
length is 0 then outputs a newline. Else, outputs the last character of the string and
then calls substring of the input string and leaves out the last character. Then is
calls the same method again with the new string.*/
string rev(string s)
{
    
    if( s.length() == 0){
        cout << endl;
    }else{
        cout << s[s.length()-1];
        s = s.substr(0,s.length()-1);
        rev(s);
    }
    return "";
}

/*This method takes in a int vector and the vector length. If the vector length is 0  
 it stops and returns 0. Else, the vector pops the last integer and adds it to the sum.
 Then deletes the last number and calls the method over again until the length is 0.
 */
int sum(vector<int> array, int arrayLength)
{
    if(arrayLength == 0){
        return 0;
    }else{
        int s = array.back();
        array.pop_back();
        s += sum(array, arrayLength-1);
        return s;
    }
}

/*This method take an int for the number of rows and its base case is 1. It just recursively
 adds each row until it reachs 0 which returns 0.*/
int triangle(int rows)
{
    if(rows < 1){
        return 0;
    }else{
        int s = rows;
        s += triangle(rows - 1);
        return s;
    }
}


int main()
{
    //Initialize variables
    string userInput = "";
    string userDecision = "";
    int userNumber1 = 0;
    int rows = 0;
    int count = 0;
    int menuSelect = 0;
    vector<int> array;

    
    do{
        cout << "Enter 1 to Reverse a String" << endl;
        cout << "Enter 2 to Find the Sum of an Array" << endl;
        cout << "Enter 3 to Find the Sum of a Triangle" << endl;
        cout << "Enter 4 to Exit" << endl;
        cin >> menuSelect;
        
        if(menuSelect == 1){
            //This section of code prompts user to enter a string to reverse and then outputs a reverse.
            cin.ignore();
            cout << "Please enter a string to reverse: ";
            getline(cin, userInput);
            cout << endl << "Reversed: " << rev(userInput) << endl;
        }else if(menuSelect == 2){
            //This section of code prompts users for integers and finds the sum.
            do{
                cout << "Please enter an integer: ";
                cin >> userNumber1;
                array.push_back(userNumber1);
                count++;
                cout << endl << "Enter 'y' if you would like to add another number, or else press enter: ";
                cin >> userDecision;
                cout << endl;
            }while(userDecision == "y");
            
            cout << "The sum = " << sum(array, count) << endl;
        }else if(menuSelect == 3){
            //This section prompts the user for an integer for the number of rows in a triangle
            cout << "Enter the number of rows for the triangle: ";
            cin >> rows;
            cout << endl << "Sum of all items in triangle : " << triangle(rows) << endl;
            cout << "There were " << rows << " rows" << endl;
        }
    }while (menuSelect != 4);
    
}