/******************************************************************************* 
 ** Program Name: Class declaration for the child class Blue_Men
 ** Author:       Susan Hibbert
 ** Date:         2 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Blue_Men
 ** *******************************************************************************/ 
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "character.hpp"

	
class Blue_Men: public Character
{ 
	public:
		Blue_Men();
		std::string get_type(); //overridden function of Character class
		int attack(); //overridden function of Character class
		int defense(int attack); //overridden function of Character class
};

#endif
