/**********************************************************************************
 ** Program Name: Source code for the member functions of the child class Blue_Men
 ** Author:       Susan Hibbert
 ** Date:         2 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Blue_Men
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "bluemen.hpp"
#include "character.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

/********************************************************************************** 
 ** Description: The default construtor for the Blue_Men class sets its int data
		 members, armor and strength_points, it inherited from the Character
		 class, to default values upon instantiation of a newly constructed 
		 Blue_Men object
 ** *******************************************************************************/ 

Blue_Men::Blue_Men()
{
	this -> set_strength_points(12);
	this -> set_armor(3);
}


/********************************************************************************** 
 ** Description: The get_type function of the Blue_Men class is an overridden 
		 function of the Character class. It takes no parameters and returns
		 a string indicating the type of the Character object i.e. Blue Men
 ** *******************************************************************************/ 

std::string Blue_Men::get_type()
{
	return "Blue Men";
	
}


/********************************************************************************** 
 ** Description: The attack function of the Blue_Men class is an overridden function
		 of the Character class using 2d10. It takes no parameters and
		 returns the attack roll of 2d10 as an int
 ** *******************************************************************************/ 

int Blue_Men::attack()
{
	//Attack is 2d10
	int attack_roll_1;
	int attack_roll_2;
	int attack_roll_total;

	//roll the 2 dice	
	attack_roll_1 = rand() % 10 + 1;
	attack_roll_2 = rand() % 10 + 1;
	attack_roll_total = attack_roll_1 + attack_roll_2;

	std::cout << "Attacker's Attack Dice Roll: " << attack_roll_total << std::endl;

	return attack_roll_total;
}


/********************************************************************************** 
 ** Description: The defense function of the Blue_Men class is an overridden function
		 of the Character class using 3d6 and Mob. It takes an int parameter
		 representing the attack roll of the attacking Character object and
		 calculates the damage inflicted to its strength points and returns
		 this damage as an int. After the damage has been calculated, its
		 strength points are updated.
		 Blue_Men has a special ability called Mob. For every 4 points 
		 deducted from its strength points as a result of damage, it loses
		 one defense die. 
 ** *******************************************************************************/ 

int Blue_Men::defense(int attack)
{
	//display strength points and armor before attack
	int defense_strength = this -> get_strength_points();
	int armor = this -> get_armor();	
	std::cout << "Defender Strength Points: " << defense_strength << std::endl;	
	std::cout << "Defender Armor: " << armor << std::endl;	
	
	int defense_roll_total;	

	if (defense_strength > 8)
	{	
		//Defense is 3d6
		int defense_roll_1;
		int defense_roll_2;
		int defense_roll_3;

		//roll the 3 dice
		defense_roll_1 = rand() % 6 + 1;
		defense_roll_2 = rand() % 6 + 1;
		defense_roll_3 = rand() % 6 + 1;
		defense_roll_total = defense_roll_1 + defense_roll_2 + defense_roll_3;
	}

	//For every 4 points of damage, they lose one defense die. After
	//losing 4 points of damage, it is down to 2d6 from 3d6
	if (defense_strength > 4 && defense_strength <= 8)
	{		
		//Defense is 2d6
		int defense_roll_1;
		int defense_roll_2;

		//roll the 2 dice
		defense_roll_1 = rand() % 6 + 1;
		defense_roll_2 = rand() % 6 + 1;
		defense_roll_total = defense_roll_1 + defense_roll_2;
	}

	//After losing 8 strength points it loses another defense dice -
	//it is now down to 1d6 from 2d6
	if (defense_strength <= 4 && defense_strength > 0)
	{		
		//roll the 1 dice
		defense_roll_total = rand() % 6 + 1;
	}

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

	int defense_strength_new = this -> get_strength_points();

	//For every 4 points of damage, they lose one defense die. After
	//losing 4 points of damage, it is down to 2d6 from 3d6
	if (defense_strength_new > 4 && defense_strength_new <= 8)
	{	
		std::cout << " " << std::endl;
		std::cout << "*** Mob ability implemented! Blue men have lost one defense die! ***"
			  << std::endl;
		std::cout << "*** Blue Men is down to 2d6 for defense ***" << std::endl;
		std::cout << " " << std::endl;
	}

	//After losing 8 strength points it loses another defense dice -
	//it is now down to 1d6 from 2d6
	if (defense_strength_new <= 4 && defense_strength_new > 0)
	{	
		std::cout << " " << std::endl;
		std::cout << "*** Mob ability implemented! Blue men have lost two defense die! ***"
			  << std::endl;
		std::cout << "*** Blue Men is down to 1d6 for defense ***" << std::endl;
		std::cout << " " << std::endl;
	
	}

	return damage;

}
