/******************************************************************************* 
 ** Program Name: Source code for the display_menu function used in the Fantasy 
		  Combat Tournament
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This program contains the function definition for the display_menu
		  function which is called by the Game menu function in the main
		  program module of the Fantasy Combat Tournament.	

		  A menu is displayed to the user with a choice of two options - play
		  the game or exit.  After the user inputs their choice, it is 
		  validated by an input validation function which returns their input
		  as an integer. If the user does not select a valid menu option they
		  will be prompted until they make a valid selection. If the user 
		  chooses to exit, the program will end.
		  
		  If the user opts to play the game, they will be asked to enter the
		  number of players for both teams (NB both teams will have the same
		  number of players). The user will then be asked to select the
		  Characters for both team lineups from the choice of 5 Character
		  options displayed on screen. After the user inputs their choice of
		  Character, it is validated by an input validation function which
		  returns their input as an integer. If the user does not select a
		  valid Character option they will be prompted until they make a 
		  valid selection. When they make a valid Character choice, they will
		  be asked to enter a name for that Character. The lineup for both
		  teams will be displayed on screen before the tournament begins. 
		 
		  The tournament function of the Game class is then called which
		  starts the combat between the two teams. This function outputs
		  information about each battle in the tournament including the names
		  and types of Characters fighting each round, the lineup of both 
		  teams after each round and the content of the loser pile. At the
		  end of the tournament, it displays the final score for both teams
		  along with the winner of the tournament. 

		  When the tournament is over, the user will be asked if they wish
		  to see the contents of the loser pile. After input validation on
		  the user's choice, if they selected yes the loser pile will be
		  displayed on screen, in order of fighters last defeated to first
		  defeated. Then the team lineups and loser pile will be cleared, 
		  should the user wish to play the game again.

		  At the end of the function, the user's original menu choice will
		  be returned to the main program module of the Fantasy Combat 
		  Tournament.
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
#include "queue.hpp"

int display_menu(Game *obj)
{
	std::string start_choice;
	std::string end_choice;
	std::string team_size;
	std::string char_choice;
	std::string input_name;
	std::string losers;
	int valid_start;
	int valid_end;
	int valid_size;
	int valid_char;
	int valid_losers;

	std::cout << "Please select one of the following two options: " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. Play Game" << std::endl;
	std::cout << "2. Exit" << std::endl; 
	std::cout << " " << std::endl;

	std::getline(std::cin, start_choice);

	//user's input is validated and converted to an integer	
	valid_start = int_input_val(start_choice);

	while (valid_start < 1 || valid_start > 2)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1 or 2." << std::endl;
		std::getline(std::cin, start_choice);
		valid_start = int_input_val(start_choice);
	}

	if (valid_start == 2)
	{
		std::cout << " " << std::endl;
		std::cout << "You have chosen to quit. Goodbye!" << std::endl;
		std::cout << " " << std::endl;
	}	

	if (valid_start == 1)
	{	
		//ask user to enter number of fighters for both teams, validate input and set up each team
		//(each team will have the same number of players)
		std::cout << " " << std::endl;
		std::cout << "Please enter the number of fighters in both teams: " << std::endl;
		std::getline(std::cin, team_size);
		
		//user's input is validated and converted to an integer	
		valid_size = int_input_val(team_size);
	
		std::cout << " " << std::endl;
		std::cout << "Please choose the " << valid_size << " characters for Team A: " << std::endl; 
		
		//display list of characters
		std::cout << "List of characters:" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "1. Vampire" << std::endl;
		std::cout << "2. Barbarian" << std::endl; 
		std::cout << "3. Blue Men" << std::endl;	
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter" << std::endl;
		std::cout << " " << std::endl;
		
		//retrieve the Queue pointer teamA of Game object
		Queue *team1 = obj -> get_queueA();
		
		//set team name
		team1 -> setName("Team A");
		Character *char_type1;	
	
		//Choose the fighters and their names for Team A
		for (int i = 0; i < valid_size; i++)
		{	
			std::cout << " " << std::endl;		
			std::cout << "Character " << (i + 1) << " type: " << std::endl;
			std::getline(std::cin, char_choice);
			
			//validate user choice of character	
			valid_char = int_input_val(char_choice);
			
			while (valid_char < 1 || valid_char > 5)
			{
				std::cout << "Oops! That isn't a valid selection. Please select 1-5." << std::endl;
				std::getline(std::cin, char_choice);
				valid_char = int_input_val(char_choice);
			}

			//call Game function to create Character
			char_type1 = obj -> character_choice(valid_char);

			//get name of Character
			std::cout << " " << std::endl;
			std::cout << "Please enter a name for Character " << (i + 1) << ": " << std::endl;
			std::getline(std::cin, input_name);

			//set Character name
			char_type1 -> set_name(input_name);

			//create CharNode with pointer to character
			team1 -> addTail(char_type1);
		}

		//display the fighers in Team A
		std::cout << " " << std::endl;		
		std::cout << "*****Characters in Team A***** " << std::endl;
		team1 -> printQueue();

		std::cout << " " << std::endl;
		std::cout << "Please choose the " << valid_size << " characters for Team B: " << std::endl; 
	
		//display list of characters
		std::cout << "List of characters:" << std::endl;
		std::cout << " " << std::endl;
		std::cout << "1. Vampire" << std::endl;
		std::cout << "2. Barbarian" << std::endl; 
		std::cout << "3. Blue Men" << std::endl;	
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter" << std::endl;
		std::cout << " " << std::endl;		
	
		//retrieve the Queue pointer teamB of Game object
		Queue *team2 = obj -> get_queueB();
	
		//set team name
		team2 -> setName("Team B");
		Character *char_type2;
	
		//Choose the fighters and their names for Team B
		for (int i = 0; i < valid_size; i++)
		{
			std::cout << " " << std::endl;		
			std::cout << "Character " << (i + 1) << " type: " << std::endl;
			std::getline(std::cin, char_choice);
			
			//validate user choice of character	
			valid_char = int_input_val(char_choice);
			
			while (valid_char < 1 || valid_char > 5)
			{
				std::cout << "Oops! That isn't a valid selection. Please select 1-5." << std::endl;
				std::getline(std::cin, char_choice);
				valid_char = int_input_val(char_choice);
			}

			//call Game function to create Character
			char_type2 = obj -> character_choice(valid_char);

			//get name of Character
			std::cout << " " << std::endl;		
			std::cout << "Please enter a name for Character " << (i + 1) << ": " << std::endl;
			std::getline(std::cin, input_name);
		
			//set Character name
			char_type2 -> set_name(input_name);

			//create CharNode with pointer to character
			team2 -> addTail(char_type2);
		}

		//display the fighters in Team B
		std::cout << " " << std::endl;		
		std::cout << "*****Characters in Team B***** " << std::endl;
		team2 -> printQueue();


		//call tournament function of Game object and pass in the two teams.
		//Combat between the two teams begins
		obj -> tournament(team1, team2);		

		//ask user if they would like to see the contents of the loser pile
		std::cout << " " << std::endl;
		std::cout << "Would you like to see the contents of the loser pile?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		std::getline(std::cin, losers);
	
		//user's input is validated and converted to an integer	
		valid_losers = int_input_val(losers);

		while (valid_losers < 1 || valid_losers > 2)
		{
			std::cout << "Oops! That isn't a valid selection. Please select 1 or 2." << std::endl;
			std::getline(std::cin, losers);
			valid_losers = int_input_val(losers);
		}
	
		if (valid_losers == 1)
		{
			Stack *printLosers = obj -> get_stack();
			
			std::cout << " " << std::endl;
			std::cout << "Here are the contents of the loser pile: " << std::endl;
			printLosers -> printStack();	
			std::cout << " " << std::endl;
		}
	
		if (valid_losers == 2)
		{
			std::cout << " " << std::endl;
			std::cout << "You have selected not to display the contents of the loser pile" << std::endl;
			std::cout << " " << std::endl;
		}

		std::cout << " " << std::endl;
		std::cout << "**********GAME OVER**********" << std::endl;
		std::cout << " " << std::endl;

		//clear team A lineup
		team1 -> clear();

		//clear team B lineup
		team2 -> clear();

		//clear loser stack
		Stack *loser_pile = obj -> get_stack();
		loser_pile -> clear();
	}
 	
	return valid_start; 	
}

