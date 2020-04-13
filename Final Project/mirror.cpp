/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Mirror
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Mirror
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "mirror.hpp"
#include "space.hpp"
#include "game.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the Mirror class sets the Space pointer
		 data members and Item pointer data member it inherited from the
		 Space class to null and sets its bool data member ready to false
		 upon instantiation of a newly constructed Mirror object
 ** *******************************************************************************/ 

Mirror::Mirror()
{
	this -> top = NULL;
	this -> bottom = NULL;
	this -> left = NULL;
	this -> right = NULL;
	this -> item1 = NULL;
	this ->	ready = false;
}


/********************************************************************************** 
 ** Description: The get_char function of the Mirror class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a char indicating the type of the Space object on the game map 
		 i.e. Mirror, represented by #
 ** *******************************************************************************/ 

char Mirror::get_char()
{
	return '#';	
}


/********************************************************************************** 
 ** Description: The get_type function of the Mirror class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a string indicating the type of the Space object i.e. Mirror
 ** *******************************************************************************/ 

std::string Mirror::get_type()
{
	return "Mirror";
}


/********************************************************************************** 
 ** Description: The set_ready function of the Mirror class is an overridden
		 function of the Space class. It has no return type and takes a bool
		 parameter which it uses to set its bool data member ready
 ** *******************************************************************************/ 

void Mirror::set_ready(bool input)
{
	this -> ready = input;
}


/********************************************************************************** 
 ** Description: The is_ready function of the Mirror class is an overridden function
		 of the Space class. It takes no parameters and returns the bool
		 data member ready indicating if the player can interact with the
		 Mirror object. They can only interact with the Mirror object if 
		 have gotten and used the Wig Item from RuPaul in his dressing room
 ** *******************************************************************************/ 

bool Mirror::is_ready()
{
	if (!ready)
	{
		std::cout << "***You do not look ready to go on stage yet!***" << std::endl;
		std::cout << "***Have you been to see RuPaul yet?***" << std::endl;
		std::cout << " " << std::endl;
	}
	else
	{
		std::cout << "~~~You look AMAZING! Go to the Stage door before you miss your time slot!~~~" << std::endl;
		std::cout << " " << std::endl;
	}
	return ready;
}


