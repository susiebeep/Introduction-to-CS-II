/******************************************************************************* 
 ** Program Name: Class declaration for the child class Barbarian
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
 ** Description:  This program contains the function prototypes for the child class
		  Barbarian
 ** *******************************************************************************/ 
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"
#include <string>
	
class Barbarian: public Character
{		
 
	public:
		Barbarian();
		std::string get_type(); //overridden function of Character class
};

#endif
