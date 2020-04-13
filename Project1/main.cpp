/******************************************************************************* 
 ** Program Name: Main program module for the Langton's Ant Simulation
 ** Author:       Susan Hibbert
 ** Date:         8 April 2019
 ** Description:  This is the main program module for the Langton's Ant Simulation.
		  A pointer to a Board object b1 is initiliazed to a dynamically
		  allocated Board object and an instance of the class Ant
		  called adam is created. These are passed as parameters to the
		  display_menu function.

		  The user's choice will be returned from the display_menu function.
		  If they selected 1, indicating that they wish to run the ant 
		  simulation, the Board and Ant objects will be initialized by values
		  input by the user. Once all the information is provided, the Board
		  member function move_ant is called to move the ant on the board.
		  Once completed, the dynamically allocated Board object is deleted
		  and a new Board object is created, pointed to by b1. The user will
		  then be asked if they wish to run the simulation again and the above
		  steps will repeat. If they selected 2, indicating they wish to quit
		  the program, the dynamically allocated Board object will be deleted
		  and b1 will be set to null
** Citations:	  C++ class object pointers and accessing member functions, 
		  Stackoverflow
 ** *******************************************************************************/ 
#include <iostream>
#include "board.hpp"
#include "ant.hpp"
#include "menu.hpp"

int main()
{

	Board *b1 = new Board;
	Ant adam;
	int choice = display_menu(b1, &adam);
	
	while (choice == 1)
	{
		b1 -> move_ant(&adam);
		delete b1;
		b1 = new Board;
		choice = display_menu(b1, &adam);
	}
	
	delete b1;
	b1 = NULL;

	return 0;
}
