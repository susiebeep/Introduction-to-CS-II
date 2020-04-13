/******************************************************************************* 
 ** Program Name: Class declaration for class Purse
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the Purse class which implements the container for the player
		  to carry items
 ** *******************************************************************************/ 
#ifndef PURSE_HPP
#define PURSE_HPP
#include "item.hpp"
#include "space.hpp"
#include "player.hpp"

class Space; //forward declaration

class Purse
{
	private:
		Item* purse[4]; //array of 4 pointers to Item objects
		bool full;		

	public:
		Purse();
		~Purse();
		void display_purse(); //displays purse contents
		void add_item(Item *item1);
		void use_item(int item_no, Player* player);
		Item* get_item(int item_no);
		void get_gift();
		void enter_dressingroom(Space* room);
		void check_mirror(Space* room1);
};
#endif
