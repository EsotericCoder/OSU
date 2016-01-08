run: BedroomOne.o BedroomTwo.o Hallway.o Kitchen.o LivingRoom.o Player.o Space.o main.o
	g++ BedroomOne.o BedroomTwo.o Hallway.o Kitchen.o LivingRoom.o Player.o Space.o main.o -o run

main.o: main.cpp 
	g++ -c main.cpp

BedroomOne.o: BedroomOne.cpp BedroomOne.hpp
	g++ -c BedroomOne.cpp

BedroomTwo.o: BedroomTwo.cpp BedroomTwo.hpp
	g++ -c BedroomTwo.cpp

Hallway.o: Hallway.cpp Hallway.hpp
	g++ -c Hallway.cpp

Kitchen.o: Kitchen.cpp Kitchen.hpp
	g++ -c Kitchen.cpp

LivingRoom.o: LivingRoom.cpp LivingRoom.hpp
	g++ -c LivingRoom.cpp

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

clean:
	rm -rf *.o run