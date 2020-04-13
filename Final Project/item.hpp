/******************************************************************************* 
 ** Program Name: Class declaration for polymorphic, abstract base class Item
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the abstract base class Item
 ** *******************************************************************************/ 
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
#include "player.hpp"

class Item
{
	protected:
		std::string item_type;		

	public:
		virtual ~Item();
		virtual char get_symbol() = 0; //pure virtual function
		virtual void item_action(Player *player) = 0; //pure virtual function
		virtual std::string get_item_type();
		void set_item_type(std::string input_type);
		void find_item();
};

#endif
