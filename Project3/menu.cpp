/******************************************************************************* 
 ** Program Name: Source code for the display_menu function used in the Fantasy 
		  Combat Game
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
 ** Description:  This program contains the function definition for the display_menu
		  function which is called by the Game menu function in the main
		  program module of the Fantasy Combat Game.	
		  A menu is displayed to the user listing a choice of 5 characters.
		  The user will be prompted to select two characters to fight one
		  another. After the user inputs their choice, it is validated
		  by an input validation function which returns their input as an
		  integer. If the user does not select a valid menu option they will
		  be prompted until they make a valid selection. At the end of the
		  function, the user's menu choice will be returned to the main
		  program module of the Fantasy Combat Game.
 ** Citations:    Chapter 4.5, Menu-Driven Programs, and
                  Chapter 6.9, Using Functions in a Menu-Driven Programs, Starting Out
		  With C++ Early Objects 9th Edition;
		  5.10 std::cin, extraction, and dealing with invalid text input, 
		  LearnCPP.com
 ** *******************************************************************************/ 
#include <iostream>
#include <string>
#include "menu.hpp"
#include "input.hpp"
#include "barbarian.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "character.hpp"
#include "game.hpp" 

int display_menu(Game *obj)
{
	std::string choice1;
	std::string choice2;
	std::string choice3;
	int valid_choice1;
	int valid_choice2;
	int valid_choice3;

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "* Welcome to the Fantasy Combat Game! *" << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "List of characters:" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. Vampire" << std::endl;
	std::cout << "2. Barbarian" << std::endl; 
	std::cout << "3. Blue Men" << std::endl;	
	std::cout << "4. Medusa" << std::endl;
	std::cout << "5. Harry Potter" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "!!! It's time to pick the characters to fight! !!!" << std::endl;
	std::cout << " " << std::endl;

	//user chooses character 1	
	std::cout << "Please choose a character number for first opponent:" << std::endl;
	std::getline(std::cin, choice1);

	//user's input is validated and converted to an integer	
	valid_choice1 = int_input_val(choice1);

	while (valid_choice1 < 1 || valid_choice1 > 5)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1-5." << std::endl;
		std::getline(std::cin, choice1);
		valid_choice1 = int_input_val(choice1);
	}

	Character** characters = obj -> get_characters();

	//create Character object based on user's choice
	
	if (valid_choice1 == 1)
	{
		//dynamically allocate a Vampire object to one of Character pointers
		characters[0] = new Vampire;
	}
	
	if (valid_choice1 == 2)
	{
		//dynamically allocate a Barbarian object to one of Character pointers
		characters[0] = new Barbarian;
	}

	if (valid_choice1 == 3)
	{
		//dynamically allocate a Blue_Men object to one of Character pointers
		characters[0] = new Blue_Men;
	}
	
	if (valid_choice1 == 4)
	{
		//dynamically allocate a Medusa object to one of Character pointers
		characters[0] = new Medusa;
	}

	if (valid_choice1 == 5)
	{
		//dynamically allocate a Harry_Potter object to one of Character pointers
		characters[0] = new Harry_Potter;
	}


	//user chooses character 2
	std::cout << "Please choose a character number for second opponent:" << std::endl;
	std::getline(std::cin, choice2);

	//user's input is validated and converted to an integer	
	valid_choice2 = int_input_val(choice2);

	while (valid_choice2 < 1 || valid_choice2 > 5)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1-5." << std::endl;
		std::getline(std::cin, choice2);
		valid_choice2 = int_input_val(choice2);
	}

	//create Character object based on user's choice	

	if (valid_choice2 == 1)
	{
		//dynamically allocate a Vampire object to other Character pointer
		characters[1] = new Vampire;
	}

	if (valid_choice2 == 2)
	{
		//dynamically allocate Barbarian object to other Character pointer
		characters[1] = new Barbarian;
	}

	if (valid_choice2 == 3)
	{
		//dynamically allocate a Blue_Men object to other Character pointer
		characters[1] = new Blue_Men;
	}
	
	if (valid_choice2 == 4)
	{
		//dynamically allocate a Medusa object to other Character pointer
		characters[1] = new Medusa;
	}

	if (valid_choice2 == 5)
	{
		//dynamically allocate a Harry_Potter object to other Character pointer
		characters[1] = new Harry_Potter;
	}

	//call start function of Game object and pass in the user's choice of Characters.
	//Combat between the two Character objects begins
	obj -> start(characters);		

	//After the end of the game ask user if want to play again or quit the game
	std::cout << " " << std::endl;
	std::cout << "Game is over! Please select one of the following two options:" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. Play again" << std::endl;
	std::cout << "2. Exit the game" << std::endl;
	std::cout << " " << std::endl;
	std::getline(std::cin, choice3);

	//user's input is validated and converted to an integer	
	valid_choice3 = int_input_val(choice3);

	while (valid_choice3 < 1 || valid_choice3 > 2)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1 or 2." << std::endl;
		std::getline(std::cin, choice3);
		valid_choice3 = int_input_val(choice3);
	}

	if (valid_choice3 == 2)
	{
		std::cout << "You have chosen to quit. Goodbye!" << std::endl;

	}	

	
	//return user's choice to main program module
	return valid_choice3;
}

