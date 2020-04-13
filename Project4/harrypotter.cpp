/********************************************************************************** 
 ** Program Name: Source code for the member functions of the child class 
		  Harry_Potter
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This program contains the member function definitions for the
		  child class Harry_Potter. The Harry_Potter subclass uses the
		  default attack function of the Character base class
 ** Citations:	  Chapter 15 Polymorphism and Virtual Functions, Starting Out With
		  C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "harrypotter.hpp"
#include "character.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/********************************************************************************** 
 ** Description: The default construtor for the Harry_Potter class sets its int data
		 members, armor and strength_points, it inherited from the Character
		 class, to default values and sets its int data member life_count to
		 0 upon instantiation of a newly constructed Harry_Potter object
 ** *******************************************************************************/ 

Harry_Potter::Harry_Potter()
{
	this -> set_strength_points(10);
	this -> set_armor(0);
	this -> set_life_count(0);
}


/********************************************************************************** 
 ** Description: The get_type function of the Harry_Potter class is an overridden 
		 function of the Character class. It takes no parameters and returns
		 a string indicating the type of the Character object i.e. Harry 
		 Potter
 ** *******************************************************************************/ 

std::string Harry_Potter::get_type()
{
	return "Harry Potter";	
}


/********************************************************************************** 
 ** Description: The starting_strength function of the Harry_Potter class is an
		 overridden function of the Character class. It takes no parameters
		 and returns an int indicating the initial strength of the Character
		 object i.e. Harry Potter, before combat. It is called by the recovery
		 function of the Character class. If Harry Potter has not yet used 
		 Hogwarts, the starting strength is returned as 10. After using 
		 Hogwarts and his starting strength is set to 20, and the function
		 returns 20. 
 ** *******************************************************************************/ 

int Harry_Potter::starting_strength()
{
	int count = this -> get_life_count();
	
	//if not used Hogwarts, starting strength is 10
	if (count == 0)
	{
		return 10;	
	}
	
	//after using Hogwarts starting strength is 20
	if (count == 1)
	{
		return 20;
	}
}


/********************************************************************************** 
 ** Description: The get_life_count function of the Harry_Potter class takes no
		 parameters and returns the int data member life_count representing
		 the number of free lives used by Harry_Potter during the game. It
		 is initialized to 0 upon instantiation of a Harry_Potter object, 
		 and gets set to 1 when Harry_Potter uses his Hogwarts special 
		 ability and comes back to life. He can only use one free life.
 ** *******************************************************************************/ 

int Harry_Potter::get_life_count()
{
	return this -> life_count;
}


/********************************************************************************** 
 ** Description: The set_life_count function of the Harry_Potter class has no return
		 type and takes one int parameter which it uses to set the int data
		 member life_count representing the number of free lives used by
		 Harry_Potter during the game. Upon instantiation of a Harry_Potter
		 object it is set to 0 but gets set to 1 when Harry_Potter uses his
		 Hogwarts special ability during the game and comes back to life.
		 He can only use one free life.
 ** *******************************************************************************/ 

void Harry_Potter::set_life_count(int input_life)
{
	this -> life_count = input_life;
}

/********************************************************************************** 
 ** Description: The defense function of the Harry_Potter class is an overridden
		 function of the Character class using 2d6 and Hogwarts. It takes
		 an int parameter representing the attack roll of the attacking
		 Character object and calculates the damage inflicted to its 
		 strength points and returns this damage as an int. After the
		 damage has been calculated, its strength points are updated.
		 Harry_Potter has a special ability called Hogwarts. If his strength
		 points reach 0 or below, he immediately recovers and his total
		 strength points is set to 20. He can only do this once and if he
		 were to die again he would not be able to come back to life a 
		 second time.
 ** *******************************************************************************/ 

int Harry_Potter::defense(int attack)
{
	//determine strength points and armor before attack
	int defense_strength = this -> get_strength_points();
	int armor = this -> get_armor();	

	//defense option is 2d6
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

	int count = this -> get_life_count();

	//check the strength points of Harry_Potter following the attack
	//before setting his new strength points
	int health = (this -> get_strength_points()) - damage;
	
	//if his strength points are 0 or less and he hasn't used up his
	//Hogwarts special ability granting him one free life then implement 
	//Hogwarts
	if (health <= 0 && count < 1)
	{
		this -> set_life_count(1);
		this -> set_strength_points(20);
		damage = 0;
	}			
	else
	{
		//set new strength points following attack
		this -> set_strength_points((defense_strength - damage));

		//if the damage inflicted results in negative strength points set the strength 
		//points to 0
		if ((this -> get_strength_points()) < 0)
		{
			this -> set_strength_points(0);
		}
	}
	
	return damage;
}

