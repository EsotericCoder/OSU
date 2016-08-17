import time
import matplotlib.pyplot as plt
import numpy as np
import os

#****************************************************
# Recursive Fibonacci Sequence
#   Recursively calculates the nth term of the
#   fibonacci sequence
#****************************************************
def recFib(n):
    if n == 0:
        return 0;
    elif n == 1:
        return 1
    else:
        return recFib(n-1) + recFib(n-2)

#****************************************************
# Iterative Fibonacci Sequence
#   Iterative calculates the nth term of the
#   fibonacci sequence
#****************************************************
def intFib(n):
    fib = 0
    last = 1
    while n > 0:
        temp = fib
        fib += last
        last = temp
        n -= 1
    return fib

#****************************************************
# Timing function
#   Main running code for testing
#****************************************************
def timing(func, nList, file):
    list = []
    for n in nList:
        print("Calculating f(%d)" % n)
        start = time.time()
        func(n)
        end = time.time()
        list.append(end - start)
    print("Calculations Ended")
    data = np.asarray([nList, list])
    data = data.T
    np.savetxt(file, data, delimiter=",")

def main():
    list = [0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.5, 2, 5]
    list[:] = [1000000*i for i in list]
    file = "intData2.csv"
    func = lambda n: intFib(n)
    timing(func, list, file)
    '''
    list = [1, 2, 5, 10, 15, 20, 25, 30, 40, 50]
    file = "recData.csv"
    func = lambda n: recFib(n)
    timing(func, list, file)
    '''
    #os.system("shutdown/s")

if __name__ == "__main__":
    main()