/******************************************************************************* 
 ** Program Name: Class declaration for the child class Wall
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Wall
 ** *******************************************************************************/ 
#ifndef WALL_HPP
#define WALL_HPP
#include "space.hpp"
	
class Wall: public Space
{
 	public:
		Wall();
		char get_char(); //overridden function of Space class
		std::string get_type(); //overridden function of Space class
		bool is_wall(); //overridden function of Space class
		bool is_ready(); //overridden function of Space class
};

#endif
