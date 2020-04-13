/******************************************************************************* 
 ** Program Name: Class declaration for class Game
 ** Author:       Susan Hibbert
 ** Date:         1 May 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the Game class which implements the Fantasy Combat Game
 ** *******************************************************************************/ 
#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"

class Game
{
	private:
		Character **characters;
	
	public:
		Game();
		~Game();
		int menu();
		Character** get_characters();
		bool do_round(Character *attacker, Character *defender);	
		void start(Character **characters);	
};

#endif
