/******************************************************************************* 
 ** Program Name: Main program module for Zoo Tycoon Game
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This is the main program module for the Zoo Tycoon Game. A Zoo
		  object is created here then the start_game function is called and
		  the user purchases animals for the zoo before the game starts.
		  Once the user purchases the animals for the game, the zoo_day
		  function is called where the game is implemented as a day at the zoo
		  and random events take place. The end_day function is called when
		  one zoo day has completed and if the user wishes to continue the
		  game and proceed to the next day the zoo_day function will be called
		  again. This repeats until the user does not wish to play the game
		  anymore or they run out of money.
		  The random number function rand used in the random_event function
		  of the Zoo class becomes seeded with a value by the srand function 
		  at the start of the main program module.
 ** *******************************************************************************/ 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "zoo.hpp"
#include "input.hpp"

int main()
{
	Zoo zoo;
	int choice; 
	
	//random number generator seed for random_event function
	unsigned seed;
	seed = time(0);
	srand(seed);

	zoo.start_game();
	zoo.zoo_day();

	choice = zoo.end_day();
	
	while (choice == 1)
	{
		zoo.zoo_day();
		choice = zoo.end_day();
	}

	return 0;
}
