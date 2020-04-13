/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Wall
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Wall
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "wall.hpp"
#include "space.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the Wall class sets the Space pointer
		 data members and Item pointer data member it inherited from the
		 Space class to null upon instantiation of a newly constructed Wall
		 object
 ** *******************************************************************************/ 

Wall::Wall()
{
	this -> top = NULL;
	this -> bottom = NULL;
	this -> left = NULL;
	this -> right = NULL;
	this -> item1 = NULL;
}


/********************************************************************************** 
 ** Description: The get_char function of the Wall class is an overridden function
		 of the Space class. It takes no parameters and returns a char
		 indicating the type of the Space object on the game map 
		 i.e. Wall, represented by * 
 ** *******************************************************************************/ 

char Wall::get_char()
{
	return '*';	
}


/********************************************************************************** 
 ** Description: The get_type function of the Wall class is an overridden function
		 of the Space class. It takes no parameters and returns a string
		 indicating the type of the Space object i.e. Wall
 ** *******************************************************************************/ 

std::string Wall::get_type()
{
	return "Wall";
}


/********************************************************************************** 
 ** Description: The is_wall function of the Wall class is an overridden function 
		 of the Space class. It takes no parameters and returns the bool
		 'true' indicating that the Space object is a Wall object
 ** *******************************************************************************/ 

bool Wall::is_wall()
{
	return true;
}


/********************************************************************************** 
 ** Description: The is_ready function of the Wall class is an overridden function 
		 of the Space class. It takes no parameters and returns the bool
		 false indicating that the player cannot move into or interact with
		 Wall objects
 ** *******************************************************************************/ 

bool Wall::is_ready()
{
	return false;
}
