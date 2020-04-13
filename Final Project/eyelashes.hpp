/******************************************************************************* 
 ** Program Name: Class declaration for the derived class Eyelashes
 ** Author:       Susan Hibbert
 ** Date:         4 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the derived class Eyelashes
 ** *******************************************************************************/ 
#ifndef EYELASHES_HPP
#define EYELASHES_HPP
#include <string>
#include "item.hpp"
#include "player.hpp"

class Eyelashes: public Item
{
	public:
		Eyelashes();
		char get_symbol(); //overridden function of Item class
		void item_action(Player *player1);  //overridden function of Item class
};

#endif
