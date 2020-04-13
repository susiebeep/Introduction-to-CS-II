/******************************************************************************* 
 ** Program Name: Header file for the Board class
 ** Author:       Susan Hibbert
 ** Date:         8 April 2019
 ** Description:  This program is the header file containing the function prototypes
		  for the class Board
 ** *******************************************************************************/ 
#include "ant.hpp"
#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
	private:
		int row;
		int col;
		int steps;
		char **array;		
		Ant *mr_ant;

	public:
		Board();
		~Board();
		void initialize(int total_row, int total_col);
		int get_rows();
		int get_cols();
		int get_steps();
		void display_board();
		void set_steps(int input_steps);
		void place_ant(Ant *input_ant, int input_row, int input_col);
		void move_ant(Ant *input_ant);

};

#endif
