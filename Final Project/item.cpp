/********************************************************************************** 
 ** Program Name: Source code for the member functions of the polymorphic, abstract
		  base class Item
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This program contains the member function definitions for the
		  abstract base class Item
 ** *******************************************************************************/ 
#include "item.hpp"
#include <string>
#include <iostream>


/********************************************************************************** 
 ** Description: The destructor of the Item class. The body of the function is
		 empty
 ** *******************************************************************************/ 

Item::~Item()
{

}


/********************************************************************************** 
 ** Description: The get_item_type function of the Item class takes no parameters
		 and returns the string data member item_type indicating the type
		 of the Item object
 ** *******************************************************************************/ 

std::string Item::get_item_type()
{
	return this -> item_type;
}

/********************************************************************************** 
 ** Description: The set_item_type function of the Item class has no return type
		 and takes a string parameter which it uses to set its string data
		 member item_type
 ** *******************************************************************************/ 

void Item::set_item_type(std::string input_type)
{
	 this -> item_type = input_type;
}


/********************************************************************************** 
 ** Description: The find_item function of the Item class has no parameters or 
		 return type. It displays on screen the type of Item object found
		 by the player when they are navigating through the game map
 ** *******************************************************************************/ 

void Item::find_item()
{
	std::cout << "***You found " << get_item_type() << "***" << std::endl;
	std::cout << " " << std::endl;
}
