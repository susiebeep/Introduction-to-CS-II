/********************************************************************************** 
 ** Program Name: Source code for the member functions of the class Queue and 
		  constructors for the struct CharNode
 ** Author:       Susan Hibbert
 ** Date:         15 May 2019
 ** Description:  This program contains the member function definitions for the
		  class Queue and constructors for the struct CharNode
 ** Citations: 	  Chapter 18 Stacks and Queues, Starting Out With C++ Early Objects,
		  9th Edition, Gaddis
		  Chapter 7.12 Strucures, Starting Out With C++ Early Objects,
		  9th Edition, Gaddis
		  C++ Circular Link List - remove all nodes, StackOverflow.com
 ** *******************************************************************************/ 
#include "queue.hpp"
#include <iostream>
#include <cstdlib>


/********************************************************************************** 
 ** Description: The default constructor for the CharNode struct. It initializes its
		 CharNode pointer data member next and Character pointer data member
		 character to null
 ** *******************************************************************************/ 

CharNode::CharNode() 
{
	next = NULL;
	character = NULL;
}


/********************************************************************************** 
 ** Description: A constructor for the CharNode struct which is called when a 
		 CharNode is added to a Queue object. It takes a Character pointer 
		 as a parameter representing the user's choice of Character and uses
		 it to set its Character pointer data member character in a new
		 CharNode struct
 ** *******************************************************************************/ 

CharNode::CharNode(Character *character1) 
{
	next = NULL;
	character = character1;
}

/********************************************************************************** 
 ** Description: The default constructor for the Queue class initializes its 
		 CharNode pointer data members head and tail to null and its string
		 data member name to an empty string in a newly created Queue object 
 ** *******************************************************************************/ 

Queue::Queue()
{
	head = NULL;
	tail = NULL;
	name = " ";
}


/********************************************************************************** 
 ** Description: The destructor for the Queue class deletes the dynamic memory used
		 by the CharNodes in the Queue object. It starts at the front node 
		 of the Queue and steps through each node, deleting the memory used
		 by each CharNode one by one, until all nodes have been deleted
 ** *******************************************************************************/ 

Queue::~Queue()
{
	//start at the front of the queue
	CharNode *ptr = head;	
		
	//while haven't reached the end of the queue
	while (ptr != NULL)	
	{	
		//garbage pointer keeps track of node to be deleted
		CharNode *garbage = ptr;
	
		//set ptr to the next node in the queue
		ptr = ptr -> next;
		
		//delete the node garbage is pointing at and the Character
		//object in the CharNode
		delete garbage -> character;
		delete garbage;
	}
}


/********************************************************************************** 
 ** Description: addTail function of the Queue class is called when a CharNode is
		 added to the tail of the Queue object representing the team lineup
		 of the Fantasty Combat Tournament. It has no return type and takes
		 a Character pointer as a parameter, representing the user's choice
		 of Character to be added to the team lineup.
 ** *******************************************************************************/ 

void Queue::addTail(Character *character2)
{
	//if the queue is empty
	if (head == NULL)
	{
		//add a new CharNode to the queue - this calls the CharNode
		//constructor which takes one parameter and sets its next
		//pointer to null
		tail = new CharNode(character2);
		
		//set the head to point to the only CharNode in the list
		head = tail;
	}

	else
	{
		//get the last CharNode the tail is pointing to
		CharNode *old_tail = tail;
			
		//add a new CharNode to the tail
		tail = new CharNode(character2); 	

		//set the original last node's next pointer to point to the
		//new last node
		old_tail -> next = tail;
	}
}	


/********************************************************************************** 
 ** Description: removeHead function of the Queue class removes a CharNode from the
		 head of the Queue object. It has no return type and takes no
		 parameters. It is called when a Character loses a fight and needs
		 to be removed from its team lineup and placed in the loser Stack object
 ** *******************************************************************************/ 

void Queue::removeHead()
{
	//if the queue is empty
	if (head == NULL)
	{
		std::cout << "The player lineup is empty!" << std::endl;
	}
	
	else
	{
		//if there is only one CharNode in the queue
		if (head == tail)
		{
			head -> next = NULL;
			delete head;
			head = NULL;
			tail = NULL;
		}
		
		else
		{
			//if removing the head will leave 1 CharNode in the queue
			if (head -> next == tail)
			{
				head -> next = NULL;
				delete head;
				head = tail;
			}

			else
			{
				CharNode *new_head = head -> next;
			
				head -> next = NULL;
				delete head;
				head = new_head;
			}
		}
	}
}


