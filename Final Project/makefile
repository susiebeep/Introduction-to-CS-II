finalproject: main.o player.o game.o menu.o input.o space.o mirror.o studio.o door.o wall.o dressingroom.o item.o dress.o wig.o ointment.o eyelashes.o purse.o
	g++ -g main.o player.o game.o menu.o input.o space.o mirror.o studio.o door.o wall.o dressingroom.o item.o dress.o wig.o ointment.o eyelashes.o purse.o -o finalproject

main.o: main.cpp menu.cpp game.cpp player.cpp
	g++ -c -g main.cpp

player.o: player.cpp player.hpp
	g++ -c -g player.cpp

game.o: game.cpp game.hpp
	g++ -c -g game.cpp

menu.o: menu.hpp menu.cpp
	g++ -c -g menu.cpp

input.o: input.hpp input.cpp
	g++ -std=c++0x -c -g input.cpp

space.o: space.hpp space.cpp
	g++ -c -g space.cpp

mirror.o: mirror.hpp mirror.cpp
	g++ -c -g mirror.cpp

studio.o: studio.hpp studio.cpp
	g++ -c -g studio.cpp

door.o: door.hpp door.cpp
	g++ -c -g door.cpp

wall.o: wall.hpp wall.cpp
	g++ -c -g wall.cpp

dressingroom.o: dressingroom.hpp dressingroom.cpp
	g++ -c -g dressingroom.cpp

item.o: item.hpp item.cpp
	g++ -c -g item.cpp

dress.o: dress.hpp dress.cpp
	g++ -c -g dress.cpp

wig.o: wig.hpp wig.cpp
	g++ -c -g wig.cpp

ointment.o: ointment.hpp ointment.cpp
	g++ -c -g ointment.cpp

eyelashes.o: eyelashes.hpp eyelashes.cpp
	g++ -c -g eyelashes.cpp

purse.o: purse.hpp purse.cpp
	g++ -c -g purse.cpp

clean:
	rm *.o finalproject
