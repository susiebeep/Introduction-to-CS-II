/********************************************************************************** 
 ** Program Name: Source file for the class Player
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program contains the function definitions for the class Player
 ** *******************************************************************************/ 
#include "player.hpp"
#include <iostream>


/********************************************************************************** 
 ** Description: The default constructor for the Player class sets its int data 
		 members player_row and player_col to -1 and its int data member
		 health to 100 in a newly constructed Player object
 ** *******************************************************************************/ 

Player::Player()
{
	player_row = -1;
	player_col = -1;
	health = 100;
}


/********************************************************************************** 
 ** Description: The set_row function of the Player class has no return type and
		 takes an int parameter representing a row on the game map which it
		 used to set its int data member player_row
 ** *******************************************************************************/ 

void Player::set_row(int input_row)
{
	this -> player_row = input_row;
}	


/********************************************************************************** 
 ** Description: The set_col function of the Player class has no return type and
		 takes an int parameter representing a column on the game map which
		 is used to set the int data member player_col
 ** *******************************************************************************/ 

void Player::set_col(int input_col)
{
	this -> player_col = input_col;
}


/********************************************************************************** 
 ** Description: The get_row function of the Player class has no parameters and
		 returns the int data member player_row which represents the row
		 the player is on on the game map
 ** *******************************************************************************/ 

int Player::get_row()
{
	return this -> player_row;
}


/********************************************************************************** 
 ** Description: The get_col function of the Player class has no parameters and
		 returns the int data member player_col which represents the column
		 the player is on on the game map
 ** *******************************************************************************/ 

int Player::get_col()
{
	return this -> player_col;
}


/********************************************************************************** 
 ** Description: The get_health function of the Player class has no parameters and
		 returns the int data member health which represents the health
		 of the player
 ** *******************************************************************************/ 

int Player::get_health()
{
	return this -> health;
}


/********************************************************************************** 
 ** Description: The lose_health function of the Player class has no parameters and
		 or return type. It subtracts 10 points from the int data member
		 health, representing the health of the player, after each move the
		 player makes on the game map. If the player's health drops below 0
		 their health is set to 0, at which point the game ends
 ** *******************************************************************************/ 

void Player::lose_health()
{	
	if (health >= 10)
	{
		this -> health = health - 10;
	}
	else
	{
		this -> health = 0;
	}
}


/********************************************************************************** 
 ** Description: The set_health function of the Player class has no return type and
		 takes an int parameter representing a new health value and uses
		 this value to set the int data member health of the player
 ** *******************************************************************************/ 

void Player::set_health(int new_health)
{
	this -> health = new_health;
}	


