grocery: Item.o List.o
	g++ Item.o List.o -o grocery

Die.o: Item.cpp Item.hpp
	g++ -c Item.cpp

List.o: List.cpp List.hpp
	g++ -c List.cpp

clean:
	rm -rf *.o grocery
