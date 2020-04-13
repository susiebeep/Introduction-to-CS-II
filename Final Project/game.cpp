/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Game class
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the member function definitions for the Game
		  class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
		  Pointers to pointers and dynamic multidimensional arrays,
		  learncpp.com
		  3D array C++ using int[] operator, StackOverflow.com
		  Deleting 3D Dynamic Array C++, StackOverflow.com
 ** *******************************************************************************/ 
#include "space.hpp"
#include "studio.hpp"
#include "door.hpp"
#include "mirror.hpp"
#include "wall.hpp"
#include "dressingroom.hpp"
#include "player.hpp"
#include "game.hpp"
#include "item.hpp"
#include "ointment.hpp"
#include "dress.hpp"
#include "eyelashes.hpp"
#include "purse.hpp"
#include <iostream>
#include <string>

/********************************************************************************** 
 ** Description: The default construtor for the Game class sets it int data members
		 row and col to 10, making the game map a 10 x 10 grid. It sets its
		 Player pointer data member to null and dynamically allocates a new
		 Purse object to its Purse pointer data member purse. It sets its
		 bool data member end_game to false. It dynamically allocates an
		 array of 100 Space pointers to its 3D pointer data member space.
		 One Space pointer is assigned for each space on the grid
 ** *******************************************************************************/ 

Game::Game()
{
	row = 10;
	col = 10;
	player = NULL;
	purse = new Purse;
	end_game = false;

	//dynamically allocate an array of 100 Space pointers to 3D pointer space
	space = new Space**[row];
	for (int count = 0; count < row; count++)
	{	
		//iterate through the array of Space pointer pointers and allocate
		//each array element a Space pointer
		space[count] = new Space*[col];
	}
}


/********************************************************************************** 
 ** Description: The destructor of the Game class frees the dynamically allocated
		 memory assigned to the 100 Space pointers and the Purse pointer. It
		 is responsible for freeing all the dynamically allocated memory 
		 that is created during the running of the game
 ** *******************************************************************************/ 

Game::~Game()
{
	for (int i = 0; i < row; i++)
	{	
		for (int j = 0; j < col; j++)
		{
			if (space[i][j] != NULL)
			{
				//delete the Item object pointed to by that Space object
				Item* garbage = space[i][j] -> get_item();
				if (garbage != NULL)
				{
					delete garbage;
					space[i][j] -> set_item1(NULL);
					delete space[i][j];
				}
				else
				{
					delete space[i][j];
				}
			}
		}
		delete [] space[i];
	}

	delete[] space;

	//delete the Purse object
	delete purse;
}


/********************************************************************************** 
 ** Description: The initialize function of the Game class sets up the game map with
		 different Space objects, placing particular Space objects in certain
		 positions on the game map to make it look like a TV studio. It
		 takes no parameters and has no return type
 ** *******************************************************************************/ 

