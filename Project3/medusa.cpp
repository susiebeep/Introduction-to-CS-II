/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class Medusa
 ** Author:       Susan Hibbert
 ** Date:         2 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Medusa
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "medusa.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

/********************************************************************************** 
 ** Description: The default construtor for the Medusa class sets its int data
		 members, armor and strength_points, it inherited from the Character
		 class, to default values upon instantiation of a newly constructed 
		 Medusa object
 ** *******************************************************************************/ 

Medusa::Medusa()
{
	this -> set_strength_points(8);
	this -> set_armor(3);
}


/********************************************************************************** 
 ** Description: The get_type function of the Medusa class is an overridden 
		 function of the Character class. It takes no parameters and returns
		 a string indicating the type of the Character object i.e. Medusa
 ** *******************************************************************************/ 

std::string Medusa::get_type()
{
	return "Medusa";	
}


/********************************************************************************** 
 ** Description: The attack function of the Medusa class is an overridden function
		 of the Character class using 2d6 and Glare. It takes no parameters
		 and returns the attack roll of the attacking Medusa object as an 
		 int. Medusa has a special ability called Glare. If Medusa rolls a
		 12 when attacking, the opponent instantly gets turned to stone and
		 Medusa wins. This is implemented by multiplying the attack roll
		 by 50 in order to generate a high attack roll which will increase
		 the damage to the opponent and defeat them
 ** *******************************************************************************/ 

int Medusa::attack()
{
	//Attack is 2d6
	int attack_roll_1;
	int attack_roll_2;
	int attack_roll_total;
	
	//roll the 2 dice
	attack_roll_1 = rand() % 6 + 1;
	attack_roll_2 = rand() % 6 + 1;
	attack_roll_total = attack_roll_1 + attack_roll_2;

	std::cout << "Attacker's Attack Dice Roll: " << attack_roll_total << std::endl;
	
	//If Medusa rolls a 12 when attacking the target instantly gets turned to
	//stone and Medusa wins
	if (attack_roll_total == 12)
	{
		std::cout << " " << std::endl;
	 	std::cout << "!!! Medusa used Glare and turned her opponent to stone! !!!" 
			  << std::endl;
		std::cout << " " << std::endl;
		
		//inflict an attack to defeat the opponent
		attack_roll_total = attack_roll_total * 50;
	}	
	else
	{
		//if Medusa does not roll a 12, return damage attacked
		attack_roll_total = attack_roll_total;
	}
	
	return attack_roll_total;
}


/********************************************************************************** 
 ** Description: The defense function of the Medusa class is an overridden function
		 of the Character class using 1d6. It takes an int parameter
		 representing the attack roll of the attacking Character object and
		 calculates the damage inflicted to its strength points and returns
		 the damage as int. After the damage has been calculated the strength
		 points for the defending Medusa are updated
 ** *******************************************************************************/ 

int Medusa::defense(int attack)
{
	//display strength points and armor before attack
	int defense_strength = this -> get_strength_points();
	int armor = this -> get_armor();	
	std::cout << "Defender Strength Points: " << defense_strength << std::endl;	
	std::cout << "Defender Armor: " << armor << std::endl;	

	//Defense is 1d6
	int defense_roll;
	
	//roll the dice
	defense_roll = rand() % 6 + 1;
	
	std::cout << "Defender's Defend Dice Roll: " << defense_roll << std::endl;
	
	//calculate damage inflicted
	int damage = attack - defense_roll - armor;
	
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

