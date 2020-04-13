/********************************************************************************** 
 ** Program Name: Source code for the member functions of the class Purse
 ** Author:       Susan Hibbert
 ** Date:         4 June 2019
 ** Description:  This program contains the member function definitions for the
		  class Purse
 ** *******************************************************************************/ 
#include "purse.hpp"
#include "player.hpp"
#include "item.hpp"
#include "wig.hpp"
#include "space.hpp"
#include <iostream>
#include <string>

/********************************************************************************** 
 ** Description: The default construtor for the Purse class sets its 4 Item pointer
		 data members to null and its bool data member full to false upon
		 instantiation of a newly constructed Purse object
 ** *******************************************************************************/ 

Purse::Purse()
{
	this -> purse[0] = NULL;
	this -> purse[1] = NULL;
	this -> purse[2] = NULL;
	this -> purse[3] = NULL;
	this -> full = false;
}


/********************************************************************************** 
 ** Description: The default construtor for the Purse class is empty
 ** *******************************************************************************/ 

Purse::~Purse()
{

}


/********************************************************************************** 
 ** Description: The display_purse function of the Purse class takes no parameters 
		 and has no return type. It displays the contents of the Purse object
		 on screen
 ** *******************************************************************************/ 

void Purse::display_purse()
{
	int count = 1;

	for (int i = 0; i < 4; i++)
	{
		std::cout << count << ". ";
		if (purse[i] == NULL)
		{	
			std::cout << "***Empty***" << std::endl;
		}
		else
		{
			std::cout << purse[i] -> get_item_type() << std::endl;
		}
		count++;
	}
}


/********************************************************************************** 
 ** Description: The add_item function of the Purse class has no return type and
		 takes an Item pointer as a parameter and adds the Item to the purse
		 if an empty slot in the purse is found. If not, a message is
		 displayed on screen to the user telling them that the purse is full
		 and that they need to use one or more items in their purse to make
		 room. The purse can hold 4 Items at a time
 ** *******************************************************************************/ 

void Purse::add_item(Item *item1)
{
	//find empty slot in purse

	int i = 0;	
	while ((purse[i] != NULL) && i < 4)
	{
		++i;

		//on last iteration if no empty slots are found purse is full	
		if (i == 4)
		{
			full = true;
		}
	}
	//if purse is not full, place Item in the empty slot 		
	if (!full)
	{
		purse[i] = item1;
	}
	//if no empty slots were found in the purse
	else
	{
		std::cout << "***Your purse is full!***" << std::endl;
		std::cout << "***Please use one or more items to make room in your purse***"
			  << std::endl;
		std::cout << " " << std::endl;
	}
}


/********************************************************************************** 
 ** Description: The use_item function of the Purse class has no return type and 
		 takes an int parameter, representing the number of the Item listed
		 in the purse contents, and a Player pointer. A function of the Item
		 class is called in order to use the particular Item object, and a
		 message is displayed on screen for the user depending on the type
		 of Item used. Once the Item has been used, the name of the Item is
		 changed according to the type of Item used. For instance, if the
		 Dress object is used its string data member item_type is changed 
		 from "Dress" to "Old Sweater" to indicate that the player has used
		 and is now wearing the Dress. Once an item has been used it cannot
		 be used again. If the item used is an Ointment object, it is deleted
		 from the purse instead of setting its name to something else
 ** *******************************************************************************/ 

void Purse::use_item(int item_no, Player *player)
{
	//call on Item function to use particular Item object
	purse[item_no - 1] -> item_action(player);

	//depending on item used, change the Item object's data member item_type
	//according to the type of the Item used or delete Item object

	if (purse[item_no - 1] -> get_item_type() == "Dress")
	{
		purse[item_no - 1] -> set_item_type("Old Sweater");
	}
	else if (purse[item_no - 1] -> get_item_type() == "False Eyelashes")
	{
		purse[item_no - 1] -> set_item_type("Contact Lens");
	}
	else if (purse[item_no - 1] -> get_item_type() == "Wig")
	{
		purse[item_no - 1] -> set_item_type("Hat");
	}
	//cannot use Dress object again
	else if (purse[item_no - 1] -> get_item_type() == "Old Sweater")
	{
		std::cout << "***You can't use this item!***" << std::endl;
		std::cout << " " << std::endl;
	}
	//cannot use Eyelashes object again
	else if (purse[item_no - 1] -> get_item_type() == "Contact Lens")
	{
		std::cout << "***You can't use this item!***" << std::endl;
		std::cout << " " << std::endl;
	}
	//cannot use Wig object again
	else if (purse[item_no - 1] -> get_item_type() == "Hat")
	{
		std::cout << "***You can't use this item!***" << std::endl;
		std::cout << " " << std::endl;
	}
	//if the item is an Ointment object, delete it from the purse
	else
	{
		delete purse[item_no - 1];
		purse[item_no - 1] = NULL;
	}

	//change full to false if used 4th item in purse
	if (purse[item_no - 1] == purse[3])
	{
		full = false;
	}
}