/********************************************************************************** 
 ** Description: getHead function of the Queue class takes no parameters and returns
		 the Character pointer character of the CharNode struct at the head
		 of the Queue object representing the Character at the head of the
		 lineup
 ** *******************************************************************************/ 

Character* Queue::getHead()
{
	//if the queue is empty
	if (head == NULL)
	{
		return NULL;
	}

	else
	{
		return head -> character;
	}
}


/********************************************************************************** 
 ** Description: getHeadName function of the Queue class takes no parameters and 
		 returns the string data member name of the Character object 
		 representing the name of the Character at the head of the queue
 ** *******************************************************************************/ 

std::string Queue::getHeadName()
{
	//if the queue is empty
	if (head == NULL)
	{
		return "";
	}

	else
	{
		return head -> character -> get_name();
	}
}


/********************************************************************************** 
 ** Description: moveHead function of the Queue class has no return type and takes
		 no parameters. It moves the head CharNode of the Queue object to 
		 the tail of the Queue object, and makes the second CharNode in the
		 Queue object the new head. If the queue is empty it displays a 
		 warning message to the user. It is called when the Character at the
		 head of the lineup wins their fight and needs to be moved to the 
		 back of the lineup
 ** *******************************************************************************/ 

void Queue::moveHead()
{
	//if queue is empty
	if (head == NULL)
	{
		std::cout << "The player lineup is empty!" << std::endl;
	}
	
	if (head == tail)
	{
		tail = head;
		head = tail;
	}	
	else
	{
		CharNode *old_head = head;
		CharNode *new_head = head -> next;
		CharNode *old_tail = tail;

		//put the CharNode currently at the head of the queue to the
		//back of the queue and direct the tail to point to it. Set its
		//next pointer to NULL as it is now the end of the queue
		tail = old_head;	
		old_head -> next = NULL;
		
		//set the next pointer of the second last node to point to the new
		//last node
		old_tail -> next = old_head;

		//set the head to point to the previously second node in the queue
		//making it the first node in the queue
		head = new_head;		
	}
}

/********************************************************************************** 
 ** Description: printQueue function of the Queue class has no return type and takes
		 no parameters. It traverses through the Queue from the head using 
		 next pointers and prints the string data member name of each Character
		 object representing the name of the Character in the team line up.
		 It prints the Character line up in the order the Characters were
		 entered by the user. If the Queue is empty it displays a warning
		 message to the user
 ** *******************************************************************************/ 

void Queue::printQueue()
{
	//start at the beginning of the queue
	CharNode *ptr = head;

	//if queue is empty
	if (head == NULL)
	{
		std::cout << "The player lineup is empty!" << std::endl;
	}
		
	else
	{
		while (ptr != NULL)
		{
			std::cout << ptr -> character -> get_name() << std::endl;
			ptr = ptr -> next;
		}
	}
}


/********************************************************************************** 
 ** Description: setName function of the Queue class has no return type and takes
		 one string parameter which it uses to set the string data member 
		 name representing the name of the Queue object (i.e. team name)
 ** *******************************************************************************/ 

void Queue::setName(std::string input_name)
{
	this -> name = input_name;
}


/********************************************************************************** 
 ** Description: getName function of the Queue class takes no parameters and returns
		 the string data member name representing the name of the Queue
		 object (i.e. team name)
 ** *******************************************************************************/ 

std::string Queue::getName()
{
	return this -> name;
}


/********************************************************************************** 
 ** Description: clear function of the Queue class takes no parameters and has no
		 return type. It clears the Queue object which represents a team line
		 up between games
 ** *******************************************************************************/ 

void Queue::clear()
{
	//start at the front of the queue
	CharNode *ptr = head;	
		
	//while haven't reached the end of the queue
	while (ptr != NULL)	
	{	
		//garbage pointer keeps track of node to be deleted
		CharNode *garbage = ptr;
	
		//set ptr to the next node in the queue
		ptr = ptr -> next;
		
		//delete the node garbage is pointing at and the Character
		//object in the CharNode
		delete garbage -> character;
		delete garbage;	
	}
	
	//head and tail pointers are set to null
	head = NULL;
	tail = NULL;
}
