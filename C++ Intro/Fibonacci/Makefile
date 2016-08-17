run: FibonacciNR.o FibonacciR.o main.o
	g++ FibonacciNR.o FibonacciR.o 
main.o -o run

main.o: main.cpp 
	g++ -c main.cpp

FibonacciNR.o: FibonacciNR.cpp FibonacciNR.hpp
	g++ -c FibonacciNR.cpp

FibonacciR.o: FibonacciR.cpp FibonacciR.hpp
	g++ -c FibonacciR.cpp

clean:
	rm -rf *.o run