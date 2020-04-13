/******************************************************************************* 
 ** Program Name: Class declaration for class Game
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This is the class declaration containing the function prototypes
		  for the Game class which implements RuPaul's Drag Race Game
 ** *******************************************************************************/ 
#ifndef GAME_HPP
#define GAME_HPP
#include "space.hpp"
#include "player.hpp"
#include "purse.hpp"

class Game
{
	private:
		int row;
		int col;
		Player *player; //pointer to the Player object
		Space ***space; //3D Space pointer
		Purse* purse; //pointer to Purse object
		bool end_game;
	
	public:
		Game();
		~Game();
		void initialize();
		void link();
		void set_player(Player* input_player);
		Player* get_player();
		Purse* get_purse();
		void place_player();
		bool get_end_game();
		void set_studio_items();
		void display_map();
		void game_over();
		bool move(int input_move);
};

#endif
