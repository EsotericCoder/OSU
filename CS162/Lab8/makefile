test: Queue.o main.o
	g++ Queue.o main.o -o test

main.o: main.cpp
	g++ -c main.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

clean:
	rm -rf *.o test
