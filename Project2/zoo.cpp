/********************************************************************************** 
 ** Program Name: Source code for the member functions of the Zoo class
 ** Author:       Susan Hibbert
 ** Date:         18 April 2019
 ** Description:  This program contains the member function definitions for the Zoo
		  class
 ** Citations:	  Chapter 11, More about Classes and Object-Orientated Programming,
		  Starting Out With C++ Early Objects, 9th Edition, Gaddis
		  C++ copy constructor for class with dynamically allocated array,
		  Stack Overflow
		  Chapter 3.10 Random Numbers, Starting Out With C++ Early Objects;
		  9th Edition, Gaddis
 ** *******************************************************************************/ 
#include "zoo.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "animal.hpp"
#include "input.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

/********************************************************************************** 
 ** Description: The default construtor for the Zoo class initializes the member
		 variables of the newly	constructed Zoo object. It sets the day to 0,
		 starting bank balance to $100,000 and the bonus to $0. A dynamic
		 array of 10 Tiger objects is created and allocated to pTiger, along
		 with a dynamic array of 10 Penguin objects and a dynamic array of 10
		 Turtle objects, each allocated to their respective pointers. The
		 maximum capacity for each animal type is set to 10 ie. the current
		 size of each animal's array, and the current level of each animal is
		 set to 0
 ** *******************************************************************************/ 

Zoo::Zoo()
{
	this -> money = 100000.0;
	this -> bonus = 0.0;
	this -> max_tiger_size = 10;
	this -> max_penguin_size = 10;
	this -> max_turtle_size = 10;
	this -> current_tiger_size = 0;
	this -> current_penguin_size = 0;
	this -> current_turtle_size = 0;
	this -> day = 0;
	pTiger = new Tiger[10];
	pPenguin = new Penguin[10];
	pTurtle = new Turtle[10];

}


/********************************************************************************** 
 ** Description: The Zoo destructor frees the dynamically allocated Tiger, Penguin
		 and Turtle arrays
 ** *******************************************************************************/ 

Zoo::~Zoo()
{
	delete [] pTiger;	
	delete [] pPenguin;
	delete [] pTurtle;

}


/********************************************************************************** 
 ** Description: The get_money function of the Zoo class takes no parameters and 
		 returns the double member variable money representing how much money
		 is in the bank
 ** *******************************************************************************/ 

double Zoo::get_money()
{
	return this -> money;
}


/********************************************************************************** 
 ** Description: The get_day function of the Zoo class takes no parameters and 
		 returns the int member variable day representing the current day
		 at the Zoo
 ** *******************************************************************************/ 

int Zoo::get_day()
{
	return this -> day;
}


/********************************************************************************** 
 ** Description: The get_tiger_max function of the Zoo class takes no parameters and
		 returns the int member variable max_tiger_size representing the
		 maximum number of tigers the Zoo can currently have
 ** *******************************************************************************/ 

int Zoo::get_tiger_max()
{
	return this -> max_tiger_size;
}


/********************************************************************************** 
 ** Description: The get_penguin_max function of the Zoo class takes no parameters and
		 returns the int member variable max_penguin_size representing the
		 maximum number of penguins the Zoo can currently have
 ** *******************************************************************************/ 

int Zoo::get_penguin_max()
{
	return this -> max_penguin_size;
}

/********************************************************************************** 
 ** Description: The get_turtle_max function of the Zoo class takes no parameters and
		 returns the int member variable max_turtle_size representing the
		 maximum number of turtles the Zoo can currently have
 ** *******************************************************************************/ 

int Zoo::get_turtle_max()
{
	return this -> max_turtle_size;
}

/********************************************************************************** 
 ** Description: The get_tiger function of the Zoo class takes no parameters and
		 returns the int member variable current_tiger_size representing the
		 current number of tigers the Zoo currently has
 ** *******************************************************************************/ 

int Zoo::get_tiger()
{
	return this -> current_tiger_size;
}

/********************************************************************************** 
 ** Description: The get_penguin function of the Zoo class takes no parameters and
		 returns the int member variable current_penguin_size representing the
		 current number of penguins the Zoo currently has
 ** *******************************************************************************/ 

int Zoo::get_penguin()
{
	return this -> current_penguin_size;
}

/********************************************************************************** 
 ** Description: The get_turtle function of the Zoo class takes no parameters and
		 returns the int member variable current_turtle_size representing the
		 current number of turtles the Zoo currently has
 ** *******************************************************************************/ 

