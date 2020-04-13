/******************************************************************************* 
 ** Program Name: Main program module for Fantasy Combat Tournament
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This is the main program module for the Fantasy Combat Tournament.
		  After a Game object is created it calls the Game menu function
		  which displays the Fantasy Combat Tournament's menu options for the
		  user (play game or exit). 
		  When the tournament is over, the Game menu will be displayed
		  to the user again. If the user wishes to play again the user's
		  choice will be returned to the main program module and a new 
		  tournament will begin. The Game menu will be displayed at the end
		  of every tournament until the user decides they want to quit. 
		  The random number function rand used in the attack and defense
		  functions of the Character subclasses and start function of the
		  Game class becomes seeded with a value by the srand function at
		  the start of the main program module
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

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "* Welcome to the Fantasy Combat Tournament! *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << " " << std::endl;
	
	//display game menu
	choice = game.menu();
	
	//if user decides to play game
	if (choice == 1)
	{
		//continue to display menu at end of the game until user quits
		while (choice != 2)
		{	
			choice = game.menu();	
		}
	}

	return 0;
}
