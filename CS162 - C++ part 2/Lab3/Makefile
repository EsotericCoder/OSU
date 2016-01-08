run_test: Die.o LoadedDie.o
	g++ run_test.cpp Die.o LoadedDie.o -o run_test

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -c LoadedDie.cpp

clean:
	rm -rf *.o run_test