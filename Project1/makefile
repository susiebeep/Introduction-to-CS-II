project1: main.o ant.o board.o menu.o input.o
	g++ main.o ant.o board.o menu.o input.o -o project1

main.o: main.cpp ant.cpp board.cpp
	g++ -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

board.o: board.cpp ant.hpp
	g++ -c board.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp menu.hpp

input.o: input.cpp input.hpp
	g++ -c -std=c++0x input.cpp input.hpp
clean:
	rm *.o project1
