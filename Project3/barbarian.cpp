/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Barbarian
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
 ** Description:  This program contains the member function definitions for the
		  child class Barbarian. The Barbarian subclass uses the default
		  attack and defense functions of the Character base class. 
		  Barbarians have no special abilities.
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "barbarian.hpp"
#include "character.hpp"
#include <string>

/********************************************************************************** 
 ** Description: The default construtor for the Barbarian class sets its int data
		 members, armor and strength_points, it inherited from the Character
		 class, to default values upon instantiation of a newly constructed 
		 Barbarian object
 ** *******************************************************************************/ 

Barbarian::Barbarian()
{
	this -> set_strength_points(12);
	this -> set_armor(0);
}


/********************************************************************************** 
 ** Description: The get_type function of the Barbarian class is an overridden 
		 function of the Character class. It takes no parameters and returns
		 a string indicating the type of the Character object i.e. Barbarian
 ** *******************************************************************************/ 

std::string Barbarian::get_type()
{
	return "Barbarian";
	
}
