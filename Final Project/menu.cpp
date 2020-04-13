/******************************************************************************* 
 ** Program Name: Source code for the menu functions used in RuPaul's Drag Race
		  Game
 ** Author:       Susan Hibbert
 ** Date:         31 May 2019
 ** Description:  This program contains the function definition for the menu
		  functions used in RuPaul's Drag Race Game
		  of the Drag Race Program	
 ** Citations:    Chapter 4.5, Menu-Driven Programs, and
                  Chapter 6.9, Using Functions in a Menu-Driven Programs, Starting 
		  Out With C++ Early Objects 9th Edition;
		  5.10 std::cin, extraction, and dealing with invalid text input, 
		  LearnCPP.com
 ** *******************************************************************************/ 
#include <iostream>
#include <string>
#include "menu.hpp"
#include "input.hpp"
#include "game.hpp"
#include "purse.hpp"


/********************************************************************************** 
 ** Description: The game_intro function takes no parameters and has no return type.
		 It is called at the start of the program and displays the back story
		 and goals for the player
 ** *******************************************************************************/ 

void game_intro()
{
	std::cout << "----------BACK STORY----------" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "You were in the middle of getting ready to hit the stage for" << std::endl;
	std::cout << "the finale of RuPaul's Drag Race, when suddenly your dressing" << std::endl;
	std::cout << "room was hit by a tornado! Oh no! Your drag has been scattered" << std::endl;
	std::cout << "all over the studio! And right before the big finale to crown" << std::endl;
	std::cout << "America's next Drag Superstar! If you still want a chance to" << std::endl;
	std::cout << "snatch the crown, you will need to collect all the items, get" << std::endl;
	std::cout << "into drag and hit the stage before your feet give out from" << std::endl;
	std::cout << "walking in heels!" << std::endl;

	std::cout << " " << std::endl;
	std::cout << "------------GOALS------------" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Find and put on the following items:" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "d = Dress" << std::endl;
	std::cout << "e = False Eyelashes" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Then, go and see RuPaul in his dressing room for a special item!" << std::endl;
	std::cout << "(he might have some helpful advice too) " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "When you pick up an item it will go into your purse. Using an" << std::endl;
	std::cout << "item removes it from your purse or it may get replaced with" << std::endl;
	std::cout << "an item you were wearing. Remember - your purse can only hold" << std::endl;
	std::cout << "4 items at once so don't forget to use the items you collect!" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "One more thing, look out for RuPaul's Magic Foot Ointment around" << std::endl;
	std::cout << "the studio. You won't be able to walk in heels and stay alive" << std::endl;
	std::cout << "without it! Using the ointment restores your health back to full," << std::endl;
	std::cout << "so use it wisely! There will be 4 for you to collect" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "m = RuPaul's Magic Foot Ointment" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "~~~Gentleman, start your engines! And may the best woman, win!~~~" << std::endl;
	std::cout << " " << std::endl;
	
}

/********************************************************************************** 
 ** Description: The direction function has no return type and takes a Game pointer
		 as a parameter. It displays a list of directions for the player to
		 move and choose from while the game is still ongoing. Once the 
		 player inputs their choice, it is validated by an input validation
		 function and their input is returned as an integer. If they do not
		 choose a valid direction option they will be prompted until they
		 make a valid selection. If the player is unable to move (e.g. they
		 hit a wall) they will be asked to select another direction. The
		 move function of the Game class is then called with the player's
		 choice of direction as a parameter
 ** *******************************************************************************/ 

void direction(Game *obj)
{
	std::string choice;
	std::string choice1;
	int valid_choice;
	int valid_choice1;
	
	std::cout << "Which direction would you like to go?" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. Up" << std::endl;
	std::cout << "2. Down" << std::endl;
	std::cout << "3. Left" << std::endl; 
	std::cout << "4. Right" << std::endl; 
	std::cout << " " << std::endl;
	std::getline(std::cin, choice);
	std::cout << " " << std::endl;

	//user's input is validated and converted to an integer	
	valid_choice = int_input_val(choice);

	while (valid_choice < 1 || valid_choice > 4)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1 - 4" << std::endl;
		std::cout << " " << std::endl;
		std::getline(std::cin, choice);
		std::cout << " " << std::endl;
		valid_choice = int_input_val(choice);
	}
	
	//call move function to move player
	bool can_move = obj -> move(valid_choice);
	bool game_over = obj -> get_end_game();
	
	while (!can_move && !game_over)
	{
		//std::cout << "You hit a wall! You need to protect that face if you want the crown!" << std::endl;
		std::cout << "Please choose another direction: " << std::endl;
		std::cout << " " << std::endl;
		std::getline(std::cin, choice1);
		std::cout << " " << std::endl;

		//user's input is validated and converted to an integer	
		valid_choice1 = int_input_val(choice1);
	
		while (valid_choice1 < 1 || valid_choice1 > 4)
		{
			std::cout << "Oops! That isn't a valid selection. Please select 1 - 4" << std::endl;
			std::cout << " " << std::endl;
			std::getline(std::cin, choice1);
			std::cout << " " << std::endl;
			valid_choice1 = int_input_val(choice1);
		}
		
		can_move = obj -> move(valid_choice1);
		game_over = obj -> get_end_game();
	}

}