int Zoo::get_turtle()
{
	return this -> current_turtle_size;
}

/********************************************************************************** 
 ** Description: The set_tiger_max function of the Zoo class has no return type and
		 takes one int parameter representing the maximum tiger capacity of
		 the Zoo and sets it to the int member variable max_tiger_size
 ** *******************************************************************************/ 

void Zoo::set_tiger_max(int tiger_capacity)
{
	this -> max_tiger_size = tiger_capacity;
}

/********************************************************************************** 
 ** Description: The set_penguin_max function of the Zoo class has no return type and
		 takes one int parameter representing the maximum penguin capacity of
		 the Zoo and sets it to the int member variable max_penguin_size
 ** *******************************************************************************/ 

void Zoo::set_penguin_max(int penguin_capacity)
{
	this -> max_penguin_size = penguin_capacity;
}

/********************************************************************************** 
 ** Description: The set_turtle_max function of the Zoo class has no return type and
		 takes one int parameter representing the maximum turtle capacity of
		 the Zoo and sets it to the int member variable max_turtle_size
 ** *******************************************************************************/ 

void Zoo::set_turtle_max(int turtle_capacity)
{
	this -> max_turtle_size = turtle_capacity;
}


/********************************************************************************** 
 ** Description: The resize_tiger function of the Zoo class take no parameters and
		 has no return type. It doubles the current size of the dynamic
		 array of Tiger objects in order to make space for new Tiger objects
		 added to the Zoo
 ** *******************************************************************************/ 

void Zoo::resize_tiger()
{
	Tiger *pTiger1;

	//set new tiger capacity to double its current capacity/array size
	max_tiger_size = max_tiger_size * 2;

	//create new dynamic array of Tiger objects which is double the size of the old array
	pTiger1 = new Tiger[max_tiger_size];
	
	//copy each Tiger object from the old array into the new array -
	//the copy constructor of the Tiger class should be invoked
	for (int i = 0; i < current_tiger_size; ++i)
	{
		pTiger1[i] = pTiger[i];
	}
	
	//delete the old array
	delete [] pTiger;

	//set the pTiger pointer to the address of the new array
	pTiger = pTiger1;
}


/********************************************************************************** 
 ** Description: The resize_penguin function of the Zoo class take no parameters and
		 has no return type. It doubles the current size of the dynamic
		 array of Penguin objects in order to make space for new Penguin
		 objects added to the Zoo
 ** *******************************************************************************/ 

void Zoo::resize_penguin()
{
	Penguin *pPenguin1;

	//set new penguin capacity to double its current capacity/array size
	max_penguin_size = max_penguin_size * 2;

	//create new dynamic array of Penguin objects which is double the size of the old array
	pPenguin1 = new Penguin[max_penguin_size];
	
	//copy each Penguin object from the old array into the new array -
	//the copy constructor of the Penguin class should be invoked
	for (int i = 0; i < current_penguin_size; ++i)
	{
		pPenguin1[i] = pPenguin[i];
	}
	
	//delete the old array
	delete [] pPenguin;

	//set the pPenguin pointer to the address of the new array
	pPenguin = pPenguin1;
}


/********************************************************************************** 
 ** Description: The resize_turtle function of the Zoo class take no parameters and
		 has no return type. It doubles the current size of the dynamic
		 array of Turtle objects in order to make space for new Turtle
		 objects added to the Zoo
 ** *******************************************************************************/ 

void Zoo::resize_turtle()
{
	Turtle *pTurtle1;

	//set new turtle capacity to double its current capacity/array size
	max_turtle_size = max_turtle_size * 2;

	//create new dynamic array of Turtle objects which is double the size of the old array
	pTurtle1 = new Turtle[max_turtle_size];
	
	//copy each Turtle object from the old array into the new array - 
	//the copy constructor of the Turtle class should be invoked
	for (int i = 0; i < current_turtle_size; ++i)
	{
		pTurtle1[i] = pTurtle[i];
	}
	
	//delete the old array
	delete [] pTurtle;

	//set the pTurtle pointer to the address of the new array
	pTurtle = pTurtle1;
}


/********************************************************************************** 
 ** Description: The print_turtle function of the Zoo class takes no parameters and
		 has no return type. It displays information for each of the turtles
		 at the zoo by calling upon the print_info function of the Animal 
		 class and was created to test the functionality of the 
		 resize_turtle function
 ** *******************************************************************************/ 

