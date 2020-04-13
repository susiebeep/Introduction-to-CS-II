/******************************************************************************* 
 ** Program Name: Class declaration for the derived class Dress
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the derived class Dress
 ** *******************************************************************************/ 
#ifndef DRESS_HPP
#define DRESS_HPP
#include <string>
#include "item.hpp"
#include "player.hpp"

class Dress: public Item
{
	public:
		Dress();
		char get_symbol(); //overridden function of Item class
		void item_action(Player *player1);  //overridden function of Item class
};

#endif
