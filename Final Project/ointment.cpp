/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Ointment
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This program contains the member function definitions for the
		  child class Ointment
 ** *******************************************************************************/ 
#include "ointment.hpp"
#include "player.hpp"
#include "item.hpp"
#include <string>
#include <iostream>

/********************************************************************************** 
 ** Description: The default construtor for the Ointment class sets its string data
		 member item_type which it inherited from the Item class to the 
		 string "RuPaul's Magic Foot Ointment" upon instantiation of a newly
		 constructed Ointment object
 ** *******************************************************************************/ 

Ointment::Ointment()
{
	this -> item_type = "RuPaul's Magic Foot Ointment";
}


/********************************************************************************** 
 ** Description: The get_symbol function of the Ointment class is an overridden 
		 function of the Item class. It takes no parameters and returns
		 a char indicating the type of the Item object on the game map i.e. 
		 RuPaul's Magic Foot Ointment, represented by m, found in the studio.
		 There are 5 for the player to collect
 ** *******************************************************************************/ 

char Ointment::get_symbol()
{
	return 'm';	
}


/********************************************************************************** 
 ** Description: The item_action function of the Ointment class is an overridden
		 function of the Item class. It has no return type and takes a 
		 pointer to a Player object as a parameter. When the player picks up
		 an Ointment object, it restores the player's health back to their
		 starting health by setting the int data member health of the
		 Player class back to 100
 ** *******************************************************************************/ 

void Ointment::item_action(Player *player)
{
	std::cout << " " << std::endl;
	std::cout << "***After rubbing this on your sore feet you restore your health back to 100!***" 
		  << std::endl;
	std::cout << " " << std::endl;
	player -> set_health(100);
}
