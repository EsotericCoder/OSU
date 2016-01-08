/****************************************************************
 ** Author: William Kim
 ** Date: 12/04/2015
 ** Description: FibonacciNR class
 ***************************************************************/
//
//  Code From:
//      Website: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
//      Created on: Sep 11, 2010
//      Author: julian
//

#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR() {
}

FibonacciNR::FibonacciNR(const int &n):n_(&n){
}

FibonacciNR::~FibonacciNR() {
}

int FibonacciNR::Fibonacci(const int &n)
{
    int first =0;
    int second=1;
    int counter=2;
    while(counter < n)
        {
            int temp=second;
            second=first+second;
            first=temp;
            ++counter;
            }
    if(n==0)
        return 0;
    else
        return first+second;
}
void FibonacciNR::PrintFibonacci(){
    const int result = Fibonacci(*n_);
    std::cout<<*n_<<"th fibonacci Number:"<<result<<std::endl;
}