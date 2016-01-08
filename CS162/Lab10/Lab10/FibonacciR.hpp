/****************************************************************
 ** Author: William Kim
 ** Date: 12/04/2015
 ** Description: FibonacciR header
 ***************************************************************/
//  Code From:
//      Website: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
//      Created on: Sep 11, 2010
//      Author: julian
//

#ifndef FibonacciR_hpp
#define FibonacciR_hpp

#include <stdio.h>

class FibonacciR {
public:
    FibonacciR(const int &n);
    virtual ~FibonacciR();
    void PrintFibonacci();
private:
    FibonacciR();
    int Fibonacci(const int &n);
    const int *n_;
};

#endif /* FibonacciR_hpp */
