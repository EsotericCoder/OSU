/*************************************************************************
 ** Author: William Kim
 ** Date: 11/12/2015
 ** Description: Lab 7
 *************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class SearchSort
{
public:
    SearchSort()
    {
    }
    
    /*************************************************************************
    This function performs a linear search on an array of Inventory objects, using itemCode
    as the key field. If the desired code is found, its array subscript is returned.
    Otherwise, -1 is returned.
    *************************************************************************/
    int search(const string array[], int size, string value)
    {
        int index = 0; // Used as a subscript to search array
        int position = -1; // Used to record position of search value
        bool found = false; // Flag to indicate if the value was found
        
        while (index < size && !found)
        {
            if (array[index] == value) // If the value is found
            {
                found = true; // Set the flag
                position = index; // Record the value's subscript
            }
            index++; // Go to the next element
        }
        return position; // Return the position, or -1
    }// End search
    
    /*************************************************************************
    This function performs an ascending-order bubble sort on array.
    The parameter size holds the number of elements in the array.
    *************************************************************************/
    void sortArray(int array[], int size)
    {
        int temp;
        bool swap;
        
        do
        {
            swap = false;
            for (int count = 0; count < (size - 1); count++)
            {
                if (array[count] > array[count + 1])
                {
                    temp = array[count];
                    array[count] = array[count + 1];
                    array[count + 1] = temp;
                    swap = true;
                }
            }
        }while (swap); // Loop again if a swap occurred on this pass.
    }
    
    /*************************************************************************
    This function performs a binary search on an integer array with size elements whose
    values are stored in ascending order. The array is searched for the number stored in the
    value parameter. If the number is found, its array subscript is returned. Otherwise, -1
    is returned.
    *************************************************************************/
    int binarySearch(const int array[], int size, int value)
    {
        int first = 0,      // First array element
        last = size - 1,    // Last array element
        middle,             // Midpoint of search
        position = -1;      // Position of search value
        bool found = false; // Flag
    
        while (!found && first <= last)
        {
            middle = (first + last) / 2;    // Calculate midpoint
            if (array[middle] == value){    // If value is found at mid
                found = true;
                position = middle;
            }else if (array[middle] > value) // If value is in lower half
                last = middle - 1;
            else
                first = middle + 1;         // If value is in upper half
        }
        return position;
    }
    
};

int main(){
    
    //Initialize
    int menuChoice = 0;
    const int SIZE = 21;
    string inputFile = "";
    string outputFile = "";
    ifstream input;
    SearchSort *ss = new SearchSort();
    
    
    //Loop for menu option
    do{
        cout << "Enter 1 to Search" << endl;
        cout << "Enter 2 to Sort" << endl;
        cout << "Enter 3 to Binary Search" << endl;
        cout << "Enter 4 to Quit Program" << endl;
        cin >> menuChoice;
        
        if( menuChoice == 1 ) {
            
            //User enters file name
            cout << "Please enter a file name: ";
            cin >> inputFile;
            cout << endl;
            
            //Open File
            input.open(inputFile.c_str(), ios::in);
            
            //If file cannot be opened ask again and loop until a correct file is inputed.
            while(input.fail())
            {
                cout << endl << "File cannot be opened. Please try again." << endl;
                cout << "File name: ";
                cin >> inputFile;
                cout << endl;
                input.open(inputFile.c_str(), ios::in);
            }
            //If the file is open then move numbers in an array and search
            if (input.is_open()) {
                string array[SIZE];
                for (int i = 0; i<SIZE; i++) {
                    input >> array[i];
                }
                int location = ss->search(array, SIZE, "0");
                if (location >= 0) {
                    cout << "0 is in space: " << location << endl;
                    cout << "\n\n";
                }else{
                    cout << "There is no 0 in this file." << endl;
                    cout << "\n\n";
                }
            }
            //Close file
            input.close();
            
            
        }else if( menuChoice == 2 ){
            
            cout << "Please enter a file name: ";
            cin >> inputFile;
            cout << endl;
            
            //Open File
            input.open(inputFile.c_str(), ios::in);
            
            //If file cannot be opened ask again and loop until a correct file is inputed.
            while(input.fail())
            {
                cout << endl << "File cannot be opened. Please try again." << endl;
                cout << "File name: ";
                cin >> inputFile;
                cout << endl;
                input.open(inputFile.c_str(), ios::in);
            }
            
            //Gets the file name to output
            cout << "Enter filename where you would like to store sorted file: ";
            cin >> outputFile;
            cout << "\n";
            //Store file to array
            if (input.is_open()) {
                int array[SIZE];
                for (int i = 0; i<=SIZE; i++) {
                    input >> array[i];
                }
                //Sort array
                ss->sortArray(array, SIZE);
                ofstream sorted;
                sorted.open(outputFile.c_str(), ios::in | ios::trunc);
                if (sorted.is_open()) {
                    //write to file
                    for (int i = 0; i<=SIZE; i++) {
                        sorted << array[i] << " ";
                    }
                }
                sorted.close();
            }
            input.close();
            
        }else if( menuChoice == 3 ){
            
            //User enters file name
            cout << "Please enter a sorted file name: ";
            cin >> inputFile;
            cout << endl;
            
            //Open File
            input.open(inputFile.c_str(), ios::in);
            
            //If file cannot be opened ask again and loop until a correct file is inputed.
            while(input.fail())
            {
                cout << endl << "File cannot be opened. Please try again." << endl;
                cout << "File name: ";
                cin >> inputFile;
                cout << endl;
                input.open(inputFile.c_str(), ios::in);
            }
            
            //Get target
            int target = 0;
            cout << "Enter target number: ";
            cin >> target;
            cout << "\n";
            
            //If the file is open then move numbers in an array and search
            if (input.is_open()) {
                int array[SIZE];
                for (int i = 0; i<=SIZE; i++) {
                    input >> array[i];
                }
                int location = ss->binarySearch(array, SIZE, target);
                if (location >= 0) {
                    cout << target << " is in space: " << location << endl;
                    cout << "\n\n";
                }else{
                    cout << "Target not found in file." << endl;
                    cout << "\n\n";
                }
            }
            //Close file
            input.close();
        }
    }while( menuChoice != 4 );
}
