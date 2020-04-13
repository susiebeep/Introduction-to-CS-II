/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Animal class
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the member function definitions for the Animal
		  class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "animal.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the Animal class initializes the member
		 variables of the newly	constructed Animal object
 ** *******************************************************************************/ 

Animal::Animal()
{
	this -> age = 0;
	this -> cost = 0.0;
	this -> number_of_babies = 0;
	this -> base_food_cost = 10.0;
	this -> payoff = 0.0;
}


/********************************************************************************** 
 ** Description: The get_type function of the Animal class takes no parameters and
		 returns a string indicating the type of the Animal object
 ** *******************************************************************************/ 

std::string Animal::get_type() const
{
	return "Animal";
}


/********************************************************************************** 
 ** Description: The get_age function of the Animal class takes no parameters and 
		 returns the int member variable age representing the age of the
		 Animal object in days
 ** *******************************************************************************/ 

int Animal::get_age() const
{
	return this -> age;
}


/********************************************************************************** 
 ** Description: The set_age function of the Animal class takes one int parameter
		 representing the age of the Animal object in days and uses it to
		 set the int member variable age of the Animal object
 ** *******************************************************************************/ 

void Animal::set_age(int new_age)
{
	this -> age = new_age;
}


/********************************************************************************** 
 ** Description: The get_cost function of the Animal class takes no parameters and
		 returns the double member variable cost representing the price of
		 the Animal object
 ** *******************************************************************************/ 

double Animal::get_cost() const
{
	return this -> cost;
}


/********************************************************************************** 
 ** Description: The get_babies function of the Animal class takes no parameters and
		 returns the int member variable number_of_babies representing the
		 number of babies the Animal object can have
 ** *******************************************************************************/ 

int Animal::get_babies() const
{
	return this -> number_of_babies;
}

/********************************************************************************** 
 ** Description: The get_food function of the Animal class takes no parameters and
		 returns the double member variable base_food_cost representing the
		 base food cost of the Animal object per day
 ** *******************************************************************************/ 

double Animal::get_food() const
{
	return this -> base_food_cost;
}


/********************************************************************************** 
 ** Description: The get_payoff function of the Animal class takes no parameters and
		 returns the double member variable payoff representing the payoff of 
		 the Animal object per day
 ** *******************************************************************************/ 

double Animal::get_payoff() const
{
	return this -> payoff;
}


/********************************************************************************** 
 ** Description: The print_info function of the Animal class takes no parameters and
		 has no return type. It displays information on the Animal object
		 which called the function, namely the type, age, cost, payoff,
		 number of babies and base food cost of the Animal object
 ** *******************************************************************************/ 

void Animal::print_info() const
{
	std::cout << "Type: " << this -> get_type() << std::endl;
	std::cout << "Age: " << this -> get_age() << std::endl;
	std::cout << "Cost: " << this -> get_cost() << std::endl;
	std::cout << "Payoff: " << this -> get_payoff() << std::endl;
	std::cout << "Number of babies: " << this -> get_babies() << std::endl;
	std::cout << "Base Food Cost: " << this -> get_food() << std::endl;

}





