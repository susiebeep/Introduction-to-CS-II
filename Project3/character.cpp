/********************************************************************************** 
 ** Program Name: Source code for the member functions of the polymorphic, abstract
		  base class Character
 ** Author:       Susan Hibbert
 ** Date:         30 April 2019
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

	std::cout << "Attacker's Attack Dice Roll: " << attack_roll_total << std::endl;
	
	//return damage attacked
	return attack_roll_total;
}


/********************************************************************************** 
 ** Description: The defense function of the Character class is the default
		 defense function of its subclasses unless overridden. It takes an
		 int parameter representing the attack roll of the attacking Character
		 object and calculates the damage inflicted to its strength points and
		 returns this damage as an int. After the damage has been calculated,
		 the strength points for the defending object are updated
 ** *******************************************************************************/ 

int Character::defense(int attack)
{
	//display strength points and armor before attack
	int defense_strength = this -> get_strength_points();
	int armor = this -> get_armor();	
	std::cout << "Defender Strength Points: " << defense_strength << std::endl;	
	std::cout << "Defender Armor: " << armor << std::endl;	

	//default defense option is 2d6
	int defense_roll_1;
	int defense_roll_2;
	int defense_roll_total;
	
	//roll the 2 dice
	defense_roll_1 = rand() % 6 + 1;
	defense_roll_2 = rand() % 6 + 1;
	defense_roll_total = defense_roll_1 + defense_roll_2;
	
	std::cout << "Defender's Defend Dice Roll: " << defense_roll_total << std::endl;
	
	//calculate damage inflicted
	int damage = attack - defense_roll_total - armor;
	
	//if damage inflicted is a negative value set the damage to 0
	if (damage < 0)
	{
		damage = 0;	
	}

	std::cout << "Total Inflicated Damage Calculation: " << damage << std::endl;
	
	//set new strength points for defender following attack
	this -> set_strength_points((defense_strength - damage));

	//if the damage inflicted results in negative strength points set the strength 
	//points to 0
	if ((this -> get_strength_points()) < 0)
	{
		this -> set_strength_points(0);
	}

	std::cout << "Defender's Updated Strength Points After Damage: " << this -> get_strength_points()
		  << std::endl;
	
	return damage;
}