void Zoo::print_turtle()
{
	for (int i = 0; i < max_turtle_size; ++i)
	{
		std::cout << "Turtle number: " << i + 1 << std::endl;	
		pTurtle[i].print_info();
		std::cout << " " << std::endl;
	}
}

/********************************************************************************** 
 ** Description: The start_game function of the Zoo class takes no parameters and
		 has no return type. It is called at the very beginning of every
		 game, before the Zoo day starts. It allows the user to purchase
		 1 or 2 of every animal type to populate the Zoo before the game
		 actually begins. The age of each animal purchased is set to 1 day
		 old via a for-loop and a pointer to a Tiger, Penguin or Turtle
		 array respectively. The quantity of each animal type purchased is
		 set in the Zoo object. The cost of each animal purchased by the user
		 is subtracted from the starting bank balance of the Zoo. Each time
		 the user is prompted to enter information in this function, their
		 input is validated and converted to an integer. If they do not select
		 a correct option or enter invalid characters, they will be 
		 continually prompted until they enter valid input
 ** *******************************************************************************/ 

void Zoo::start_game()
{
	std::string tigers;
	std::string penguins;
	std::string turtles;
	int val_tigers;
	int val_penguins;
	int val_turtles;
	double tiger_cost;
	double penguin_cost;
	double turtle_cost;	

	std::cout << " " << std::endl;	
	std::cout << "********************" << "WELCOME TO ZOO TYCOON!" << "********************" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "How many tigers would you like to purchase for the zoo?" << std::endl;
	std::cout << "Press 1 to purchase 1 tiger, or press 2 to purchase 2 tigers" << std::endl;
	std::getline(std::cin, tigers);
	
	//validate user's choice and convert to an integer
	val_tigers = int_input_val(tigers);

	while (val_tigers < 1 || val_tigers > 2)
	{
		std::cout << "Oops! That's the wrong number of tigers! Please select 1 or 2" << std::endl;
		std::getline(std::cin, tigers);
		val_tigers = int_input_val(tigers);
	}	

	//set number of tigers in Zoo object
	this -> current_tiger_size = val_tigers;	
	
	//set age of each tiger to 1 day old in Tiger array
	for (int i = 0; i < val_tigers; ++i)
	{
		pTiger[i].set_age(1);
	}
	
	//determine cost of tiger
	tiger_cost = pTiger -> get_cost();
		
	std::cout << " " << std::endl;	
	std::cout << "How many penguins would you like to purchase for the zoo?" << std::endl;
	std::cout << "Press 1 to purchase 1 penguin, or press 2 to purchase 2 penguins" << std::endl;
	std::getline(std::cin, penguins);
	
	//validate user's choice and convert to an integer
	val_penguins = int_input_val(penguins);

	while (val_penguins < 1 || val_penguins > 2)
	{
		std::cout << "Oops! That's the wrong number of penguins! Please select 1 or 2" << std::endl;
		std::getline(std::cin, penguins);
		val_penguins = int_input_val(penguins);
	}	
	//set number of penguins in Zoo object
	this -> current_penguin_size = val_penguins;	

	//set age of penguins to 1 day old in Penguin array
	for (int i = 0; i < val_penguins; ++i)
	{
		pPenguin[i].set_age(1);
	}

	//determine cost of penguin
	penguin_cost = pPenguin -> get_cost(); 

	std::cout << " " << std::endl;
	std::cout << "How many turtles would you like to purchase for the zoo?" << std::endl;
	std::cout << "Press 1 to purchase 1 turtle, or press 2 to purchase 2 turtles" << std::endl;
	std::getline(std::cin, turtles);
	
	//validate user's choice and convert to an integer
	val_turtles = int_input_val(turtles);

	while (val_turtles < 1 || val_turtles > 2) 
	{
		std::cout << "Oops! That's the wrong number of turtles! Please select 1 or 2" << std::endl;
		std::getline(std::cin, turtles);
		val_turtles = int_input_val(turtles);
	}	
	//set number of turtles in Zoo object
	this -> current_turtle_size = val_turtles;	

	//set age of turtle to 1 day old in Turtle array
	for (int i = 0; i < val_turtles; ++i)
	{
		pTurtle[i].set_age(1);
	}
	
	//determine cost of turtle
	turtle_cost = pTurtle -> get_cost();

	//deduct the cost of each type of animal purchased from bank balance
	money = money - (val_tigers * tiger_cost) - (val_penguins * penguin_cost) - (val_turtles * turtle_cost);
	
}


