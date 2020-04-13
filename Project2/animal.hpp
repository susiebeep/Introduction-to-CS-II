/******************************************************************************* 
 ** Program Name: Class declaration for base class Animal
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the function prototypes for the parent class
		  Animal 
 ** *******************************************************************************/ 
#include <string>
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		double cost;
		int number_of_babies;
		double base_food_cost;
		double payoff;

	public:
		Animal();
		std::string get_type() const;
		int get_age() const;
		void set_age(int new_age);
		double get_cost() const;
		int get_babies() const;
		double get_food() const;
		double get_payoff() const;
		void print_info() const;
};

#endif
