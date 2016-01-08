Game: Queue.o Creature.o Barbarian.o BlueMen.o ReptilePeople.o TheShadow.o Goblin.o Game.o
	g++ Queue.o Creature.o Barbarian.o BlueMen.o ReptilePeople.o TheShadow.o Goblin.o Game.o -o Game

Game.o: Game.cpp
	g++ -c Game.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

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