/********************************************************************************** 
 ** Description: The random_event function of the Zoo class takes no parameters and
		 has no return type. One randomized event takes place during every
		 Zoo day. A random number generator generates a number between 1 and
		 4, representing the 4 random event options available. The random 
		 events are:
		1. A sickness occurs in a Zoo animal and the animal dies
		2. A boom in Zoo attendance occurs
		3. A baby animal is born
		4. Nothing happens
		Within random events 1 and 3, there is another random number generator
		which generates a number between 1 and 3, representing the 3 different
		animal types at the Zoo, which determines which animal type will die
		or have a baby. If none of that animal type are old enough to have a 
		baby or if there are none of that animal type at the Zoo, the two other
		animal types are checked for eligibility to have a baby or become sick
		and be removed from the Zoo. If no animals are eligible to have a baby
		or if there are no animals at the Zoo, a message will be displayed on
		screen informing the user
 ** *******************************************************************************/

void Zoo::random_event()
{
	int tiger = 1;
	int penguin = 2;
	int turtle = 3;
	int num = rand() % 4 + 1; //random event number generator


	//sickness occurs in an animal in the zoo- an animal type is picked at random
	//and an animal of that type is removed from its array
	if (num == 1)
	{
		bool sick_tiger = true; //switches to false when Tigers have been searched
		bool sick_penguin = true; //switches to false when Penguins have been searched
		bool sick_turtle = true; //switches to false when Turtles have been searched
		bool found = false; // switches to true when an animal has been found to get sick

		std::cout << "Oh no! A zoo animal is sick!" << std::endl;
	
		//randomly select an animal type to get sick
		int sickness = rand() % 3 + 1;
	
		// search through all the zoo animals while there is at least one animal type still to search
		// and a sick animal has not been found
		while (!found && (sick_tiger || sick_penguin || sick_turtle))
		{
			//if a tiger is sick
			if (sickness == 1)
			{	
				//if tigers have not already been searched
				if (sick_tiger)
				{
					//if the zoo has at least 1 tiger
					if (current_tiger_size > 0)
					{
						std::cout << "One of your tigers suddenly fell ill and you need to get it put to sleep :-("
							  << std::endl;
					
						//set 'dead' Tiger object's age back to the default value of 0
						pTiger[current_tiger_size - 1].set_age(0);

						//update current tiger population
						current_tiger_size = current_tiger_size - 1;
						
						//indicates a sick animal has been found
						found = true;
					}
					//if the zoo has no tigers, set the sick_tiger bool to false and check if the zoo has penguins
					else
					{
						sick_tiger = false;
						sickness++;
					}
				}
			}
	
		
			//if a penguin is sick
			if (sickness == 2)
			{
				//if penguins have not already been searched
				if (sick_penguin)
				{
					//if the zoo has at least 1 penguin
					if (current_penguin_size > 0)
					{
						std::cout << "One of your penguins suddenly fell ill and you need to get it put to sleep :-("
							  << std::endl;
					
						//set 'dead' Penguin object's age back to the default value of 0
						pPenguin[current_penguin_size - 1].set_age(0);

						//update current penguin population
						current_penguin_size = current_penguin_size - 1;
					
						//indicates a sick animal has been found
						found = true;
					}
					//if the zoo has no penguins, set the sick_penguin bool to false and check if the zoo has turtles
					else
					{
						sick_penguin = false;
						sickness++;
					}
				}
			}
	
			//if a turtle is sick
			if (sickness == 3)
			{
				//if turtles have not already been searched
				if (sick_turtle)
				{
					//if the zoo has at least 1 turtle
					if (current_turtle_size > 0)
					{
						std::cout << "One of your turtles suddenly fell ill and you need to get it put to sleep :-("
							  << std::endl;
					
						//set 'dead' Turtle object's age back to the default value of 0
						pTurtle[current_turtle_size - 1].set_age(0);

						//update current turtle population
						current_turtle_size = current_turtle_size - 1;
					
						//indicates a sick animal has been found
						found = true;
					}
					//if the zoo has no turtles set the sick_turtle bool to false and check if the zoo has tigers	
					else
					{
						sick_turtle = false;
						sickness = sickness - 2;
					}
				}
			}
		}

		//if the zoo has no animals
		if (!sick_tiger && !sick_penguin && !sick_turtle && !found)
		{
			std::cout << "It looks like the zoo has no animals to get sick!" << std::endl;
		}
	}
	
	//boom in zoo attendance
	if (num == 2)
	{
		double award = rand() % 251 + 250; // generate a bonus between 250 and 500 dollars
		bonus = (current_tiger_size) * award; //bonus is calculated based on number of tigers in the zoo
		std::cout << "There is a boom in zoo attendance!" << std::endl;
		
		//if the zoo has at least 1 tiger
		if (current_tiger_size > 0)
		{
			std::cout << "You generate a bonus of $" << bonus << "!" << std::endl;
		}

		//if the zoo has no tigers
		else
		{
			std::cout << "Unfortunately you don't generate a bonus as the zoo has no tigers!" << std::endl;
		}
		
	}
	
	//one of the zoo animals has a baby
	if (num == 3)
	{
		bool pregnant_tiger = true; //switches to false if Tigers have been searched
		bool pregnant_penguin = true; //switches to false if Penguins have been searched
		bool pregnant_turtle = true; //switches to false if Turtles have been searched
		bool found = false; //switches to true is animal old enough to have a baby is found

		std::cout << "Could one of the animals be pregnant...?" << std::endl;
	
		//randomly select an animal type to have a baby
		int pregnant = rand() % 3 + 1;


		// search through all the zoo animals while there is at least one animal type still to search
		// and an animal old enough to have a baby has not been found
		while (!found && (pregnant_tiger || pregnant_penguin || pregnant_turtle))
		{
			//if a tiger is pregnant
			if (pregnant == 1)
			{

				//if bool pregnant_tiger is set to true the tiger
				//population has not been checked yet
				if (pregnant_tiger)
				{	
	
					//check to see if the zoo has tigers
					if (current_tiger_size > 0)
					{

						//check if there is a tiger that is old enough to have a baby
						for (int i = 0; i < current_tiger_size && !found; ++i)
						{
							//if there is a tiger that is old enough to have a cub check
							//the current size of the Tiger array and resize it if it is not
							//large enough to accomodate another Tiger object, then increase
							//the tiger population by 1. By default, new Tiger objects are
							//set to age 0 on instantiation so the age of the new cub does
							//not need to be set by a separate function
						
							double age = pTiger[i].get_age();
							if (age >= 3)
							{
								std::cout << "One of your tigers gave birth to a tiger cub!" << std::endl;

								found = true; //tiger old enough to have a baby is found

								if (current_tiger_size == max_tiger_size)
								{
									resize_tiger();
									current_tiger_size = current_tiger_size + 1;
								}
								else
								{
									current_tiger_size = current_tiger_size + 1;
								}	
								
							}
						}
						//if no tiger is found to be old enough to have babies
						if (!found)
						{
							std::cout << "No tigers are old enough to have a cub!" << std::endl;
							pregnant_tiger = false;
							pregnant++;
						}
					}
					//if the zoo has no tigers, set pregnant_tiger to false and check the penguins
					else
					{
						std::cout << "There are no tigers at the zoo to have a baby!" << std::endl;
						pregnant_tiger = false;
						pregnant++;
					}

				}
			}

			//if a penguin is pregnant
			if (pregnant == 2)
			{	
			
				//if bool pregnant_penguin is set to true the penguin
				//population has not been checked yet
				if (pregnant_penguin)
				{	

					//check to see if the zoo has penguins
					if (current_penguin_size > 0)
					{
						//check if there is a penguin that is old enough to have a baby
						for (int i = 0; i < current_penguin_size && !found; ++i)
						{
							//if there is a penguin that is old enough to have 5 babies check the
							//current size of the Penguin array and resize it if it is not large
							//enough to accomodate 5 Penguin objects, then increase the penguin
							//population by 5. By default, new Penguin objects are set to age 0 on
							//instantiation so the ages of the 5 baby penguins do not need to be set
							//by a separate function

							double age = pPenguin[i].get_age();
							if (age >= 3)
							{
								std::cout << "One of your penguins gave birth to 5 chicks!" << std::endl;

								found = true; //penguin old enough to have a baby is found

								if (current_penguin_size + 5 > max_penguin_size)
								{
									resize_penguin();
									current_penguin_size = current_penguin_size + 5;
								}
								else
								{
									current_penguin_size = current_penguin_size + 5;
						
								}	
								
							}
						}
		
						//if no penguin is found to be old enough to have babies
						if (!found)
						{
							std::cout << "No penguins are old enough to have chicks!" << std::endl;
							pregnant_penguin = false;
							pregnant++;
						}
					}

					//if the zoo has no penguins, set pregnant_penguin to false and check the turtles
					else
					{
						std::cout << "There are no penguins at the zoo to have babies!" << std::endl;
						pregnant_penguin = false;
						pregnant++;
					}

				}
			}
	
			//if a turtle is pregnant
			if (pregnant == 3)
			{
				
				//if set bool pregnant_turtle is set to true the turtle
				//population has not been checked yet
				if (pregnant_turtle)
				{	
					//check to see if the zoo has turtles
					if (current_turtle_size > 0)
					{
						//check if there is a turtle that is old enough to have babies
						for (int i = 0; i < current_turtle_size && !found; ++i)
						{
							//if there is a turtle that is old enough to have 10 babies check
							//the current size of the Turtle array and resize it if it is not
							//large enough to accomodate 10 Turtle objects, then increase the
							//turtle population by 10. By default, new Turtle objects are set
							//to age 0 on instantiation so the ages of the 10 baby turtles do
							//not need to be set by a separate function
						
							double age = pTurtle[i].get_age();
							if (age >= 3)
							{
								std::cout << "One of your turtles gave birth to 10 hatchlings!" << std::endl;

								found = true; //turtle old enough to have a baby is found

								if (current_turtle_size + 10 > max_turtle_size)
								{
									resize_turtle();
									current_turtle_size = current_turtle_size + 10;
			
								}
								else
								{
									current_turtle_size = current_turtle_size + 10;
								}	
								
							}
						}
	
						//if no turtle is found to be old enough to have babies
						if (!found)
						{
							std::cout << "No turtles are old enough to have hatchlings!" << std::endl;
							pregnant_turtle = false;
							pregnant = pregnant - 2;
						}
					}

					//if the zoo has no turtles, set pregnant_turtle to false and check the tigers
					else
					{
						std::cout << "There are no turtles at the zoo to have babies!" << std::endl;
						pregnant_turtle = false;
						pregnant = pregnant - 2;
					}

				}
			}
		}

		//if there are no zoo animals able to have a baby
		if (!found && !pregnant_tiger && !pregnant_penguin && !pregnant_turtle)
		{
			std::cout << "False alarm! There won't be any baby animals born today :-(" << std::endl;
		}
	}

	//nothing happens
	if (num == 4)
	{
		std::cout << "It's a non-eventful day at the zoo!" << std::endl;
	}
}


