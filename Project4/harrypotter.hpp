/******************************************************************************* 
 ** Program Name: Class declaration for the child class Harry_Potter
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Harry_Potter
 ** *******************************************************************************/ 
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "character.hpp"
#include <string>
	
class Harry_Potter: public Character
{
	private:
		int life_count;	
 
	public:
		Harry_Potter();
		std::string get_type(); //overridden function of Character class
		int starting_strength(); //overridden function of Character class
		int defense(int attack); //overridden function of Character class
		int get_life_count();
		void set_life_count(int input_life);
};

#endif
