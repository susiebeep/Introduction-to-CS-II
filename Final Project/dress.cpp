/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Dress
 ** Author:       Susan Hibbert
 ** Date:         3 June 2019
 ** Description:  This program contains the member function definitions for the
		  child class Dress
 ** *******************************************************************************/ 
#include "dress.hpp"
#include "item.hpp"
#include "player.hpp"
#include <iostream>
#include <string>

/********************************************************************************** 
 ** Description: The default construtor for the Dress class sets its string data
		 member item_type which it inherited from the Item class to the
		 string "Dress" upon instantiation of a newly constructed Dress
		 object
 ** *******************************************************************************/ 

Dress::Dress()
{
	this -> item_type = "Dress";
}

/********************************************************************************** 
 ** Description: The get_symbol function of the Dress class is an overridden 
		 function of the Item class. It takes no parameters and returns
		 a char indicating the type of the Item object on the game map
		 object i.e. Dress, represented by d, found in the studio
 ** *******************************************************************************/ 

char Dress::get_symbol()
{
	return 'd';	
}


/********************************************************************************** 
 ** Description: The item_action function of the Dress class is an overridden function
		 of the Item class. It has no return type and takes a Player pointer.
		 When the player uses the Dress object found in the game map a message
		 is displayed on screen indicating that they are now wearing the Dress
		 and the Old Sweater they were wearing has been put into their purse
 ** *******************************************************************************/ 

void Dress::item_action(Player *player1)
{
	if (item_type == "Dress")
	{
		std::cout << " " << std::endl;
		std::cout << "***You put on the Dress and luckily it's just your size!***" << std::endl;
		std::cout << "***You put the Old Sweater you were wearing into your purse***" << std::endl;
		std::cout << " " << std::endl;
	}
}
