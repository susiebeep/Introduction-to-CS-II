/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Game class
 ** Author:       Susan Hibbert
 ** Date:         1 May 2019
 ** Description:  This program contains the member function definitions for the Game
		  class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
		  Chapter 3.10 Random Numbers, 
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "character.hpp"
#include "game.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/********************************************************************************** 
 ** Description: The default construtor for the Game class dynamically allocates an 
		 array of 2 Character pointers to its pointer-to-a-pointer-to-a-
		 Character characters in a newly created Game object
 ** *******************************************************************************/ 

Game::Game()
{
	characters = new Character*[2];
}


/********************************************************************************** 
 ** Description: The destructor of the Game class frees dynamically allocated memory
		 allocated to the two Character objects which were created during
		 the running of the Fantasy Combat game
 ** *******************************************************************************/ 
Game::~Game()
{
	delete characters[0];
	delete characters[1];
	delete [] characters;
}
/********************************************************************************** 
 ** Description: The Game menu function calls upon a separate display_menu function
		 to print the Fantasy Combat game's menu to the user. The display_menu
		 function takes the Game object that called the Game menu function as a
		 parameter and returns an int value indicating the user's menu choice
		 at the end of the game (i.e. play the game again or quit). The Game
		 menu function itself does not take any parameters but returns the
		 user's menu choice from the display_menu function to the calling
		 program
 ** *******************************************************************************/ 

int Game::menu()
{
	int choice = display_menu(this);
	return choice;
}

/********************************************************************************** 
 ** Description: The get_characters function of the Game class takes no parameters
		 and returns characters, the pointer to the array of Character
		 pointers
 ** *******************************************************************************/ 

Character** Game::get_characters()
{
	return this -> characters;
}


/********************************************************************************** 
 ** Description: The do_round function of the Game class takes a Character pointer
		 to the attacking Character object and a Character pointer to the
		 defending Character object. It returns the boolean true to the
		 start function if the defending Character object is still alive
		 at the end of the attack, and returns false if it died which ends
		 the game. Information about the round is displayed on screen for
		 the user during the execution of this function.
 ** *******************************************************************************/ 

bool Game::do_round(Character *attacker, Character *defender)
{
	//boolean flag set to true if the defending character is alive
	bool alive = true;	

	//display stats of each attack round
	std::cout << " " << std::endl;
	std::cout << "**********RESULTS OF ATTACK**********" 
		  << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Attacker Type: " << attacker -> get_type() << std::endl;
	std::cout << "Defender Type: " <<  defender -> get_type() << std::endl;

	//call attacker's attack funtion
	int attack = attacker -> attack();

	//call defender's defense function and calculate damage of attack
	int damage = defender -> defense(attack);	

	//if the defender has negative strength points after the attack
	if ((defender -> get_strength_points()) == 0)
	{
		std::cout << " " << std::endl;
		std::cout << "Oh no! One of your characters died!" << std::endl;
		std::cout << "*** " << attacker -> get_type() << " wins! ***" 
			  << std::endl;
		alive = false;
	}

	return alive;
}


/********************************************************************************** 
 ** Description: The start function sets up the Fantasy Combat Game after the user 
		 has selected their choice of Character objects. It takes no
		 parameters and does not have a return type. One of the Character
		 objects is selected at random to start attacking. Then the
		 attacking and defending Character objects are passed to the do_round
		 function, where the combat happens. The do_round function will
		 continue to be called after each attack as along as both characters are
		 still alive. Each round consists of 2 attacks, one for each Character
		 object. The round number is displayed at the end of every round.
 ** *******************************************************************************/ 

void Game::start(Character **characters)
{
		int round = 0;
		int counter = 0;

		//decide who starts as attacker and who starts as defender randomly
		int first = rand() % 2 + 1;
		Character *attacker;
		Character *defender;
		
		if (first == 1)
		{
			attacker = characters[0];
			defender = characters[1];
		}
		
		else
		{
			attacker = characters[1];
			defender = characters[0];
		}

		//call do_round function to initiate the combat. Opponents will swap
		//attacker and defender positions during the round and continue to
		//fight until one of the characters dies
		while (do_round(attacker, defender))
		{
			Character *temp;
			temp = attacker;
			attacker = defender;
			defender = temp;	
			
			//each round consists of 2 attacks
			if ((round + 1) % 2 == 0)
			{	

				//int display_round = (round + 2) - round;	
				std::cout << " " << std::endl;
				std::cout << "--------------------END OF ROUND " 
					  << (round - counter) << "--------------------"
					  << std::endl;
				std::cout << " " << std::endl;
				counter++; 
			}
			
			round++;
		}

}
