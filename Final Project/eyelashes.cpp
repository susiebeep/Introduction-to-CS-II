/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Eyelashes
 ** Author:       Susan Hibbert
 ** Date:         4 June 2019
 ** Description:  This program contains the member function definitions for the
		  child class Eyelashes
 ** *******************************************************************************/ 
#include "eyelashes.hpp"
#include "item.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

/********************************************************************************** 
 ** Description: The default construtor for the Eyelashes class sets its string data
		 member item_type which it inherited from the Item class to the
		 string "False Eyelashes" upon instantiation of a newly constructed
		 Eyelashes object
 ** *******************************************************************************/ 

Eyelashes::Eyelashes()
{
	this -> item_type = "False Eyelashes";
}


/********************************************************************************** 
 ** Description: The get_symbol function of the Eyelashes class is an overridden 
		 function of the Item class. It takes no parameters and returns
		 a char indicating the type of the Item object on the game map
		 object i.e. Eyelashes, represented by e, found in the studio
 ** *******************************************************************************/ 

char Eyelashes::get_symbol()
{
	return 'e';	
}


/********************************************************************************** 
 ** Description: The item_action function of the Eyelashes class is an overridden
		 function of the Item class. It has no return type and takes a 
		 Player pointer. When the player uses the Eyelashes object found in
		 the game map a message is displayed on screen indicating that they
		 are now wearing the Eyelashes and their Contact Lens have been put
		 into their purse
 ** *******************************************************************************/ 

void Eyelashes::item_action(Player *player1)
{
	if (item_type == "False Eyelashes")
	{
		std::cout << " " << std::endl;
		std::cout << "***Eyelashes are on! They really make your eyes pop!***" << std::endl;
		std::cout << "***You take out your Contact Lens and put them in your purse***" << std::endl;
		std::cout << " " << std::endl;
	}
}
