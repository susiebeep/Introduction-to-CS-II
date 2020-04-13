/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class DressingRoom
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class DressingRoom
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "dressingroom.hpp"
#include "space.hpp"
#include "item.hpp"
#include "wig.hpp"
#include "purse.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the DressingRoom class sets the Space
		 pointer data members and Item pointer data member it inherited from
		 the Space class to null. It sets its bool data member enter to false
		 upon instantiation of a newly constructed DressingRoom object
 ** *******************************************************************************/ 

DressingRoom::DressingRoom()
{
	this -> top = NULL;
	this -> bottom = NULL;
	this -> left = NULL;
	this -> right = NULL;
	this -> item1 = NULL;
	this -> enter = false;
}

/********************************************************************************** 
 ** Description: The get_char function of the DressingRoom class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a char indicating the type of the Space object on the game map 
		 i.e. DressingRoom, represented by $
 ** *******************************************************************************/ 

char DressingRoom::get_char()
{
	return '$';	
}


/********************************************************************************** 
 ** Description: The get_type function of the DressingRoom class is an overridden 
		 function of the Space class. It takes no parameters and returns
		 a string indicating the type of the Space object i.e. DressingRoom
 ** *******************************************************************************/ 

std::string DressingRoom::get_type()
{
	return "RuPaul's Dressing Room";	
}



/********************************************************************************** 
 ** Description: The set_ready function of the DressingRoom class is an overridden 
		 function of the Space class. It has no return type and takes a 	
		 bool parameter which it uses to set its bool data member enter
 ** *******************************************************************************/ 

void DressingRoom::set_ready(bool input)
{
	this ->	enter = input;
}


/********************************************************************************** 
 ** Description: The is_ready function of the DressingRoom class is an overridden
		 function of the Space class. It takes no parameters and returns the
		 bool data member enter indicating if the player can enter RuPaul's
		 dressing room. They can only enter once they have found and used 
		 the Dress Item and Eyelashes Item
 ** *******************************************************************************/ 

bool DressingRoom::is_ready()
{
	if (!enter)
	{
		std::cout << "!!! RuPaul is not ready to see you yet! !!!" << std::endl;
		std::cout << "!!! You need to find and put on the Dress and Eyelashes before he will let you in !!!"
			  << std::endl;	
	}	
	else
	{
		std::cout << "~~~RuPaul is ready to see you now...~~~" << std::endl;
		std::cout << " " << std::endl;
	}

	return enter;	
}


