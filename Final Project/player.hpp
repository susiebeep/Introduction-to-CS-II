/******************************************************************************* 
 ** Program Name: Header file for the class Player
 ** Author:       Susan Hibbert
 ** Date:         29 May 2019
 ** Description:  This program is the header file containing the class declaration
   		  for the class Player
 ** *******************************************************************************/ 
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	private:
		int player_row;
		int player_col;	
		int health;

	public:
		Player();
		void set_row(int input_row);
		void set_col(int input_col);
		int get_row();
		int get_col();
		int get_health();
		void lose_health();
		void set_health(int new_health);
};

#endif
