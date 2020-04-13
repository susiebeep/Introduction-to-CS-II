/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Game class
 ** Author:       Susan Hibbert
 ** Date:         17 May 2019
 ** Description:  This program contains the member function definitions for the Game
		  class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
		  Chapter 3.10 Random Numbers, 
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "character.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "barbarian.hpp"
#include "game.hpp"
#include "menu.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/********************************************************************************** 
 ** Description: The default construtor for the Game class dynamically allocates a
		 Queue object to each of its two Queue pointer data members teamA
		 and teamB and a new Stack object to its Stack pointer data member
		 losers in a newly created Game object
 ** *******************************************************************************/ 

Game::Game()
{
	teamA = new Queue;
	teamB = new Queue;
	losers = new Stack;
}


/********************************************************************************** 
 ** Description: The destructor of the Game class frees dynamically allocated memory
		 allocated to the two Queue objects and Stack object by the default
		 constructor
 ** *******************************************************************************/ 
Game::~Game()
{
	delete teamA;
	delete teamB;
	delete losers;
}


/********************************************************************************** 
 ** Description: The Game menu function calls upon a separate display_menu function
		 to print the Fantasy Combat Tournament's menu to the user. The 
		 display_menu function takes the Game object that called the Game menu
		 function as a parameter and returns an int value indicating the 
		 user's menu choice. The Game menu function itself does not take any
		 parameters but returns the user's menu choice from the display_menu
		 function to the calling program
 ** *******************************************************************************/ 

int Game::menu()
{
	int choice = display_menu(this);
	return choice;
}


/********************************************************************************** 
 ** Description: The character_choice function of the Game class takes an int 
		 parameter representing the user's choice of Character from the menu
		 then dynamically allocates a Character object of that type and
		 returns a pointer to the Character object to the calling program
 ** *******************************************************************************/ 

Character* Game::character_choice(int input_choice)
{
	Character *type = NULL;

	//create a Character object based on the user's choice
	if (input_choice == 1)
	{
		//dynamically allocate a Vampire object to a Character pointer
		type = new Vampire;
	}
	
	if (input_choice == 2)
	{
		//dynamically allocate a Barbarian object to a Character pointer
		type = new Barbarian;
	}

	if (input_choice == 3)
	{
		//dynamically allocate a Blue_Men object to a Character pointer
		type = new Blue_Men;
	}
	
	if (input_choice == 4)
	{
		//dynamically allocate a Medusa object to a Character pointer
		type = new Medusa;
	}

	if (input_choice == 5)
	{
		//dynamically allocate a Harry_Potter object to a Character pointer
		type = new Harry_Potter;
	}

	return type;
}


/********************************************************************************** 
 ** Description: The get_queueA function of the Game class takes no parameters
		 and returns teamA, the Queue pointer data member of the Game class
 ** *******************************************************************************/ 

Queue* Game::get_queueA()
{
	return this -> teamA;
}


/********************************************************************************** 
 ** Description: The get_queueB function of the Game class takes no parameters
		 and returns teamB, the Queue pointer data member of the Game class
 ** *******************************************************************************/ 

Queue* Game::get_queueB()
{
	return this -> teamB;
}


/********************************************************************************** 
 ** Description: The get_stack function of the Game class takes no parameters
		 and returns losers, the Stack pointer data member of the Game class
 ** *******************************************************************************/ 

Stack* Game::get_stack()
{
	return this -> losers;
}


/********************************************************************************** 
 ** Description: The do_round function of the Game class takes a Character pointer
		 to the attacking Character object and a Character pointer to the
		 defending Character object. It returns the boolean true to the
		 start function if the defending Character object is still alive
		 at the end of the attack, and returns false if it died which ends
		 the game
 ** *******************************************************************************/ 

bool Game::do_round(Character *attacker, Character *defender)
{
	//boolean flag set to true if the defending character is alive
	bool alive = true;	

	//call attacker's attack funtion
	int attack = attacker -> attack();

	//call defender's defense function and calculate damage of attack
	int damage = defender -> defense(attack);	

	//if the defender has 0 strength points after the attack the boolean
	//flag is set to false
	if ((defender -> get_strength_points()) == 0)
	{
		alive = false;
	}

	return alive;
}


/********************************************************************************** 
 ** Description: The start function begins the Fantasy Combat Game Tournament. It
		 takes 2 Character pointers as parameters and at the end of the 
		 combat returns the Character pointer to the winning Character object. 
		 One of the Character objects is selected at random to start attacking.
		 Then the attacking and defending Character objects are passed to the
		 do_round function, where the combat happens. The do_round function
		 will continue to be called after each round as long as both 
		 characters are still alive
 ** *******************************************************************************/ 

