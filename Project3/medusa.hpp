/******************************************************************************* 
 ** Program Name: Class declaration for the child class Medusa
 ** Author:       Susan Hibbert
 ** Date:         2 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Medusa
 ** *******************************************************************************/ 
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"

	
class Medusa: public Character
{ 
	public:
		Medusa();
		std::string get_type(); //overridden function of Character class
		int attack(); //overridden function of Character class
		int defense(int attack); //overridden function of Character class
};

#endif
