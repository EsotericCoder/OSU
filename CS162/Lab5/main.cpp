/******************************************************************************************
 ** Author: William Kim
 ** Date: 10/29/2015
 ** Description: main class
 *****************************************************************************************/

#include "main.hpp"
#include "Filter.hpp"
#include "Original.hpp"
#include "Encryption.hpp"
#include "Upper.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    //Initialize
    ifstream input;
    ofstream encrypted;
    ofstream upper;
    ofstream original;
    
    string inputFile;
    string encryptedFile;
    string upperFile;
    string originalFile;
    
    int key;
    
    //Create an instance of Upper and Original object
    Upper u;
    Original o;
    
    //Prompt User
    cout << "Enter the file name: ";
    cin >> inputFile;
    
    //Open file
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
    
    //Get filename of copy original file
    cout << endl << "Filename to export original copy: ";
    cin >> originalFile;
    cout << endl;
    
    //Create and open original file
    original.open(originalFile.c_str(), ios::in | ios::trunc);
    
    //Get filename of output upper file
    cout << endl << "Filename to export uppercase data: ";
    cin >> upperFile;
    
    //Create and open upper file
    upper.open(upperFile.c_str(), ios::in | ios::trunc);
    
    //Get filename of output encrypted file.
    cout << endl << "Filename to export encrypted data: ";
    cin >> encryptedFile;
    
    //Get Encryption Key
    cout << endl << "Enter Encryption Key (Integer 1-26): ";
    cin >> key;
    
    //Create and open encrypted file
    encrypted.open(encryptedFile.c_str(), ios::in | ios::trunc);
    
    //Create instance of Encryption object
    Encryption e(key);
    
    //Do
    e.doFilter(input, encrypted);
    u.doFilter(input, upper);
    o.doFilter(input, original);
    
    //Close all files
    input.close();
    encrypted.close();
    upper.close();
    original.close();
    
    return 0;
}


