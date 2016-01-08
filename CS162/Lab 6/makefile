test: Queue.o Stack.o main.o
	g++ Queue.o Stack.o main.o -o test

main.o: main.cpp
	g++ -c main.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

Stack.o: Stack.cpp Stack.hpp
	g++ -c Stack.cpp

clean:
	rm -rf *.o test
