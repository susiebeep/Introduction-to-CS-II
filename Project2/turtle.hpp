/******************************************************************************* 
 ** Program Name: Class declaration for derived class Turtle
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the function prototypes of the child class
		  Turtle
 ** *******************************************************************************/ 
#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "animal.hpp"
#include <string>

class Turtle : public Animal
{
	public:
		Turtle();
		std::string get_type();
		Turtle(const Turtle &other); //copy constructor

};

#endif
