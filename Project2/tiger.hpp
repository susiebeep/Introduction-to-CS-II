/******************************************************************************* 
 ** Program Name: Class declaration for derived class Tiger
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the function prototypes of the child class
		  Tiger
 ** *******************************************************************************/ 
#ifndef TIGER_HPP
#define TIGER_HPP
#include "animal.hpp"
#include <string>

class Tiger : public Animal
{
	public:
		Tiger();
		std::string get_type();
		Tiger(const Tiger &other); //copy constructor
};

#endif
