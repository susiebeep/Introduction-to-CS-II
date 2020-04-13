/********************************************************************************** 
 ** Program Name: Source code for the member functions of the polymorphic, abstract
		  base class Space
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the member function definitions for the
		  abstract base class Space
 ** *******************************************************************************/ 
#include "space.hpp"
#include "item.hpp"
#include "purse.hpp"

/********************************************************************************** 
 ** Description: The destructor of the Space class is empty
 ** *******************************************************************************/ 

Space::~Space()
{
}


/********************************************************************************** 
 ** Description: The is_wall function of the Space class has no parameters and 
		 returns the bool false indicating that the Space object is not a
		 Wall object. This function is overridden in the derived classes of
		 Space
 ** *******************************************************************************/ 

bool Space::is_wall()
{
	return false;
}


/********************************************************************************** 
 ** Description: The is_ready function of the Space class has no parameters and 
		 returns the bool true indicating that the Space object can be
		 interacted with. This function is overridden in the derived classes
		 of Space
 ** *******************************************************************************/ 

bool Space::is_ready()
{
	return true;
}


/********************************************************************************** 
 ** Description: The set_ready function of the Space class has no return type and
		 takes a bool parameter. The body of the function is empty. This
		 function is overridden in the derived classes of Space
 ** *******************************************************************************/ 

void Space::set_ready(bool input)
{
	
}


/********************************************************************************** 
 ** Description: The set_item1 function of the Space class has no return type and
		 takes an Item pointer as a parameter which it uses to set its Item
		 pointer data member item1. This function is overridden in the
		 derived classes of Space
 ** *******************************************************************************/ 

void Space::set_item1(Item* input_item1)
{
	this -> item1 = input_item1;
}

/********************************************************************************** 
 ** Description: The get_top function of the Space class has no parameters and 
		 returns the Space pointer data member top
 ** *******************************************************************************/ 

Space* Space::get_top()
{
	if (top != NULL)
	{
		return this -> top;
	}
	else
	{
		return NULL;
	}
}

	
/********************************************************************************** 
 ** Description: The get_bottom function of the Space class has no parameters and 
		 returns the Space pointer data member bottom
 ** *******************************************************************************/ 

Space* Space::get_bottom()
{	
	if (bottom != NULL)
	{
		return this -> bottom;
	}
	else
	{
		return NULL;
	}
}	


/********************************************************************************** 
 ** Description: The get_left function of the Space class has no parameters and 
		 returns the Space pointer data member left
 ** *******************************************************************************/ 

Space* Space::get_left()
{
	if (left != NULL)
	{
		return this -> left;
	}
	else
	{
		return NULL;
	}
}

	
/********************************************************************************** 
 ** Description: The get_right function of the Space class has no parameters and 
		 returns the Space pointer data member right
 ** *******************************************************************************/ 

Space* Space::get_right()
{
	if (right != NULL)
	{
		return this -> right;
	}
	else
	{
		return NULL;
	}
}

	
/********************************************************************************** 
 ** Description: The set_top function of the Space class has no return type and 	
		 takes a Space pointer as a parameter which it uses to set its
		 Space pointer data member top
 ** *******************************************************************************/ 

void Space::set_top(Space *input1)
{
	this -> top = input1;
}

	
/********************************************************************************** 
 ** Description: The set_bottom function of the Space class has no return type and 	
		 takes a Space pointer as a parameter which it uses to set its
		 Space pointer data member bottom
 ** *******************************************************************************/ 

void Space::set_bottom(Space *input2)
{
	this -> bottom = input2;
}

	
/********************************************************************************** 
 ** Description: The set_left function of the Space class has no return type and 	
		 takes a Space pointer as a parameter which it uses to set its
		 Space pointer data member left
 ** *******************************************************************************/ 

void Space::set_left(Space *input3)
{
	this -> left = input3;
}

	
/********************************************************************************** 
 ** Description: The set_right function of the Space class has no return type and 	
		 takes a Space pointer as a parameter which it uses to set its
		 Space pointer data member right
 ** *******************************************************************************/ 

void Space::set_right(Space *input4)
{
	this -> right = input4;
}

	
/********************************************************************************** 
 ** Description: The check_for_items function of the Space class has no return type
		 and takes a Purse pointer as a parameter. It is called when the
		 player moves onto a new Space object on the game map. If that
		 Space object has an item it gets added to the player's Purse object
 ** *******************************************************************************/ 

void Space::check_for_items(Purse *purse)
{
	if (item1 != NULL)	
	{
		//call function of Item class which displays item type on screen to user
		item1 -> find_item();

		//add item to Purse
		purse -> add_item(item1);

		//set item1 to null
		item1 = NULL;
	}
}

	
/********************************************************************************** 
 ** Description: The get_item function of the Space class takes no parameters and 	
		 returns its Item pointer data member item1
 ** *******************************************************************************/ 

Item* Space::get_item()
{
	return this -> item1;
}
