/******************************************************************************* 
 ** Program Name: Main program module for Fantasy Combat Game
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
 ** Description:  This is the main program module for the Fantasy Combat Game.
		  After a Game object is created it calls the Game menu function
		  which displays the Fantasy Combat Game's menu options for the
		  user. When the game is over, if the user wishes to play again
		  the user's choice will be returned to the main program module
		  and the game menu will be displayed again until the user decides
		  they want to quit. The random number function rand used in the
		  attack and defense functions of the Character subclasses and
		  start function of the Game class becomes seeded with a value by
		  the srand function at the start of the main program module
 ** *******************************************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "menu.hpp"
#include "game.hpp"

int main()
{	
	//create Game object
	Game game;
	int choice;

	//random number generator seed for the attack and defense functions
	unsigned seed;
	seed = time(0);
	srand(seed);

	choice = game.menu();
	
	while (choice != 2)
	{	
		choice = game.menu();	
	}

	return 0;
}
