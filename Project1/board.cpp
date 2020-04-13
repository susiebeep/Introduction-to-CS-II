/******************************************************************************* 
 ** Program Name: Source file/Class declaration for the Board class
 ** Author:       Susan Hibbert
 ** Date:         8 April 2019
 ** Description:  This program contains the function definitions of the Board
		  class 
 ** Citations:	  Chapter 10 Pointers, Starting Out with C++ Early Objects 9th Edition,
		  6.14, Pointers to pointer and dynamic multidimensional array, learncpp.com 
		  Passing a 2D array to a C++ function, Stackoverflow.com
 ** *******************************************************************************/ 
#include <iostream>
#include "board.hpp"
#include "ant.hpp"


/********************************************************************************** 
 ** Description: The Board default constructor sets the pointer-to-a-pointer array
		 and the pointer-to-an-ant-object mr_ant to NULL and sets the data 
		 members steps, row and col to -1. The default constructor is 
		 called upon creation of a Board object and has no parameters or
		 return type 
 ** *******************************************************************************/ 

Board::Board()
{
	array = NULL;
	mr_ant = NULL;
	row = -1;
	col = -1;
	steps = -1;

}

/********************************************************************************** 
 ** Description: The Board destructor frees dynamically allocated memory used by
		 the initialize function unless the dynamically alloctated memory
		 was previously freed (ie. the pointer array is set to NULL)
 ** *******************************************************************************/ 

Board::~Board()
{
	if (array != NULL)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] array[i];
		}
	
		delete[] array;
	}
}


/********************************************************************************** 
 ** Description: The initialize function sets up the board for the ant simulation.
		 The function takes two int parameters to set the row and col member
		 variables, which represent the total number of rows and columns of
		 the board. If the value entered for row is less than or equal to 1
		 the row is set to 10 by default, and if the value is greater than
		 100 row is set to 100 by default. This is the same for col. A 2D
		 dynamically allocated char array is created based on the specified
		 number of rows and columns which represents the board in the ant
		 simulation. Each element or space on the board is initialized to
		 contain a 'white space' as per the specification of the ant
		 simulation. There is no return type		
 ** *******************************************************************************/ 

void Board::initialize(int total_row, int total_col)
{
	row = total_row;
	col = total_col;
	
	if (row <= 1)	
	{
		row = 10;
	}
	if (row > 100)
	{
		row = 100;
	}
	if (col <= 1) 
	{
		col = 10;
	}
	if (col > 100)
	{
		col = 100;
	}

	//dynamically allocate a 2D char array
	array = new char*[row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new char[col];
	}
	
	//initialize the 2D char array
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = ' ';			
		}
	}
}


/********************************************************************************** 
 ** Description: The get_rows function takes no parameters and returns the int
		 member variable row representing the total number of rows in the
		 board
 ** *******************************************************************************/ 

int Board::get_rows()
{
	return row;
}


/********************************************************************************** 
 ** Description: The get_cols function takes no parameters and returns the int
		 member variable col representing the total number of columns in
		 the board
 ** *******************************************************************************/ 

int Board::get_cols()
{
	return col;
}


/********************************************************************************** 
 ** Description: The display_board function displays the 2D char array which represents
		 the board in the ant simulation. It calls two member functions
		 of the Ant class to find the current position of the ant, printing
		 a '*' on the board to represent the ant's current location. 'White
		 spaces' are  represented by a ' ' and 'black spaces' are represented
		 by a '#'. There is no return type 
 ** *******************************************************************************/ 

void Board::display_board()
{
	//find the current position of the ant on the board
	int ant_row = mr_ant -> get_row();
	int ant_col = mr_ant -> get_col();
	
	//display the contents of the board including
	//the current position of the ant
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == ant_row && j == ant_col)
			{		
				std::cout << '*' << " ";
			}						
			else
			{
				std::cout << array[i][j] << " ";
			}
		}
	
		std::cout << " " << std::endl;
	}

}


/********************************************************************************** 
 ** Description: The set_steps function determines how many steps the ant will take
		 on the board during the simulation. The function takes an int
		 parameter representing the number of steps the ant will take in the
		 simulation and uses this value to set the member variable steps. If
		 the value passed as a parameter is less than 0 steps defaults to 10,
		 and if the value is greater than 10000 steps defaults to 10000. 
		 There is no return type
 ** *******************************************************************************/ 
	
void Board::set_steps(int input_steps)
{
	if (input_steps <= 0)
	{
		input_steps = 10;
		steps = input_steps;
	}
	if (input_steps > 10000)
	{	
		input_steps = 10000;
		steps = input_steps;
	}
	else
	{
		steps = input_steps;	
	}
}


/********************************************************************************** 
 ** Description: The get_steps function has no parameters and returns the int
		 member variable steps representing the number of steps the ant
		 will take in the simulation 
 ** *******************************************************************************/ 

int Board::get_steps()
{
	return steps;
}


/********************************************************************************** 
 ** Description: The place_ant function places the ant on the board. It takes 3 
		 parameters - a pointer to an Ant object, and two integers representing
		 the row and column at which to place the ant. The default direction of
		 the ant is set to 'W' (west) by calling the set_direction member
		 function of the Ant class. If the row and column entered are within the
		 confines of the board, the starting row and column of the ant are set
		 by calling the set_row and set_col member functions of the Ant class.
		 If the ant is placed outside the board, the ant will be placed in the
		 centre of the board by default. After the ant is placed, its position
		 on the board and direction will be displayed for the user. There is
		 no return type
 ** *******************************************************************************/ 

