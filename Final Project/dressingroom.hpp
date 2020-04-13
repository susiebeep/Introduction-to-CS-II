/******************************************************************************* 
 ** Program Name: Class declaration for the child class DressingRoom
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  DressingRoom
 ** *******************************************************************************/ 
#ifndef DRESSINGROOM_HPP
#define DRESSINGROOM_HPP
#include "space.hpp"
#include "item.hpp"
#include "purse.hpp"
	
class DressingRoom: public Space
{ 
	private:
		bool enter;

	public:
		DressingRoom();
		char get_char(); //overridden function of Space class
		std::string get_type(); //overridden function of Space class
		void set_ready(bool input); //overridden function of Space class
		bool is_ready(); //overridden function of the Space class
};

#endif