/********************************************************************************** 
 ** Description: The get_item function of the Purse class takes an int parameter,
		 representing the number of the item listed in the purse contents,
		 and returns an Item pointer, representing the position of the item
		 in its data member array of Item pointers
 ** *******************************************************************************/ 

Item* Purse::get_item(int item_no)
{
	return this -> purse[item_no - 1];
}


/********************************************************************************** 
 ** Description: The get_gift function of the Purse class has no parameters or return
		 type. A dialogue between the Player and RuPaul displays on screen
		 when the player enter RuPaul's Dressing Room. The player is given
		 a Wig object which is added to their purse
 ** *******************************************************************************/ 

void Purse::get_gift()
{
	std::cout << "RuPaul: 'Come in!'" << std::endl;
	std::cout << "You: 'I can't believe it's actually you! I'm...I'm....'" << std::endl;
	std::cout << "RuPaul: 'I know, I know, it's me. Look I'm a busy man, you're here for the wig, right?'"
		  << std::endl;
	std::cout << "You: 'Y-yes, the wig!'" << std::endl;
	std::cout << "RuPaul: 'Ok here. Go put it on, check it in the Mirror then hit that stage, you go on in 10'"
		  << std::endl;
	std::cout << " " << std::endl;
	std::cout << "***RuPaul gave you a wig!***" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "RuPaul: '....you still here?!'"
		  << std::endl;
	std::cout << " " << std::endl;

	//dynamically allocate Wig object
	Item *gift = new Wig;
	add_item(gift);
}


/********************************************************************************** 
 ** Description: The enter_dressingroom function of the Purse class has no return
		 type and takes a Space pointer as a parameter. It checks whether 
		 the player has found and used the Dress object and Eyelashes object,
		 if so the Dressing Room object is 'unlocked' and its bool data 
		 member enter is set to true, allowing the player to interact with
		 the Dressing Room object i.e. dialogue with RuPaul
 ** *******************************************************************************/ 

void Purse::enter_dressingroom(Space* room)
{
	bool dress = false;
	bool eyelashes = false;
	bool ready1 = false;

	//search the purse for "Old Sweater" and "Contact Lens", indicating that the
	//player used the Dress and Eyelashes objects. If player has used Dress and
	//Eyelashes, their respective bool variables get set to true
	for (int i = 0; i < 4; i++)
	{	
		if (purse[i] != NULL)
		{
			if (purse[i] -> get_item_type() == "Old Sweater")
			{
				dress = true;
			}
			else if (purse[i] -> get_item_type() == "Contact Lens")
			{
				eyelashes = true;
			}
		}
	}
	//if both items were used, the Dressing Room is unlocked
	if (dress && eyelashes)
	{
		ready1 = true;
		room -> set_ready(ready1);	
	}

}


/********************************************************************************** 
 ** Description: The check_mirror function of the Purse class has no return type 
		 and takes a Space pointer as a parameter. It checks whether the
		 player has used the Wig object, given to the player by RuPaul, and
		 if so the bool data member ready of the Mirror object is set to true.
		 When the player now interacts with the Mirror object, a different
		 message will be displayed on screen, telling the player that they are
		 ready and that they should make their way to the Stage Door, which
		 is unlocked at the same time by a function of the Game class
 ** *******************************************************************************/ 

void Purse::check_mirror(Space* room1)
{
	bool wig = false;
	bool ready1 = false;

	//search purse for "Hat" indicating that the player used the Wig object. If 
	//player has used Wig, the bool variable wig is set to true
	for (int i = 0; i < 4; i++)
	{
		if (purse[i] != NULL)
		{
			if (purse[i] -> get_item_type() == "Hat")
			{
				wig = true;
			}
		}
	}
	//if wig is found, the Mirror will display a different message the next
	//time the player interacts with it
	if (wig)
	{
		ready1 = true;
		room1 -> set_ready(ready1);	
	}

}
