/********************************************************************************** 
 ** Program Name: Source code for the member functions of the polymorphic, abstract
		  base class Character
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This program contains the member function definitions for the
		  abstract base class Character
 ** *******************************************************************************/ 
#include "character.hpp"
#include <cstdlib>
#include <iostream>


/********************************************************************************** 
 ** Description: The set_armor function of the Character class has no return type
		 and takes one int parameter which it uses to set the int data member
		 armor which represents the armor strength of the Character object
 ** *******************************************************************************/ 

void Character::set_armor(int input_armor)
{
	this -> armor = input_armor;
}

/********************************************************************************** 
 ** Description: The set_strength_points function of the Character class has no
		 return type and takes one int parameter which it uses to set the
		 int data member strength_points which represents the strength points
		 of the Character object
 ** *******************************************************************************/ 

void Character::set_strength_points(int input_strength)
{
	this -> strength_points = input_strength;
}


/********************************************************************************** 
 ** Description: The set_name function of the Character class has no return type and
		 takes one string parameter which it uses to set the string data
		 member name which represents the name of the Character object
 ** *******************************************************************************/ 

void Character::set_name(std::string input_name)
{
	this -> name = input_name;
}


/********************************************************************************** 
 ** Description: The get_armor function of the Character class takes no parameters
		 and returns the int data member armor which represents the armor
		 strength of the Character object
 ** *******************************************************************************/ 

int Character::get_armor()
{
	return this -> armor;
}


/********************************************************************************** 
 ** Description: The get_strength_points function of the Character class takes no
		 parameters and returns the int data member strength_points which
		 represents the strength points of the Character object
 ** *******************************************************************************/ 

int Character::get_strength_points()
{
	return this -> strength_points;
}


/********************************************************************************** 
 ** Description: The get_name function of the Character class takes no parameters
		 and returns the string data member name which represents the name
		 of the Character object
 ** *******************************************************************************/ 

std::string Character::get_name()
{
	return this -> name;
}


/********************************************************************************** 
 ** Description: The attack function of the Character class is the default attack
		 function of its subclasses unless overridden. It takes no parameters
		 and returns the attack roll of the attacking Character object as
		 an int
 ** *******************************************************************************/ 

int Character::attack()
{
	//default attack action is 2d6
	int attack_roll_1;
	int attack_roll_2;
	int attack_roll_total;

	//roll the 2 dice	
	attack_roll_1 = rand() % 6 + 1;
	attack_roll_2 = rand() % 6 + 1;
	attack_roll_total = attack_roll_1 + attack_roll_2;
	
	//return damage attacked
	return attack_roll_total;
}


/********************************************************************************** 
 ** Description: The defense function of the Character class is the default
		 defense function of its subclasses unless overridden. It takes an
		 int parameter representing the attack roll of the attacking Character
		 object and calculates the damage inflicted to its strength points and
		 returns this damage as an int. After the damage has been calculated,
		 the strength points for the defending Character object are updated
 ** *******************************************************************************/ 

int Character::defense(int attack)
{
	//determine strength points and armor before attack
	int defense_strength = this -> get_strength_points();
	int armor = this -> get_armor();	

	//default defense option is 2d6
	int defense_roll_1;
	int defense_roll_2;
	int defense_roll_total;
	
	//roll the 2 dice
	defense_roll_1 = rand() % 6 + 1;
	defense_roll_2 = rand() % 6 + 1;
	defense_roll_total = defense_roll_1 + defense_roll_2;
		
	//calculate damage inflicted
	int damage = attack - defense_roll_total - armor;
	
	//if damage inflicted is a negative value set the damage to 0
	if (damage < 0)
	{
		damage = 0;	
	}
	
	//set new strength points for defender following attack
	this -> set_strength_points((defense_strength - damage));

	//if the damage inflicted results in negative strength points set the strength 
	//points to 0
	if ((this -> get_strength_points()) < 0)
	{
		this -> set_strength_points(0);
	}

	return damage;
}



/********************************************************************************** 
 ** Description: The recovery function of the Character class is called by the
		 winning Character object after a fight. It has no return type and
		 no parameters. It calculates the amount of damage taken by the 
		 winning Character object by comparing its current strength to its 
		 starting strength, and adds back a percentage of the damage to the
		 Character object's current strength points, based on the random
		 number generated. For instance, if the number 5 is generated, the
		 Character object will gain back 50% of the damage they lost during
		 the fight
 ** *******************************************************************************/ 

void Character::recovery()
{
	//random number is generated between 1 and 9 representing the percentage of
	//damage recovery (10 - 90%)
	int recover = rand() % 9 + 1;
	int current_strength = this -> get_strength_points();
	int initial_strength = this -> starting_strength();
	double new_strength;	

	//if the Character's current strength points is the same as its starting
	//strength points, keep the current strength points (NB current strength will
	//never be higher than starting strength)
	if (current_strength == initial_strength)
	{
		new_strength = current_strength;
	}
	
	else
	{	
		//calculate the difference between the starting strength and
		//current strength and add back a percentage of the damage to
		//the current strength points, based on the random number 
		//generated (will be between 10-90%) 
		//(NB the Character will not be restored back to their starting
		//strength)
		int damage = initial_strength - current_strength;		

		//10% recovery
		if (recover == 1)
		{
			new_strength = (damage * 0.1) + current_strength;
		}

		//20% recovery
		if (recover == 2)
		{
			new_strength = (damage * 0.2) + current_strength;
		}

		//30% recovery
		if (recover == 3)
		{
			new_strength = (damage * 0.3) + current_strength;
		}
		
		//40% recovery
		if (recover == 4)
		{
			new_strength = (damage * 0.4) + current_strength;
		}
	
		//50% recovery
		if (recover == 5)
		{
			new_strength = (damage * 0.5) + current_strength;
		}
	
		//60% recovery
		if (recover == 6)
		{
			new_strength = (damage * 0.6) + current_strength;
		}
	
		//70% recovery
		if (recover == 7)
		{
			new_strength = (damage * 0.7) + current_strength;
		}
	
		//80% recovery
		if (recover == 8)
		{
			new_strength = (damage * 0.8) + current_strength;
		}

		//90% recovery
		if (recover == 9)
		{
			new_strength = (damage * 0.9) + current_strength;
		}	
	}

	//cast the double variable new_strength to an int as the strength_points data
	//member of the Character class is an int, and the set_strength_points
	//function takes an int as a parameter
	int int_strength = static_cast<int>(new_strength);
	
	//set the new strength poinrs of the winning Character
	this -> set_strength_points(int_strength);
	
	//display the new strength points
	std::cout << this -> get_name() << "'s strength points after recovery: " 
		  << this -> get_strength_points() << std::endl;	
}
