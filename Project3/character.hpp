/******************************************************************************* 
 ** Program Name: Class declaration for polymorphic, abstract base class Character
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
 ** Description:  This program contains the function prototypes for the abstract
		  base class Character
 ** *******************************************************************************/ 
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

class Character
{
	protected:
		int armor;
		int strength_points;
 
	public:
		virtual int attack(); //attack virtual function
		virtual int defense(int attack); //defense virtual function
		virtual void set_armor(int input_armor);
		virtual void set_strength_points(int input_strength);
		virtual std::string get_type() = 0; //pure virtual function		
		int get_armor();
		int get_strength_points();

};

#endif
