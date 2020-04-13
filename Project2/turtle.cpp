/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Turtle class
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the member function definitions for the
		  derived Turtle class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "turtle.hpp"
#include "animal.hpp"
#include <string>


/********************************************************************************** 
 ** Description: The default construtor for the Turtle class calls upon the default
		 constructor of the Animal parent class to initialize the member
		 variables of the newly created Turtle object
 ** *******************************************************************************/ 

Turtle::Turtle() : Animal()
{
	this -> age = 0;
	this -> cost = 100.0;
	this -> number_of_babies = 10;
	this -> base_food_cost = 5.0;
	this -> payoff = 5;
}


/********************************************************************************** 
 ** Description: The get_type function of the Turtle class takes no parameters and
		 overrides the get_type function of the Animal class and returns the
		 string "Turtle" representing the animal type
 ** *******************************************************************************/ 

std::string Turtle::get_type()
{
	return "Turtle";
}


/********************************************************************************** 
 ** Description: The copy constructor of the Turtle class takes another Turtle
		 object passed by constant reference and copies its data members
		 and sets them to its own corresponding data members 
 ** *******************************************************************************/ 

Turtle::Turtle(const Turtle &other)
{
	this -> age = other.get_age();
	this -> cost = other.get_cost();
	this -> number_of_babies = other.get_babies();
	this -> base_food_cost = other.get_food();
	this -> payoff = other.get_payoff();


}


