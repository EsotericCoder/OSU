Game: Creature.o Barbarian.o BlueMen.o ReptilePeople.o TheShadow.o Goblin.o main.o
	g++ Creature.o Barbarian.o BlueMen.o ReptilePeople.o TheShadow.o Goblin.o main.o -o Game

main.o: main.cpp
	g++ -c main.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -c Creature.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

Goblin.o: Goblin.cpp Goblin.hpp
	g++ -c Goblin.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

ReptilePeople.o: ReptilePeople.cpp ReptilePeople.hpp
	g++ -c ReptilePeople.cpp

TheShadow.o: TheShadow.cpp TheShadow.hpp
	g++ -c TheShadow.cpp

clean:
	rm -rf *.o Game
