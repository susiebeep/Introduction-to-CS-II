/******************************************************************************* 
 ** Program Name: Class declaration for derived class Penguin
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the function prototypes of the child class
		  Penguin
 ** *******************************************************************************/ 
#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "animal.hpp"
#include <string>

class Penguin : public Animal
{
	public:
		Penguin();
		std::string get_type();
		Penguin(const Penguin &other); //copy constructor
};

#endif
