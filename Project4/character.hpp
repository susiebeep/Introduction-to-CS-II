/******************************************************************************* 
 ** Program Name: Class declaration for polymorphic, abstract base class Character
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
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
		std::string name;
 
	public:
		virtual std::string get_type() = 0; //pure virtual function		
		virtual int starting_strength() = 0; //pure virtual function
		virtual void set_armor(int input_armor);
		virtual void set_strength_points(int input_strength);
		void set_name(std::string input_name);
		int get_armor();
		int get_strength_points();
		std::string get_name();
		virtual int attack(); //attack virtual function
		virtual int defense(int attack); //defense virtual function
		void recovery();

};

#endif
