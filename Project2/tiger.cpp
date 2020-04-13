/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Tiger class
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the member function definitions for the
		  derived Tiger class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
		  C++ discards qualifiers, Stack Overflow
 ** *******************************************************************************/ 
#include "tiger.hpp"
#include "animal.hpp"
#include <string>


/********************************************************************************** 
 ** Description: The default construtor for the Tiger class calls upon the default
		 constructor of the Animal parent class to initialize the member
		 variables of the newly created Tiger object
 ** *******************************************************************************/ 

Tiger::Tiger() : Animal()
{
	this -> age = 0;
	this -> cost = 10000.0;
	this -> number_of_babies = 1;
	this -> base_food_cost = 50.0;
	this -> payoff = 2000;
}


/********************************************************************************** 
 ** Description: The get_type function of the Tiger class takes no parameters and 
		 overrides the get_type function of the Animal class and returns
		 the string "Tiger" representing the animal type
 ** *******************************************************************************/ 

std::string Tiger::get_type()
{
	return "Tiger";
}


/********************************************************************************** 
 ** Description: The copy constructor of the Tiger class takes another Tiger object
		 passed by constant reference and copies its data members and sets
		 them to its own corresponding data members
 ** *******************************************************************************/ 

Tiger::Tiger(const Tiger &other)
{
	this -> age = other.get_age();
	this -> cost = other.get_cost();
	this -> number_of_babies = other.get_babies();
	this -> base_food_cost = other.get_food();
	this -> payoff = other.get_payoff();
}


