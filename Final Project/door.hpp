/******************************************************************************* 
 ** Program Name: Class declaration for the child class Door
 ** Author:       Susan Hibbert
 ** Date:         30 May 2019
 ** Description:  This program contains the function prototypes for the child class
		  Door
 ** *******************************************************************************/ 
#ifndef DOOR_HPP
#define DOOR_HPP
#include "space.hpp"
	
class Door: public Space
{ 
		private:
			bool open;

		public:
			Door();
			char get_char(); //overridden function of Space class
			std::string get_type(); //overridden function of Space class
			void set_ready(bool input); //overridden function of Space class
			bool is_ready(); //overridden function of Space class
};

#endif
