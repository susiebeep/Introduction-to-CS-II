/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Studio
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Studio
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "studio.hpp"
#include "space.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default constructor for the Studio class sets the Space pointer
		 data members and Item pointer data member it inherited from the
		 Space class to null upon instantiation of a newly constructed Studio
		 object
 ** *******************************************************************************/ 

Studio::Studio()
{
	this -> top = NULL;
	this -> bottom = NULL;
	this -> left = NULL;
	this -> right = NULL;
	this ->	item1 = NULL;
}

/********************************************************************************** 
 ** Description: The get_char function of the Studio class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a char indicating the type of the Space object on the game map i.e.
		 Studio, represented by .
 ** *******************************************************************************/ 

char Studio::get_char()
{
	if (item1 == NULL)
	{
		return '.';
	}
	//if there is an item in the Studio object, display the Item's symbol
	//instead
	else
	{
		return item1 -> get_symbol();
	}
}


/********************************************************************************** 
 ** Description: The get_type function of the Studio class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a string indicating the type of the Space object i.e. Studio
 ** *******************************************************************************/ 

std::string Studio::get_type()
{
	return "Studio";
}