void Game::initialize()
{
	//assign the Space pointers and dynamically allocate each a Space object
	//depending on the location of the game map
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//place the Mirror objects
			if ((i == 1 || i == 8) && j == 9)	
			{
				space[i][j] = new Mirror;
			}
			else
			{
				//place the Door object
				if (i == 4 && j == 0)
				{
					space[i][j] = new Door;
				}
				else
				{	
					//place the DressingRoom object
					if (i == 4 && j == 8)
					{
						space[i][j] = new DressingRoom;
					}
					else
					{
	
						//place Wall objects - top wall
						if (i == 0 && (j >= 0 && j <= 9))
						{
							space[i][j] = new Wall;
						}
						else
						{	//place Wall objects - bottom wall
							if (i == 9 && (j >= 0 && j <= 9))
							{
								space[i][j] = new Wall;
							}
							else
							{
								//place Wall objects - left wall
								if (i != 4  &&  j == 0)
								{
									space[i][j] = new Wall;
								}
								else
								{
									//place Wall objects - right wall
									if ((i >= 2 && i <= 7)  &&  j == 9)
									{
										space[i][j] = new Wall;
									}
									//place Studio objects in remaining spaces
									else
									{		
										space[i][j] = new Studio;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



/********************************************************************************** 
 ** Description: The link function of the Game class takes no parameter and has no
		 return type. It links all the Space objects on the game map by 
		 setting each Space object's Space pointer data members top, bottom
		 left and right to its surrounding Space objects. Any unused Space
		 pointers are set to null
 ** *******************************************************************************/ 

void Game::link()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//link objects in top row, row 0
			if (i == 0)
			{
				//set their top pointers and bottom pointers	
				space[i][j] -> set_top(NULL);
				space[i][j] -> set_bottom(space[i + 1][j]);

				//first object in first row
				if (j == 0)
				{
					space[i][j] -> set_left(NULL);
					space[i][j] -> set_right(space[i][j + 1]);
				}
				else
				{
					//last object in first row
					if (j == 9)
					{	
						space[i][j] -> set_right(NULL);
						space[i][j] -> set_left(space[i][j - 1]);
	
					}
					//rest of the objects in the first row
					else
					{
						space[i][j] -> set_left(space[i][j - 1]);
						space[i][j] -> set_right(space[i][j + 1]);
					}
				}
			}
			else
			{	//link objects in bottom row, row 9
				if (i == 9)
				{
					//set their top pointers and bottom pointers	
					space[i][j] -> set_bottom(NULL);
					space[i][j] -> set_top(space[i - 1][j]);

					//first object in last row
					if (j == 0)
					{
						space[i][j] -> set_left(NULL);
						space[i][j] -> set_right(space[i][j + 1]);
					}

					//last object in last row
					else if (j == 9)
					{	
						space[i][j] -> set_right(NULL);
						space[i][j] -> set_left(space[i][j - 1]);
	
					}
					//rest of the objects in the last row
					else
					{
						space[i][j] -> set_left(space[i][j - 1]);
						space[i][j] -> set_right(space[i][j + 1]);
					}
				}
				else
				{	
					//link objects in first column, col 0
					if (j == 0 && (i > 0 && i < 9))
					{
						//set their pointers	
						space[i][j] -> set_left(NULL);
						space[i][j] -> set_right(space[i][j + 1]);
						space[i][j] -> set_top(space[i - 1][j]);
						space[i][j] -> set_bottom(space[i + 1][j]);
					}
					else
					{	
						//link objects in last column, col 9
						if (j == 9 && (i > 0 && i < 9))
						{
							//set their pointers	
							space[i][j] -> set_right(NULL);
							space[i][j] -> set_left(space[i][j - 1]);
							space[i][j] -> set_top(space[i - 1][j]);
							space[i][j] -> set_bottom(space[i + 1][j]);
						}
						else
						{
							//link objects in rest of game map
							space[i][j] -> set_top(space[i - 1][j]);
							space[i][j] -> set_bottom(space[i + 1][j]);
							space[i][j] -> set_left(space[i][j - 1]);
							space[i][j] -> set_right(space[i][j + 1]);
							
						}
					}
				}
			}
		}
	}
}


/********************************************************************************** 
 ** Description: The set_player function of the Game class has no return type and
		 takes a Player pointer as a parameter which it uses to set its
		 Player pointer data member player
 ** *******************************************************************************/ 

void Game::set_player(Player* input_player)
{
	this -> player = input_player;
}


/********************************************************************************** 
 ** Description: The get_player function of the Game class takes no parameters and
		 returns its Player pointer data member player
 ** *******************************************************************************/ 

Player* Game::get_player()
{
	return this -> player;
}



/********************************************************************************** 
 ** Description: The get_purse function of the Game class takes no parameters and
		 returns its Purse pointer data member purse
 ** *******************************************************************************/ 

Purse* Game::get_purse()
{
	return this -> purse;
}


/********************************************************************************** 
 ** Description: The place_player function of the Game class takes no parameters
		 and has no return type. It places the player on the game map at
		 row 1, column 1
 ** *******************************************************************************/ 

void Game::place_player()
{
	player -> set_row(1);
	player -> set_col(1);
}


/********************************************************************************** 
 ** Description: The get_end_game function of the Game class takes no parameters 
		 and returns its bool data member end_game, indicating if the player
		 has completed the game or not
 ** *******************************************************************************/ 

bool Game::get_end_game()
{
	return this -> end_game;
}


/********************************************************************************** 
 ** Description: The set_studio_items function of the Game class takes no parameters
		 and has no return type. It places the Item objects to be collected
		 as part of the game in the studio area of the game map. The Items
		 placed in the studio are 5 Ointment objects, 1 Dress object and 1
		 Eyelashes object
 ** *******************************************************************************/ 

void Game::set_studio_items()
{
	//create various Item objects
	Item *ointment1 = new Ointment;
	Item *ointment2 = new Ointment;
	Item* ointment3 = new Ointment;
	Item* ointment4 = new Ointment;
	Item* ointment5 = new Ointment;
	Item *dress1 = new Dress;
	Item *lashes = new Eyelashes;

	//place 5 x RuPaul's Magic Foot Ointment on game map
	space[7][2] -> set_item1(ointment1);
	space[2][3] -> set_item1(ointment2);	
	space[6][7] -> set_item1(ointment3);
	space[1][7] -> set_item1(ointment4);
	space[3][5] -> set_item1(ointment5);

	//place 1 x Dress
	space[4][1] -> set_item1(dress1);
	
	//place 1 x Eyelashes
	space[1][2] -> set_item1(lashes);
}


/********************************************************************************** 
 ** Description: The end_game function of the Game class is the function called 
		 after the player has made it through the stage door and completed
		 the game. The bool data member end_game is set to true as the
		 game has been completed
 ** *******************************************************************************/ 

void Game::game_over()
{
	std::cout << "....as you strut your stuff on stage, you can see that the" << std::endl;
	std::cout << "judges are clearly impressed. Why wouldn't they be?" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "As the rest of the Drag Queens prance around on stage, you" << std::endl;
	std::cout << "can't help but feel how much better you look than all of them" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "RuPaul: 'SILENCE! I've made my decision.....' " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "RuPaul: 'The winner of RuPaul's Drag Race and America's " << std::endl;
	std::cout << "         next Drag Superstar is..... '" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "* " << std::endl;
	std::cout << "*" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "RuPaul: 'Bob The Drag Queen!'" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "(shocked gasps and whispers)" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "I've been robbed! Oh well, there's always next year..." << std::endl;
	std::cout << " " << std::endl;
	std::cout << "*************************" << std::endl;
	std::cout << "********THE END!*********" << std::endl;
	std::cout << "***THANKS FOR PLAYING!***" << std::endl;
	std::cout << "*************************" << std::endl;
	std::cout << " " << std::endl;

	//set bool data member end_game to true as end of game reached
	end_game = true;
}


/********************************************************************************** 
 ** Description: The display_map function of the Game class takes no parameters and
		 has no return type. It displays the game map and it called after
		 each move made by the player. It includes the position of the player
		 on the game map. The function also displays the player's purse
		 contents and health stats and a list of the different symbols and
		 what Space object they represent on the game map
 ** *******************************************************************************/ 

void Game::display_map()
{	
	//find the player's position
	int user_row = player -> get_row();
	int user_col = player -> get_col();

	//display what each symbol in the game map means
	std::cout << "----------STUDIO MAP----------" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "o = you" << std::endl;
	std::cout << "* = wall" << std::endl;
	std::cout << ". = studio floor" << std::endl;
	std::cout << "# = mirror" << std::endl;
	std::cout << "/ = stage door" << std::endl;
	std::cout << "$ = RuPaul's dressing room" << std::endl;
	std::cout << " " << std::endl;		

	//display the game map including the current position of the player
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == user_row && j == user_col)
			{
				std::cout << 'o' << " ";
			}
			else
			{
				std::cout << space[i][j] -> get_char() << " ";
			}
		}

		std::cout << " " << std::endl;
	}
	std::cout << " " << std::endl;

	//tell user their health stats
	std::cout << "+++ Your current health is " << player -> get_health() 
		  << " points +++" << std::endl;
	std::cout << " " << std::endl;
}


/********************************************************************************** 
 ** Description: The move function of the Game class takes an int parameter,
		 between 1 and 4, indicating the direction the player has decided to
		 move (up, down, left or right). It returns a bool indicating it the
		 player was able to move successfully. The player will encounter
		 different scenarios depending on the direction they choose, their
		 location on the game map and what items they have collected and used
		 in the game so far
 ** *******************************************************************************/ 

bool Game::move(int input_move)
{
	//indicates whether player was able to move
	bool move = false;;

	//get the player's current coordinates on the game map
	int current_row = player -> get_row();
	int current_col = player -> get_col();

	//get the Space objects surrounding the player
	Space* north = space[current_row][current_col] -> get_top();
	Space* south = space[current_row][current_col] -> get_bottom();
	Space* west = space[current_row][current_col] -> get_left();
	Space* east = space[current_row][current_col] -> get_right();

	//check if any surrounding Space objects are wall objects
	bool wall_north = north -> is_wall();	
	bool wall_south = south -> is_wall();	
	bool wall_west = west -> is_wall();	
	bool wall_east = east -> is_wall();	


	//if user chooses to move up
	if (input_move == 1)
	{
		//if there isn't a wall above
		if (!wall_north)
		{
			//if RuPaul's Dressing Room is above
			if (north == space[4][8])
			{
				//check if they can enter the dressing room
				purse -> enter_dressingroom(north);

				bool open = north -> is_ready();
				
				//if unable to enter dressing room as not used Dress or Eyelashes
				if (!open)
				{
					move = false;
				}
				else
				{
					move = true;
					//call function to give player a wig and interact with RuPaul
					purse -> get_gift();
					display_map();
					//set bool in dressingroom to false so player cannot reenter
					bool open1 = false;
					north -> set_ready(open1);
				}
			}
		
			else
			{
				//move the player up one space
				player -> set_row(current_row - 1);
				player -> set_col(current_col);
		
				//player health declines
				player -> lose_health();
				
				//check for items
				north -> check_for_items(purse);
	
				move = true;

				//display_map
				display_map();
			}
		}

		//if there is a wall above
		else
		{
			std::cout << "***You've hit a wall!***" << std::endl;
			move = false;
		}
	}

	//if user chooses to move down
	else if (input_move == 2)
	{
		//if there isn't a wall below
		if (!wall_south)
		{
			//if RuPaul's Dressing Room is below
			if (south == space[4][8])
			{
				//check if can enter dressing room
				purse -> enter_dressingroom(south);

				bool open = south -> is_ready();
				
				//if unable to enter dressing room as not used Dress or Eyelashes
				if (!open)
				{
					move = false;
				}
				else
				{
					move = true;
					//call function to give player a wig and interact with RuPaul
					purse -> get_gift();
					display_map();

					//set bool in dressingroom to false so player cannot reenter
					bool open1 = false;
					south -> set_ready(open1);	
				}
			}

			else
			{
				//move player down one space
				player -> set_row(current_row + 1);
				player -> set_col(current_col);
		
				//player health declines
				player -> lose_health();
			
				//check for items
				south -> check_for_items(purse);

				move = true;			

				//display_map
				display_map();
			}
		}

		//if there is a wall below
		else
		{
			std::cout << "***You've hit a wall!***" << std::endl;
			move = false;
		}
	}

	//if user chooses to move left
	else if (input_move == 3)
	{
		//if there isn't a wall to the left
		if (!wall_west)
		{
			//if the stage door is to the left
			if (west == space[4][0])
			{
				//check if stage door is open
				bool open = west -> is_ready();
				
				//if not open as not interacted with mirror after using wig
				if (!open)
				{	
					move = false;
				}
				//if stage door is open, game ends
				else
				{
					game_over();
				}
			}
			else
			{
				//move the player one space to the left
				player -> set_row(current_row);
				player -> set_col(current_col - 1);
			
				//player health declines
				player -> lose_health();
				
				//check for items
				west -> check_for_items(purse);

				move = true;

				//display_map
				display_map();
			}
		}
		//if there is a wall to the left
		else
		{
			std::cout << "***You've hit a wall!***" << std::endl;
			move = false;
		}
	}

	//if user chooses to move right
	else if (input_move == 4)
	{	
		//if there isn't a wall to the right
		if (!wall_east)
		{
			//if there is a mirror to the right
			if (east == space[1][9] || east == space[8][9])	
			{
				//check if new interaction available with mirror
				purse -> check_mirror(east);
	
				bool ready = east -> is_ready();
				
				//if new interaction not available as not wearing wig
				if (!ready)
				{
					move = false;
				}
				else
				{
					move = true;
					//set Stage Door to open
					bool open = true;
					space[4][0] -> set_ready(open);
					display_map();
				}
			}

			//if RuPaul's Dressing Room is to the right
			else if (east == space[4][8])
			{	//check if can enter
				purse -> enter_dressingroom(east);

				bool open = east -> is_ready();
				
				//if unable to enter as not used Dress or Eyelashes
				if (!open)
				{
					move = false;
				}
				else
				{
					move = true;

					//call function to give player a wig and interact with RuPaul
					purse -> get_gift();
					display_map();

					//set bool in dressingroom to false so player cannot reenter
					bool open1 = false;
					east -> set_ready(open1);
				}
			}
			else
			{	//move player one space to right
				player -> set_row(current_row);
				player -> set_col(current_col + 1);
			
				//player's health declines
				player -> lose_health();
			
				//check for items
				east -> check_for_items(purse);

				move = true;
	
				//display map
				display_map();
			}
		}
		//if there is a wall to the right
		else
		{
			std::cout << "***You've hit a wall!***" << std::endl;
			move = false;
		}
	}
	
	return move;
}
