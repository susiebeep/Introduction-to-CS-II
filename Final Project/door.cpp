/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Door
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Door
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "door.hpp"
#include "space.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the Door class sets the Space pointer
		 data members and the Item pointer data member it inherited from the
		 Space class to null and sets its bool data member open to false
		 upon instantiation of a newly constructed Door object
 ** *******************************************************************************/ 

Door::Door()
{
	this -> top = NULL;
	this -> bottom = NULL;
	this -> left = NULL;
	this -> right = NULL;
	this -> item1 = NULL;
	this -> open = false;
}


/********************************************************************************** 
 ** Description: The get_char function of the Door class is an overridden function
		 of the Space class. It takes no parameters and returns a char
		 indicating the type of the Space object on the game map 
		 i.e. Door, represented by /
 ** *******************************************************************************/ 

char Door::get_char()
{
	return '/';	
}


/********************************************************************************** 
 ** Description: The get_type function of the Door class is an overridden function
		 of the Space class. It takes no parameters and returns a string
		 indicating the type of the Space object i.e. Door
 ** *******************************************************************************/ 

std::string Door::get_type()
{
	return "Stage Door";	
}


/********************************************************************************** 
 ** Description: The set_ready function of the Door class is an overridden function
		 of the Space class. It has no return type and takes a bool
		 parameter which it uses to set its bool data member open
 ** *******************************************************************************/ 

void Door::set_ready(bool input)
{
	this -> open = input;
}


/********************************************************************************** 
 ** Description: The is_ready function of the Door class is an overridden function
		 of the Space class. It takes no parameters and returns the bool data
		 member open indicating if the Door object is open and the player
		 can move through it to complete the game
 ** *******************************************************************************/ 

bool Door::is_ready()
{
	if (!open)
	{
		std::cout << "---You aren't ready to go on stage yet!---" << std::endl;
		std::cout << "---Have you checked yourself in the Mirror lately?---"
			   << std::endl;
		std::cout << " " << std::endl;
	}
	else
	{
		std::cout << "***Time to hit the stage!***" << std::endl;
		std::cout << " " << std::endl;
	}

	return open;
}
