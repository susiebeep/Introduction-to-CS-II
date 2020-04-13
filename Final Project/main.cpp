/******************************************************************************* 
 ** Program Name: Main program module for RuPaul's Drag Race Game
 ** Author:       Susan Hibbert
 ** Date:         14 May 2019
 ** Description:  This is the main program module for RuPaul's Drag Race Game.
		  A Game object and Player object are created and various functions
		  of the Game class are called to set up the game before the player
		  starts the game. A menu is then displayed to the user which 
		  provides the user with two options - to play the game or exit
 ** *******************************************************************************/ 
#include <iostream>
#include "menu.hpp"
#include "game.hpp"
#include "player.hpp"

int main()
{	
	
	//create Game and Player objects
	Game game;
	Player p1;
	
	//set Player and set up game map
	game.set_player(&p1);
	game.initialize();
	game.link();
	game.set_studio_items();

	//place player on game map
	game.place_player();

	//display menu options to user
	display_menu(&game);
	
	return 0;
}
