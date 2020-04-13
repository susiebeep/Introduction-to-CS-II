/******************************************************************************* 
 ** Program Name: Class declaration for class Game
 ** Author:       Susan Hibbert
 ** Date:         17 May 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the Game class which implements the Fantasy Combat Tournament
 ** *******************************************************************************/ 
#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"
#include "queue.hpp"
#include "stack.hpp"

class Game
{
	private:
		Queue *teamA; //pointer to a Queue object
		Queue *teamB; //pointer to a Queue object
		Stack *losers; //pointer to Stack object
	
	public:
		Game();
		~Game();
		int menu();
		Character* character_choice(int input_choice);	
		Queue* get_queueA();
		Queue* get_queueB();
		Stack* get_stack();
		bool do_round(Character *attacker, Character *defender);	
		Character* start(Character *char1, Character *char2);
		void tournament(Queue *teamx, Queue *teamy);	
};

#endif
