/****************************************************************
 ** Author: William Kim
 ** Date: 12/04/2015
 ** Description: main class
 ***************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
using namespace std;

void Usage(){
    cout<<"Correct Usage:"<<endl;
    cout<<"./Fibonacci [n]"<<endl;
}
//Code from lecture slide
long rfactorial(int n){
    if (n == 1)
        return 1;
    else
        return n * rfactorial(n-1);
}
//Code from lecture slide
long factorialHelper(int n, int result){
    if (n == 1)
        return result;
    else
        return factorialHelper(n-1, n*result);
}
//Code from lecture slide
long factorial(int n){
    return factorialHelper(n, 1);
}

int main(int argc, char** args) {
    try{
        int n;
        clock_t t;
        
        cout << "Enter integer N: ";
        cin  >> n;
        cout << endl;
        
        cout << "Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
        
        cout << "Calling Recursive Fibonacci implementation"<<endl;
        t = clock();
        FibonacciR fr(n);
        fr.PrintFibonacci();
        t = clock() - t;
        cout << "It took " << t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) <<  "seconds).\n" << endl;
        
        
        cout<<"Calling Non-Recursive Fibonacci implementation"<<endl;
        t = clock();
        FibonacciNR fnr(n);
        fnr.PrintFibonacci();
        t = clock() - t;
        cout << "It took " << t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) <<  "seconds).\n" << endl;
        
        cout << "Calling Recursive Factorial implementation"<<endl;
        t = clock();
        cout << rfactorial(n) << endl;
        t = clock() - t;
        cout << "It took " << t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) <<  "seconds).\n" << endl;
        
        
        cout<<"Calling Tail-Recursive Factorial implementation"<<endl;
        t = clock();
        cout << factorial(n) << endl;
        t = clock() - t;
        cout << "It took " << t << " clicks (" << (((float)t)/CLOCKS_PER_SEC) <<  "seconds).\n" << endl;
        
        
        cout << "Done!!!!" << endl;
        return 0;
    }
    catch(...)
    {
        cout<<"Oops an error occured! Please check usage"<<endl;
        Usage();
        return 1;
    }
}