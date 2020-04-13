/********************************************************************************** 
 ** Program Name: Source file/Class Declaration for the Ant class
 ** Author:       Susan Hibbert
 ** Date:         8 April 2019
 ** Description:  This program contains the function definitions for the Ant class
 ** *******************************************************************************/ 
#include "ant.hpp"
#include <iostream>


/********************************************************************************** 
 ** Description: The get_direction function has no parameters and returns a char
		 representing the direction of the ant on the board ('N' = north,
		 'S' = south, 'E' = east, 'W' = west)
 ** *******************************************************************************/ 

char Ant::get_direction()
{
	return ant_direction;
}


/********************************************************************************** 
 ** Description: The set_direction function has no return type and takes a char
		 parameter representing the ant's direction on the board which it 
		 uses to set the member variable ant_direction
 ** *******************************************************************************/ 

void Ant::set_direction(char input_direction)
{
	ant_direction = input_direction;
}


/********************************************************************************** 
 ** Description: The set_row function has no return type and takes an int parameter
		 representing a row on the board which is used to set the member
		 variable ant_row
 ** *******************************************************************************/ 

void Ant::set_row(int input_row)
{
	ant_row = input_row;
}	


/********************************************************************************** 
 ** Description: The set_col function has no return type and takes an int parameter
		 representing a column on the board which is used to set the member
		 variable ant_col
 ** *******************************************************************************/ 

void Ant::set_col(int input_col)
{
	ant_col = input_col;
}


/********************************************************************************** 
 ** Description: The get_row function has no parameters and returns the int member
		 variable ant_row which represents the row the ant is on on the board
 ** *******************************************************************************/ 

int Ant::get_row()
{
	return ant_row;
}


/********************************************************************************** 
 ** Description: The get_col function has no parameters but returns the int member
		 variable ant_col which represents the column the ant is on on the
		 board
 ** *******************************************************************************/ 

int Ant::get_col()
{
	return ant_col;
}
