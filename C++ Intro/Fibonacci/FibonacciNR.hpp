/****************************************************************
 ** Author: William Kim
 ** Date: 12/04/2015
 ** Description: FibonacciNR header
 ***************************************************************/
//  Code From:
//      Website: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
//      Created on: Sep 11, 2010
//      Author: julian
//

#ifndef FibonacciNR_hpp
#define FibonacciNR_hpp

#include <stdio.h>



class FibonacciNR {
public:
    FibonacciNR(const int &n);
    virtual ~FibonacciNR();
    void PrintFibonacci();
private:
    FibonacciNR();
    int Fibonacci(const int &n);
    const int* n_;
};

#endif /* FibonacciNR_hpp */
