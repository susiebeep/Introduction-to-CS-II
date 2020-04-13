project2: main.o animal.o tiger.o penguin.o turtle.o zoo.o input.o
	g++ main.o animal.o tiger.o penguin.o turtle.o zoo.o input.o -o project2

main.o: main.cpp animal.cpp tiger.cpp penguin.cpp turtle.cpp 
	g++ -c main.cpp

animal.o: animal.cpp animal.hpp
	g++ -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c turtle.cpp

zoo.o: zoo.hpp zoo.cpp
	g++ -c zoo.cpp

input.o: input.hpp input.cpp
	g++ -std=c++0x -c input.cpp

clean:
	rm *.o project2