Character* Game::start(Character *char1, Character *char2)
{
		//decide who starts as attacker and who starts as defender randomly
		int first = rand() % 2 + 1;
		Character *attacker;
		Character *defender;
		
		if (first == 1)
		{
			attacker = char1;
			defender = char2;
		}
		
		else
		{
			attacker = char2;
			defender = char1;
		}

		//call do_round function to initiate the combat. Opponents will swap
		//attacker and defender positions during the round and continue to
		//fight until one of the characters dies
		while (do_round(attacker, defender))
		{
			Character *temp;
			temp = attacker;
			attacker = defender;
			defender = temp;	
			
		}
		
		//display who won the fight	
		std::string defendType = defender -> get_name();
		std::string attackType = attacker -> get_name();
		int defendPoint = defender -> get_strength_points();
		int attackPoint = attacker -> get_strength_points();
		Character* winner = NULL;

		if (defendPoint == 0)
		{
			std::cout << attackType << " won the fight and has "
				  << attackPoint << " strength points before recovery"
				  << std::endl;
	
			winner = attacker;
		}
			
		if (attackPoint == 0)
		{
			std::cout << defendType << " won the fight and has "					
				  << defendPoint << " strength points before recovery"
				  << std::endl;	

			winner = defender;
		}
		
		//pointer to winning Character object is returned to calling
		//function
		return winner;
}


/********************************************************************************** 
 ** Description: The tournament function of the Game class implements the tournament
		 aspect of the Fantasy Combat Tournament. It has no return type and
		 takes two Queue pointers as parameters, which represent the two 
		 teams. The Characters at the head of each Queue object fight each 
		 other. When the fight is over, the winning Character gets put to the
		 tail of its Queue object and the losing Character is removed from 
		 its Queue object and goes to the head of the Stack object, which
		 houses the losing Characters from both teams. The winning Character 
		 will have some percentage of the damage they incurred during the
		 fight restored when they move to the back of their lineup. Then, the
		 next two Characters in each lineup fight each other. Characters
		 fight in the order they were entered by the user. Wins score the
		 respective team 1 point, and losses score 0 points. The tournament
		 ends when one of the teams has no Characters left to fight. When the
		 tournament ends, the final scores for both teams are displayed along
		 with the winner of the tournament
 ** *******************************************************************************/ 

void Game::tournament(Queue *teamx, Queue *teamy)
{
	int pointsA = 0; //initialize Team A points
	int pointsB = 0; //initialize Team B points
	int round = 1; //initialize round counter


	//retrieve the first two characters to fight at the head of each queue
	Character* headA = teamx -> getHead();
	Character* headB = teamy -> getHead();

	//get the names of the two teams
	std::string teamA = teamx -> getName();
	std::string teamB = teamy -> getName();				

	//continue to fight until one of the teams has no characters left
	while (headA != NULL && headB != NULL)
	{	
		std::cout << "--------------- ROUND " << round << " ---------------" 
			  << std::endl;
		
		//get the names of the two opponents
		std::string charA = headA -> get_name();
		std::string charB = headB -> get_name();				

		//get the types of the two opponents
		std::string typeA = headA -> get_type();
		std::string typeB = headB -> get_type();
	
		//display the names and types of the fighting Characters from both teams
		std::cout << " " << std::endl;
		std::cout << "***** " << teamA << ": " << charA << " the " << typeA
			  << " vs " << teamB << ": " << charB << " the " << typeB 
			  << " *****"<< std::endl;
		std::cout << " " << std::endl;
	
		//the two players fight and the winning Character is returned
		Character* winner = start(headA, headB);
		
		//if winner is in team A
		if (winner == headA)
		{
			//call recovery function for winner
			headA -> recovery();
		
			//move winner to back of queue
			teamx -> moveHead();
	
			//move loser to loser stack
			losers -> pushHead(headB);
		
			//remove loser from team lineup
			teamy -> removeHead();
			
			//add 1 point to team A's score
			pointsA++;
		}

		//if winner is in team B
		if (winner == headB)
		{
			//call recovery function for winner
			headB -> recovery();
		
			//move winner to back of queue
			teamy -> moveHead();
		
			//move loser to loser stack
			losers -> pushHead(headA);
			
			//remove loser from team lineup
			teamx -> removeHead();
			
			//add 1 point to team B's score
			pointsB++;
		}

		//display some statistics after each round
		std::cout << " " << std::endl;
		std::cout << "Team A now: " << std::endl;
		teamx -> printQueue();
		std::cout << "Team A points: " << pointsA << std::endl;
		std::cout << " " << std::endl;

		std::cout << "Team B now: " << std::endl;
		teamy -> printQueue();
		std::cout << "Team B points: " << pointsB << std::endl;
		std::cout << " " << std::endl;

		std::cout << "Loser Pile: " << std::endl;
		losers -> printStack();
		std::cout << " " << std::endl;
		
		//retrieve first two characters from the two new lineup queues
		headA = teamx -> getHead();
		headB = teamy -> getHead();	
		
		round++;
	}
	
	//display the final score for each team
	
	std::cout << " " << std::endl;
	std::cout << "**********FINAL SCORES**********" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Team A: " << pointsA << " points" << std::endl;
	std::cout << "Team B: " << pointsB << " points" << std::endl;
	std::cout << " " << std::endl;

	//determine the winner
	if (pointsA > pointsB)
	{
		std::cout << "Team A won with " << pointsA << " points!" << std::endl;
	}

	if (pointsB > pointsA)
	{
		std::cout << "Team B won with " << pointsB << " points!" << std::endl;
	}

	if (pointsA == pointsB)
	{
		std::cout << "Team A and Team B drew with " << pointsA << " points!" << std::endl;
	}

}