void Board::place_ant(Ant *input_ant, int input_row, int input_col)
{
	mr_ant = input_ant;
	mr_ant -> set_direction('W');

	if (input_row <= row && input_row >= 0)
	{	
		mr_ant -> set_row(input_row);	
	}
	if (input_col <= col && input_col >= 0)
	{
		mr_ant -> set_col(input_col);
	}
	if (input_row > row || input_row < 0)
	{
		mr_ant -> set_row(row/2);
	}
	if (input_col > col || input_col < 0)
	{
		 mr_ant -> set_col(col/2);
	}
	

	int ant_row = mr_ant -> get_row();
	int ant_col = mr_ant -> get_col();

	std::cout << " " << std::endl;
	std::cout << "The ant is on the board at row " << ant_row << " and column " << ant_col << std::endl;
	std::cout << "Ant's Initial Direction: W" << std::endl;
	std::cout << " " << std::endl;
}


/********************************************************************************** 
 ** Description: The move_ant function implements the rules of Langton's Ant. The
		 function takes a pointer to an Ant object as a parameter and accesses
		 member functions of the Ant class to determine the ant's current
		 direction and position on the board. If the ant is on a white space,
		 it turns right 90 degrees, the space it's on changes to black and
		 it takes one step forward in its new direction. If the ant is on a
		 black space, it turns left 90 degrees, the space it's on changes to
		 white and it takes one step forward in its new direction. The ant
		 will follow these rules until it has completed the total number
		 of steps. The number of steps taken by the ant is being tracked by 
		 the variable count, which gets incremented after each step.
		
		 If the ant moves off the board during one of the steps, the board
		 will wrap around and the ant will appear on the other side of the	
		 board. There is no return type
 ** *******************************************************************************/ 

void Board::move_ant(Ant *input_ant)
{	
	mr_ant = input_ant;
	char direction = mr_ant -> get_direction();
	int ant_row = mr_ant -> get_row();
	int ant_col = mr_ant -> get_col();

	//initialize the loop counter to keep track of the ant's steps
	int count = 1; 

	while (count <= steps)
	{
		//if the ant is on a white space	
		if (array[ant_row][ant_col] == ' ')
		{

			if (direction == 'W')
			{
			
				array[ant_row][ant_col] = '#';			
				direction = 'N';
				ant_row = ant_row - 1;
				ant_col = ant_col;
		
			}
		
			else if (direction == 'N')
			{
			
				array[ant_row][ant_col] = '#';			
				direction = 'E';
				ant_col = ant_col + 1;
				ant_row = ant_row;
			
			}

			else if (direction == 'E')
			{
				
				array[ant_row][ant_col] = '#';			
				direction = 'S';
				ant_row = ant_row + 1;
				ant_col = ant_col;
				
			}
		
			else if (direction == 'S')
			{
				
				array[ant_row][ant_col] = '#';			
				direction = 'W';
				ant_col = ant_col - 1;
				ant_row = ant_row;
				
			}		

			if (ant_row >= row)
			{
				ant_row = 0;
			}
			if (ant_col >= col)
			{
				ant_col = 0;
			}
			if (ant_row < 0)
			{	
				ant_row = row - 1;
			}
			if (ant_col < 0)
			{	
				ant_col = col - 1;
			}

			mr_ant -> set_row(ant_row);
			mr_ant -> set_col(ant_col);
	
			//display the board after each step
			Board::display_board();

			std::cout << "Step number: " << count << std::endl;
			std::cout << "Ant's Direction: " << direction << std::endl; 
			std::cout << " " << std::endl;
			count++;
		}

		//if the ant is on a black space
		else
		{
			
			if (direction == 'W')
			{
				
				array[ant_row][ant_col] = ' ';			
				direction = 'S';
				ant_row = ant_row + 1;
				ant_col = ant_col;
			
			}
		
			else if (direction == 'N')
			{
				
				array[ant_row][ant_col] = ' ';			
				direction = 'W';
				ant_col = ant_col - 1;
				ant_row = ant_row;
			
			}

			else if (direction == 'E')
			{
				
				array[ant_row][ant_col] = ' ';			
				direction = 'N';
				ant_row = ant_row - 1;
				ant_col = ant_col;
				
			}
		
			else if (direction == 'S')
			{
				
				array[ant_row][ant_col] = ' ';			
				direction = 'E';
				ant_col = ant_col + 1;
				ant_row = ant_row;
			
			}
		
			if (ant_row >= row)
			{
				ant_row = 0;
			}
			if (ant_col >= col)
			{
				ant_col = 0;
			}
			if (ant_row < 0)
			{	
				ant_row = row - 1;
			}
			if (ant_col < 0)
			{	
				ant_col = col - 1;
			}

			mr_ant -> set_row(ant_row);
			mr_ant -> set_col(ant_col);

			//display the board after each ant's step
			Board::display_board();

			std::cout << "Step number: " << count << std::endl; 
			std::cout << "Ant's Direction: " << direction << std::endl;
			std::cout << " " << std::endl;
			count++;
		}
	}

}