/********************************************************************************** 
 ** Description: The zoo_day function of the Zoo class takes no parameters and has 
		 no return type. This function implements a day at the Zoo. All
		 the animals are fed at the start of every Zoo day and the cost of
		 feeding each animal type is subtracted from the bank balance. Each
		 animal in the zoo ages by one day every Zoo day. The random_event
		 function is called by this function which causes a random event to
		 take place during the Zoo day
 ** *******************************************************************************/ 

void Zoo::zoo_day()
{	
	double feed_tiger;
	double feed_penguin;
	double feed_turtle;	
	int tiger_age;
	int penguin_age;
	int turtle_age;
	bonus = 0.0; //reset bonus to $0 every day

	std::cout << " " << std::endl;	
	std::cout << "**************************" << "START OF DAY " << day << "**********************" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "CURRENT STATS" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Tiger Population: " << current_tiger_size << std::endl;
	std::cout << "Penguin Population: " << current_penguin_size << std::endl;
	std::cout << "Turtle Population: " << current_turtle_size << std::endl;
	std::cout << "Bank Balance: $" << money << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << "You need to feed all your animals!" << std::endl;
	std::cout << " " << std::endl;

	//calculate the feeding cost per animal
	feed_tiger = current_tiger_size * (pTiger -> get_food());
	feed_penguin = current_penguin_size * (pPenguin -> get_food());
	feed_turtle = current_turtle_size * (pTurtle -> get_food());
	
	std::cout << "Feeding the tigers costs $" << feed_tiger << std::endl;
	std::cout << "Feeding the penguins costs $" << feed_penguin << std::endl;
	std::cout << "Feeding the turtles costs $" << feed_turtle << std::endl;
	std::cout << " " << std::endl;

	//subtract the feeding cost for each animal from the bank balance
	money = money - feed_tiger - feed_penguin - feed_turtle;

	std::cout << "After feeding all the animals, you're left with $" << money << std::endl;
	std::cout << " " << std::endl;
	
	//all the animals age by one day
	std::cout << "Every animal in the zoo has gotten older by one day" << std::endl;		
	std::cout << " " << std::endl;
	 
	//add one day to each tiger's age for each Tiger object in the array 
	for (int i = 0; i < current_tiger_size; ++i)
	{	
		tiger_age = (pTiger[i].get_age()) + 1;
		pTiger[i].set_age(tiger_age);
	}

	//add one day to each penguin's age for each Penguin object in the array
	for (int i = 0; i < current_penguin_size; ++i)
	{	
		penguin_age = (pPenguin[i].get_age()) + 1;
		pPenguin[i].set_age(penguin_age);
	}

	//add one day to each Turtle's age for each Turtle object in the array
	for (int i = 0; i < current_turtle_size; ++i)
	{	
		turtle_age = (pTurtle[i].get_age()) + 1;
		pTurtle[i].set_age(turtle_age);
	}

	//a random event takes place at the zoo
	std::cout << "It wouldn't be a typical day at the zoo without SOMETHING happening..." << std::endl;
	std::cout << " " << std::endl;
	
	random_event();	

}


