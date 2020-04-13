/******************************************************************************* 
 ** Program Name: Class declaration for the child class Studio
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Studio
 ** *******************************************************************************/ 
#ifndef STUDIO_HPP
#define STUDIO_HPP
#include "space.hpp"
#include "item.hpp"
	
class Studio: public Space
{ 
	public:
		Studio();
		char get_char(); //overridden function of Space class
		std::string get_type(); //overridden function of Space class
};

#endif
