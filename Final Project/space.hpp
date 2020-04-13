/******************************************************************************* 
 ** Program Name: Class declaration for polymorphic, abstract base class Space
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the function prototypes for the abstract
		  base class Space
 ** Citations: 	  2.7 Forward declarations and definitions, learncpp.com
 ** *******************************************************************************/ 
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include "item.hpp"
#include "player.hpp"
#include "purse.hpp"

class Purse; //forward declaration

class Space
{
	protected:
		Space* top;
		Space* bottom;
		Space* left;
		Space* right;
 		Item* item1;
		
	public:
		virtual ~Space();
		virtual std::string get_type() = 0; //pure virtual function		
		virtual char get_char() = 0; //pure virtual function 
		virtual bool is_wall();
		virtual bool is_ready();
		virtual void set_ready(bool input);
		virtual void set_item1(Item* input_item1);
		Space* get_top();
		Space* get_bottom();
		Space* get_left();
		Space* get_right();
		void set_top(Space* input1);
		void set_bottom(Space* input2);
		void set_left(Space* input3);
		void set_right(Space* input4);
		void check_for_items(Purse *purse);
		Item* get_item();
		
};

#endif
