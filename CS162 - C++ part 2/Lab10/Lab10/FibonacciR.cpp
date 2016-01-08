/****************************************************************
 ** Author: William Kim
 ** Date: 12/04/2015
 ** Description: FibonacciR class
 ***************************************************************/
//  Code From:
//      Website: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
//      Created on: Sep 11, 2010
//      Author: julian
//

#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() {
}

FibonacciR::FibonacciR(const int &n):n_(&n){
}

FibonacciR::~FibonacciR() {
}

int FibonacciR::Fibonacci(const int &n){
    if(n==0)
        return 0;
    else if(n==1)
  		return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}
void FibonacciR::PrintFibonacci(){
    int FibonaciNum=Fibonacci(*n_);
    std::cout<<*n_<<"th fibonaci number: "<<FibonaciNum<<std::endl;
}