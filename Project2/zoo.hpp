/******************************************************************************* 
 ** Program Name: Class declaration for class Zoo
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the function prototypes for the class Zoo
 ** *******************************************************************************/ 
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{
	private:
		double money;
		double bonus;
		int day;
		int max_tiger_size; //tiger capacity
		int max_penguin_size; //penguin capacity
		int max_turtle_size; //turtle capacity
		int current_tiger_size; //current number of tigers
		int current_penguin_size; //current number of penguins
		int current_turtle_size; //current number of turtles
		Tiger *pTiger; //pointer to a Tiger object
		Penguin *pPenguin; //pointer to a Penguin object
		Turtle *pTurtle; //pointer to a Turtle oobject
 
	public:
		Zoo();
		~Zoo();
		double get_money();
		int get_day();
		int get_tiger_max();
		int get_penguin_max();
		int get_turtle_max();
		int get_tiger();
		int get_penguin();
		int get_turtle();
		void set_tiger_max(int tiger_capacity);
		void set_penguin_max(int penguin_capacity);
		void set_turtle_max(int turtle_capacity);
		void resize_tiger();
		void resize_penguin();
		void resize_turtle();
		void print_turtle();
		void start_game();
		void zoo_day();
		int end_day();
		void random_event();
};

#endif
