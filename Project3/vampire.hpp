/******************************************************************************* 
 ** Program Name: Class declaration for the child class Vampire
 ** Author:       Susan Hibbert
 ** Date:         2 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Vampire
 ** *******************************************************************************/ 
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "character.hpp"

	
class Vampire: public Character
{ 
	public:
		Vampire();
		std::string get_type(); //overridden function of Character class
		int attack(); //overridden function of Character class
		int defense(int attack); //overridden function of Character class
};

#endif
