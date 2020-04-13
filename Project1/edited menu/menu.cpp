/******************************************************************************* 
 ** Program Name: Source code for the display_menu function used in Langton's Ant Simulation
 ** Author:       Susan Hibbert
 ** Date:         5 April 2019
 ** Description:  This program contains the function definition for the display_menu
		  function which is called by the main module of the ant simulation program.	
		 
		  It takes two parameters - a pointer to a Board object and a pointer to an
		  Ant object, created in the main program of the ant simulation program.
	
		  This function prints two options on the screen for the user (run program
		  or quit). After the user inputs their choice, it is validated by an input
		  validation function which returns their input as an integer. If the user
		  does not select a valid menu option they will be prompted until they make
		  a valid selection.
		
		  The program will quit if the user selected this option, otherwise the user
		  will be prompted to enter all the information needed to run the ant
		  simulation program. Their input will be validated at each step with an
 		  input validation function which returns their input as an integer. 

		  At each step, the integer returned from the input validation function
		  will be used as a parameter in a Board member function to set
		  the data members of the Board and Ant objects passed to the menu
		  function. The board size, the number of steps and the ant's position
		  and initial direction will be displayed on screen after the user sets
		  the values. Should they enter erroneous values for any of these values,
		  the default value (determined by each member function) will be set
		  and displayed to the user.
			
		  At the end of the function, the user's menu choice will be returned to
		  the main program of the ant simulation. 
 ** Citations:    Chapter 4.5, Menu-Driven Programs, and
                  Chapter 6.9, Using Functions in a Menu-Driven Programs, Starting Out
		  With C++ Early Objects 9th Edition;
		  5.10 std::cin, extraction, and dealing with invalid text input, 
		  LearnCPP.com
 ** *******************************************************************************/ 
#include <iostream>
#include <string>
#include "menu.hpp"
#include "board.hpp"
#include "ant.hpp"
//#include "input.hpp"

int display_menu(Board *b1, Ant *adam)
{
	std::string choice;
	std::string total_row;
	std::string total_col;
	std::string total_steps;
	std::string start_row;
	std::string start_col;
	int valid_choice;
	int rows0;
	int rows1;
	int cols0;
	int cols1;
	int steps0;
	int steps1;
	int input_row;
	int input_col;

	std::cout << "Welcome to Langton's Ant Simulation!" << std::endl;
	std::cout << "1. Start Langton's Ant Simulation" << std::endl;
	std::cout << "2. Quit program" << std::endl; 
	std::cout << "Press 1 to start or press 2 to quit then enter" << std::endl;
	std::cin >> choice;

	
	//user's input is validated and converted to an integer	
	//valid_choice = int_input_val(choice);

	
	if (choice == 2)
	{
		std::cout << "You selected quit. Goodbye!" << std::endl;
	}
	
	if (choice == 1)
	{
		std::cout << "Enter the number of rows for the board: " << std::endl;
		std::cin >> total_row;
 
		//user's input is validated and converted to an integer
		//rows0 = int_input_val(total_row);		
		
		std::cout << "Enter the number of columns for the board: " << std::endl;
		std::cin >> total_col;

		//user's input is validated and converted to an integer
		//cols0 = int_input_val(total_col);
		
		//board object is initialized with the number of rows and columns specified
		//by the user	
		b1 -> initialize(total_row, total_col);
		
		rows1 = b1 -> get_rows();
		cols1 = b1 -> get_cols();
			
		std::cout << "Setting rows to " << rows1 << " and columns to " << cols1 << std::endl;
		std::cout << " " << std::endl;

		std::cout << "Enter the number of steps for the simulation: " << std::endl;
		std::cin >> total_steps;

		//user's input is validated and converted to an integer
		//steps0 = int_input_val(total_steps);
	
		//number of steps the ant will take is passed to the Board object to
		//initialize its data member steps
		b1 -> set_steps(total_steps);
		steps1 = b1 -> get_steps();

		std::cout << "Setting the number of steps to " << steps1 << std::endl;
		std::cout << " " << std::endl;

		std::cout << "Enter the starting row of the ant: " << std::endl;
		std::cin >> start_row;
		
		//user's input is validated and converted to an integer
		//input_row = int_input_val(start_row);		

		std::cout << "Enter the starting column of the ant: " << std::endl;
		std::cin >> start_col;

		//user's input is validated and converted to an integer
		input_col = int_input_val(start_col);
			
		//ant is placed on the board at the specified location
		b1 -> place_ant(adam, start_row, start_col); 
	}	


	return valid_choice;

}

