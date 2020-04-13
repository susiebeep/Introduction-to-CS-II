/******************************************************************************* 
 ** Program Name: Class declaration for the child class Mirror
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Mirror
 ** *******************************************************************************/ 
#ifndef MIRROR_HPP
#define MIRROR_HPP
#include "space.hpp"
	
class Mirror: public Space
{ 
	private:
		bool ready;

	public:
		Mirror();
		char get_char(); //overridden function of Space class
		std::string get_type(); //overridden function of Space class
		void set_ready(bool input); //overridden function of Space class
		bool is_ready(); //overridden function of the Space class
};

#endif
