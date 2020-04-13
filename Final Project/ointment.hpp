/******************************************************************************* 
 ** Program Name: Class declaration for the derived class Ointment
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the derived class Ointment
 ** *******************************************************************************/ 
#ifndef OINTMENT_HPP
#define OINTMENT_HPP
#include <string>
#include "item.hpp"

class Ointment: public Item
{
	public:
		Ointment();
		char get_symbol(); //overridden function of Item class
		void item_action(Player* player); //overridden function of Item class
};

#endif
