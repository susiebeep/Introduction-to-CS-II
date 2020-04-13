project4: main.o character.o medusa.o barbarian.o vampire.o harrypotter.o bluemen.o game.o input.o menu.o queue.o stack.o
	g++ main.o character.o medusa.o barbarian.o vampire.o harrypotter.o bluemen.o game.o input.o menu.o queue.o stack.o -o project4

main.o: main.cpp menu.cpp game.cpp
	g++ -c main.cpp

character.o: character.cpp character.hpp
	g++ -c character.cpp

vampire.o: vampire.hpp vampire.cpp
	g++ -c vampire.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c medusa.cpp

harrypotter.o: harrypotter.hpp harrypotter.cpp
	g++ -c harrypotter.cpp

bluemen.o: bluemen.hpp bluemen.cpp
	g++ -c bluemen.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c barbarian.cpp

game.o: game.cpp game.hpp queue.cpp stack.cpp character.cpp
	g++ -c game.cpp

input.o: input.hpp input.cpp
	g++ -std=c++0x -c input.cpp

menu.o: menu.hpp menu.cpp
	g++ -c menu.cpp

queue.o: queue.hpp queue.cpp character.cpp
	g++ -c queue.cpp

stack.o: stack.hpp stack.cpp queue.cpp character.cpp
	g++ -c stack.cpp

clean:
	rm *.o project4
