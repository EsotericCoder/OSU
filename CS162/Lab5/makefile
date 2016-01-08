filter: Filter.o Original.o Encryption.o Upper.o main.o
	g++ Filter.o Original.o Encryption.o Upper.o main.o -o filter

main.o: main.cpp main.hpp
	g++ -c main.cpp

Filter.o: Filter.cpp Filter.hpp
	g++ -c Filter.cpp

Original.o: Original.cpp Original.hpp
	g++ -c Original.cpp

Encryption.o: Encryption.cpp Encryption.hpp
	g++ -c Encryption.cpp

Upper.o: Upper.cpp Upper.hpp
	g++ -c Upper.cpp

clean:
	rm -rf *.o filter
