/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Penguin class
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the member function definitions for the
		  derived Penguin class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis 	
 ** *******************************************************************************/ 
#include "penguin.hpp"
#include "animal.hpp"
#include <string>


/********************************************************************************** 
 ** Description: The default construtor for the Penguin class calls upon the default
		 constructor of the Animal parent class to initialize the member
		 variables of the newly created Penguin object
 ** *******************************************************************************/ 

Penguin::Penguin() : Animal()
{
	this -> age = 0;
	this -> cost = 1000.0;
	this -> number_of_babies = 5;
	this -> base_food_cost = 10.0;
	this -> payoff = 100;
}


/********************************************************************************** 
 ** Description: The get_type function of the Penguin class takes no parameters and
		 overrides the get_type function of the Animal class and returns the
		 string "Penguin" indicating the animal type
 ** *******************************************************************************/ 

std::string Penguin::get_type()
{
	return "Penguin";
}


/********************************************************************************** 
 ** Description: The copy constructpr of the Penguin class takes another Penguin
		 object passed by constant reference and copies its data members
		 and sets them to its own corresponding data members
 ** *******************************************************************************/ 

Penguin::Penguin(const Penguin &other)
{	
	this -> age = other.get_age();
	this -> cost = other.get_cost();
	this -> number_of_babies = other.get_babies();
	this -> base_food_cost = other.get_food();
	this -> payoff = other.get_payoff();

}


