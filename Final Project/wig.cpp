/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Wig
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This program contains the member function definitions for the
		  child class Wig
 ** *******************************************************************************/ 
#include "wig.hpp"
#include "item.hpp"
#include "player.hpp"
#include <string>
#include <iostream>


/********************************************************************************** 
 ** Description: The default construtor for the Wig class sets its string data
		 member item_type which it inherited from the Item class to the
		 string "Wig" upon instantiation of a newly constructed Wig object
 ** *******************************************************************************/ 

Wig::Wig()
{
	this -> item_type = "Wig";
}


/********************************************************************************** 
 ** Description: The get_symbol function of the Wig class is an overridden 
		 function of the Item class. It takes no parameters and returns
		 a char indicating the type of the Item object on the game map i.e.
		 a Wig, represented by w, given to the player by RuPaul in his
		 dressing room
 ** *******************************************************************************/ 

char Wig::get_symbol()
{
	return 'w';	
}


/********************************************************************************** 
 ** description: The item_action function of the wig class is an overridden function
		 of the item class. It has no return type and takes a Player pointer
		 as a parameter. When the player uses the Wig object, given to the
		 player by RuPaul in his dressing room, a message is displayed on
		 screen indicating that they are now wearing the wig and advising
		 the player to visit the Mirror object. They are informed that the
		 Hat they were wearing has been put into their purse
 ** *******************************************************************************/ 

void Wig::item_action(Player *player1)
{
	if (item_type == "Wig")
	{
		std::cout << " " << std::endl;
		std::cout << "***Wig is on! Go and check yourself in the Mirror before heading to the stage!***"
			  << std::endl;
		std::cout << "***You put the Hat you were wearing into your purse***" << std::endl;
		std::cout << " " << std::endl;
	}
}
