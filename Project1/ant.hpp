/******************************************************************************* 
 ** Program Name: Header file for Ant class
 ** Author:       Susan Hibbert
 ** Date:         8 April 2019
 ** Description:  This program is the header file containing the class declaration
   		  for the class Ant
 ** *******************************************************************************/ 

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		char ant_direction;
		int ant_row;
		int ant_col;	


	public:
		char get_direction();
		void set_direction(char input_direction);
		void set_row(int input_row);
		void set_col(int input_col);
		int get_row();
		int get_col();
};

#endif
