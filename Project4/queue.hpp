/******************************************************************************* 
 ** Program Name: Class declaration for struct CharNode and class Queue
 ** Author:       Susan Hibbert
 ** Date:         15 May 2019
 ** Description:  This program contains the function prototypes for the class Queue
		  and struct CharNode
 ** *******************************************************************************/ 
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "character.hpp"
#include <string>

struct CharNode
{
	Character *character;
	CharNode *next;
	CharNode();
	CharNode(Character *character1);
};

class Queue
{
	private:
		CharNode *head;
		CharNode *tail;
		std::string name;
 
	public:
		Queue();
		~Queue();
		void addTail(Character *character2);
		void removeHead();
		Character* getHead();
		std::string getHeadName();
		void moveHead();
		void printQueue();
		void setName(std::string input_name);
		std::string getName();
		void clear();
		
};

#endif
