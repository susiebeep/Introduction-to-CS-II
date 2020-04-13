/******************************************************************************* 
 ** Program Name: Class declaration for the derived class Wig
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the derived class Wig
 ** *******************************************************************************/ 
#ifndef WIG_HPP
#define WIG_HPP
#include <string>
#include "item.hpp"
#include "player.hpp"

class Wig: public Item
{
	public:
		Wig();
		char get_symbol(); //overridden function of Item class
		void item_action(Player *player1);  //overridden function of Item class
};

#endif