/********************************************************************************** 
 ** Description:  The display_menu function has no return type and takes a Game
		  pointer as a parameter. It where the game play is implemented,
		  while the player is still alive and the game has not yet been
		  completed. This function prints 2 options on the screen for the
		  user - to play the game or exit. After the user inputs their choice,
		  it is validated by an input validation function which returns their
		  input as an integer. If the user does not select a valid menu
		  option they will be prompted until they make a valid selection.
		  If the user decides to exit, the program will end. Otherwise the
		  game will start and the player will be asked to pick a direction
		  to move and whether they would like to use any items in their purse
		  if they have collected any. They will continue to move around the
		  game map while their health is greater than 0 and they have not
		  reached the end of the game
 ** *******************************************************************************/ 

void display_menu(Game *obj)
{
	bool game_over = obj -> get_end_game();
	std::string choice;
	int valid_choice;

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "* WELCOME TO RUPAUL'S DRAG RACE GAME! *" << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << " " << std::endl;
	
	//backstory and goal of game
	game_intro();	

	std::cout << " " << std::endl;
	std::cout << "Please select one of the following TWO options:" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "1. Play Game" << std::endl;
	std::cout << "2. Exit" << std::endl; 
	std::cout << " " << std::endl;
	std::getline(std::cin, choice);
	std::cout << " " << std::endl;

	//user's input is validated and converted to an integer	
	valid_choice = int_input_val(choice);

	while (valid_choice < 1 || valid_choice > 2)
	{
		std::cout << "Oops! That isn't a valid selection. Please select 1 or 2" << std::endl;
		std::getline(std::cin, choice);
		valid_choice = int_input_val(choice);
	}
	
	//if user chooses to exit program
	if (valid_choice == 2)
	{
		std::cout << " " << std::endl;
		std::cout << "You selected quit. RuPaul is very disappointed..." << std::endl;
		std::cout << " " << std::endl;
	}
	
	//if user chooses to play game
	if (valid_choice == 1)
	{
		//display map
		obj -> display_map();
		
		//retrieve Player object and their starting health
		Player* p1 = obj -> get_player();
		int health = p1 -> get_health();
		
		//retrieve Purse object 
		Purse* purse1 = obj -> get_purse();
		
		//dynamically allocate 4 Item pointers to use as temporary storage of Purse items
		Item **content = new Item*[4];
		content[0] = NULL;
		content[1] = NULL;
		content[2] = NULL;
		content[3] = NULL;

		//continue the game while the player still has health points
		while (health > 0 && !game_over)
		{ 
			std::string use_item;
			int int_use_item;
	
			direction(obj);
	
			//check if game is still ongoing
			game_over = obj -> get_end_game();

			//update Purse contents
			content[0] = purse1 -> get_item(1);
			content[1] = purse1 -> get_item(2);
			content[2] = purse1 -> get_item(3);
			content[3] = purse1 -> get_item(4);

			//if there is at least 1 item in the purse ask player if wants to use any items
			if ((content[0] != NULL  || content[1] != NULL || content[2] != NULL || content[3] != NULL) && !game_over)
			{	
				//display purse contents
				std::cout << "~~~~~~~~PURSE CONTENTS~~~~~~~~" << std::endl;
				std::cout << " " << std::endl;
				purse1 -> display_purse();
				std::cout << " " << std::endl;
				std::cout << "Would you like to put on any items in your purse?" << std::endl;
				std::cout << "Press 1 for yes, or 2 for no" << std::endl;
				std::cout << " " << std::endl;
				std::getline(std::cin, use_item);
				std::cout << " " << std::endl;

				//user's input is validated and converted to an integer	
				int_use_item = int_input_val(use_item);

				while (int_use_item < 1 || int_use_item > 2)
				{
					std::cout << "Oops! That isn't a valid selection. Please select 1 or 2" << std::endl;
					std::getline(std::cin, use_item);
					int_use_item = int_input_val(use_item);
				}
	
				//if user chooses to use an item
				if (int_use_item == 1)
				{
					std::string item_no;
					int int_item_no;
		
					std::cout << " " << std::endl;
					std::cout << "What item number would you like to put on?" << std::endl;
					std::cout << " " << std::endl;
					std::getline(std::cin, item_no);
					std::cout << " " << std::endl;

					//user's input is validated and converted to an integer	
					int_item_no = int_input_val(item_no);
					
					//retrieve user's choice of item 
					Item *valid_item = purse1 -> get_item(int_item_no);

					while ((int_item_no < 1 || int_item_no > 4) || valid_item == NULL)
					{
						std::cout << "Oops! That isn't a valid selection. Please select another item" << std::endl;
						std::getline(std::cin, item_no);
						int_item_no = int_input_val(item_no);
					
						valid_item = purse1 -> get_item(int_item_no);
					}
					
					//call function of Purse class to use item
					purse1 -> use_item(int_item_no, p1);
				}
			
				//if user chooses not to use an item
				else
				{
					std::cout << "Ok! But remember, your purse can only hold 4 items at a time!" << std::endl;
					std::cout << " " << std::endl;
				}	
			}
		
			//update player's health after the previous move
			health = p1 -> get_health();	
		}
		//if player's health is 0 the game ends		
		if (health == 0)
		{
			std::cout << "Oh snap! Your feet have finally given out after walking in those heels!" << std::endl;
			std::cout << "... maybe stick to flats next time!" << std::endl;
			std::cout << " " << std::endl;
			std::cout << "**********GAME OVER**********" << std::endl;
			std::cout << " " << std::endl;
		}
		
		//free dynamically allocated memory assigned to content
		for (int i = 0; i < 4; i++)
		{
			if (content[i] != NULL)
			{	
				delete content[i];
			}
		}
		
		delete[]  content;	
	}

}