/********************************************************************************** 
 ** Description: The end_day function of the Zoo class takes no parameters and returns
		 an int to the main program module, indicating whether the user wants
		 to continue playing the game or not. This function calculates how
		 much is left in the bank after the events of the zoo day have transpired
		 including any profits made from the payoff for each animal type at the
		 zoo and any bonusses. The user is asked if they want to purchase an
		 adult animal for the zoo, before asking them if they wish to continue
		 playing. If the user does not have enough money to continue playing,
		 a message will be displayed informing them of such and the game will
		 end
 ** *******************************************************************************/ 

int Zoo::end_day()
{
	std::string choice;
	std::string choice1;	
	int val_choice;	
	int val_choice1;
	double profit;
	double tiger_payoff;
	double penguin_payoff;
	double turtle_payoff;
	
	//calculate profit for the day based on number of animals and their payoff,
	//and add on any bonuses
	tiger_payoff = current_tiger_size * (pTiger -> get_payoff());
	penguin_payoff = current_penguin_size * (pPenguin -> get_payoff());
	turtle_payoff = current_turtle_size * (pTurtle -> get_payoff());

	profit = bonus + tiger_payoff + penguin_payoff + turtle_payoff; 
	money = money + profit;

	std::cout << " " << std::endl;	
	std::cout << "*************************" << "END OF DAY " << day << "*************************" << std::endl;
	std::cout << " " << std::endl;

	std::cout << "Today's profit for Zoo Day " << day << " is $" << profit << std::endl;
	std::cout << "This includes a bonus of $" << bonus << std::endl;
	std::cout << "The zoo's bank balance at the end of Zoo Day " << day << " is $" << money << std::endl;

	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;


	//before the end of the day, user is asked if they wish to purchase an adult animal
	std::cout << "Would you like to purchase an adult animal?" << std::endl;
	std::cout << "Press 1 for yes, or press 2 for no" << std::endl;
	std::getline(std::cin, choice);

	//validate user's choice and convert to an integer
	val_choice = int_input_val(choice);
	
	while (val_choice < 1 || val_choice > 2)
	{
		std::cout << "Oops! That isn't a valid selection. Press 1 for yes or press 2 for no" << std::endl;
		std::getline(std::cin, choice);
		val_choice = int_input_val(choice);
	}
	
	if (val_choice == 2)
	{
		std::cout << " " << std::endl;
		std::cout << "You have chosen not to purchase an adult animal" << std::endl;
	}

	if (val_choice == 1)
	{
		std::string animal;
		int val_animal;

		std::cout << " " << std::endl;
		std::cout << "What type of adult animal would you like to purchase? " << std::endl;
		std::cout << "Press 1 for an adult tiger" << std::endl;
		std::cout << "Press 2 for an adult penguin" << std::endl;
		std::cout << "Press 3 for an adult turtle" << std::endl;
		std::getline(std::cin, animal);

		val_animal = int_input_val(animal);

		while (val_animal < 1 || val_animal > 3)
		{
			std::cout << "Oops! That isn't a valid selection. Please select from option 1, 2 or 3" << std::endl;
			std::getline(std::cin, animal);
			val_animal = int_input_val(animal);
		}

		//if user buys a tiger
		if (val_animal == 1)
		{
			std::cout << " " << std::endl;
			std::cout << "You bought a tiger!" << std::endl;
			int current_level = this -> get_tiger();
			int max_level = this -> get_tiger_max();
			
			//if the maximum tiger capacity has been reached
			if (current_level == max_level)
			{			
				//double the current array and copy current tigers over to it,
				//set new tiger's age to 3 days old, subtract cost of tiger from
				//bank and increase tiger population by 1		
				resize_tiger();
				pTiger[current_level].set_age(3);
				money = money - 10000.0;
				++current_tiger_size;	
			}
			
			//if the maximum tiger capacity has not been reached
			if (current_level < max_level)
			{	
				pTiger[current_level].set_age(3);
				money = money - 10000.0;
				++current_tiger_size;
			}
		}
	
		//if user buys a penguin
		if (val_animal == 2)
		{
			std::cout << " " << std::endl;
			std::cout << "You bought a penguin!" << std::endl;
			int current_level = this -> get_penguin();
			int max_level = this -> get_penguin_max();
			
			//if the maximum penguin capacity has been reached
			if (current_level == max_level)
			{		
				//double the current array and copy current penguins over to it,
				//set new penguin's age to 3 days old, subtract cost of penguin from
				//bank and increase penguin population by 1		
				resize_penguin();
				pPenguin[current_level].set_age(3);
				money = money - 1000.0;
				++current_penguin_size;	
			}

			//if the maximum penguin capacity has not been reached
			if (current_level < max_level)
			{	
				pPenguin[current_level].set_age(3);
				money = money - 1000.0;
				++current_penguin_size;
			}
			
		}

		//if user buys a turtle
		if (val_animal == 3)
		{
			std::cout << " " << std::endl;
			std::cout << "You bought a turtle!" << std::endl;
			int current_level = this -> get_turtle();
			int max_level = this -> get_turtle_max();
			
			//if the maximum turtle capacity has been reached
			if (current_level == max_level)
			{
				//double the current array and copy current turtles over to it,
				//set new turtle's age to 3 days old, subtract cost of turtle 
				//from the bank and increase turtle population by 1		
				resize_turtle();
				pTurtle[current_level].set_age(3);
				money = money - 100.0;
				++current_turtle_size;	
			}

			//if the maximum turtle capacity has not been reached
			if (current_level < max_level)
			{	
				pTurtle[current_level].set_age(3);
				money = money - 100.0;
				++current_turtle_size;
			}
			
		}		
	}

	std::cout << " " << std::endl;
	std::cout << "*.*.*.*.*.*.*.*.*.*." << std::endl;
	std::cout << " " << std::endl;

	//at the end of the day, user is asked if they want to keep playing the game

	std::cout << "Do you want to keep playing or end the game?" << std::endl;	
	std::cout << "Your bank balance is currently $" << money << std::endl;
	std::cout << "Press 1 to continue playing, or press 2 to quit game" << std::endl;
	std::getline(std::cin, choice1);

	//validate user's choice and convert to an integer
	val_choice1 = int_input_val(choice1);
	
	while (val_choice1 < 1 || val_choice1 > 2)
	{
		std::cout << "Oops! That isn't a valid selection. Press 1 to continue playing game or press 2 to quit" << std::endl;
		std::getline(std::cin, choice1);
		val_choice1 = int_input_val(choice1);
	}
	
	if (val_choice1 == 2)
	{
		std::cout << " " << std::endl;
		std::cout << "You have chosen to quit, goodbye!" << std::endl;
		std::cout << "(All the animals in the zoo were released into the wild and lived happily every after!)" << std::endl;
		std::cout << " " << std::endl;
		return 2;
	}

	if (val_choice1 == 1)
	{
		//if the user does not have enough money to continue the game
		if (money <= 0)
		{	
			std::cout << "Sorry, you don't have enough money to keep playing. Goodbye!" << std::endl;
			std::cout << "(All the animals in the zoo were released into the wild and lived happily ever after!)" << std::endl;
		}	
		else
		{
			++day;
			std::cout << " " << std::endl;
			std::cout << "Let's move on to Zoo Day " << day << "! " << std::endl;
			return 1;
		}
	}
}

