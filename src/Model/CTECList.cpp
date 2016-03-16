/*
 * CTECList.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: clar5254
 */

#include "CTECList.h"

//Constructor
template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

//Destructor
template<class Type>
CTECList<Type>::~CTECList()
{
	/*
	 * Start at head
	 * iterate over nodes
	 * update position then delete
	 * delete final
	 * reset size, head, end to default
	 */
	ArrayNode<Type>* current = head;

	while (current->getNext() != nullptr)
	{
		ArrayNode<Type>* temp = current;

		current = current->getNext();
		head= current;
		delete temp;
	}

	delete head;
	head = nullptr;
	end = nullptr;
	size = 0;
}

//Returns the size of the list
template<class Type>
int CTECList<Type>::getSize()
{
	this->calculateSize();
	return this->size;
}

//Returns front of the list
template<class Type>
Type CTECList<Type>::getFront()
{
	return head->getValue();
}

//Returns the end of the list
template<class Type>
Type CTECList<Type>::getEnd()
{
	return end->getValue();
}

//Returns at the given index
template<class Type>
Type CTECList<Type>::getAtIndex(int index)
{
	assert(index < size && index >= 0);
	ArrayNode<Type>* current = head;

	for (int i = 0; i <= index; i++)
	{
		if(i != index)
		{
			current = current->getNext();
		}
		else
		{
			return current->getValue();
		}
	}
	return current->getValue();
}

//Sets a value at a given index
template<class Type>
void CTECList<Type>::set(int index, const Type& value)
{
	//Bound check for size and negative
	assert(index < size && index >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= index; spot++)
	{
		if (spot != index)
		{
			current = current->getNext();
		}
		else
		{
			return current->setValue(value);
		}
	}
}

//Adds to the front of the list
template<class Type>
void CTECList<Type>::addFront(const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);

	if (head == nullptr)
	{
		newNode->setNext(nullptr);
		head = newNode;
		end = newNode;
	}
	else
	{
		newNode->setNext(head);
		head = newNode;
	}
	calculateSize();
}

//Adds to the end of the list
template<class Type>
void CTECList<Type>::addEnd(const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	ArrayNode<Type>* current = head;

	if (current->getNext() == nullptr)
	{
		current->setNext(newNode);
		newNode->setNext(nullptr);
		end = newNode;
	}
	else
	{
		while(current->getNext() != nullptr)
		{
			current = current->getNext();
		}
		current->setNext(newNode);
		newNode->setNext(nullptr);
		end = newNode;
	}
	calculateSize();
}

//Adds at a given index
template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
	ArrayNode<Type>* newNode = new ArrayNode<Type>(value);
	ArrayNode<Type>* current = head;
	ArrayNode<Type>* previous = current;

	assert(index <= size && index >= 0);

	if (index == 0)
	{
		addFront(value);
	}
	else if(index == size)
	{
		addEnd(value);
	}
	else
	{
		for(int i = 0; i < index; i++)
		{
			previous = current;
			current = current->getNext();
		}
		previous->setNext(newNode);
		newNode->setNext(current);
	}

	calculateSize();
}

//Removes the front of the list
template<class Type>
Type CTECList<Type>::removeFront()
{
	//Create a pointer to what is after head, Delete what head is pointing to, Set head to the new head.
	ArrayNode<Type>* newHead = new ArrayNode<Type>();
	Type thing;
	newHead = this->head->getNext();
	thing = this->head->getValue();
	delete this->head;
	this->head = newHead;

	size--;

	this->calculateSize();
	return thing;
}

//Removes the end of the list
template<class Type>
Type CTECList<Type>::removeEnd()
{
	//make node and point to head
	//Can loop over size(for), or loop until ->getNext() = nullptr(while)
	//Make temp and temp ptr, assign value, set current
	//Delete node
	//return

	assert(size > 0);

	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* current = head;
	Type thing;

	if (current->getNext() == nullptr)
	{
		toDelete = current;
		thing = toDelete->getValue();
		delete toDelete;
		end = nullptr;
	}
	else
	{
		while(current->getNext() != nullptr)
		{
			previous = current;
			current = current->getNext();
		}
		toDelete = current;
		thing = toDelete->getValue();
		delete toDelete;
		previous->setNext() = nullptr;
		end = previous;
	}

	this->calculateSize();
	return thing;
}

//Removes at given index
template<class Type>
Type CTECList<Type>::removeAtIndex(int index)
{
	//Check not negative, not greater than size. Using assert
	//node pointers for previous and for ToDelete and new next
	//Find previous next to index, use a for loop(index - 1), loop should have 3 if's
	//Assign previous next,
	//return what was in ToDelete (Type thing = ToDelete      return thing
	//Delete ToDelete
	//set previous to next
	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* newNext;
	ArrayNode<Type>* current = head;
	Type thing;

	assert(this->size > 0);
	assert(index > 0 || index <= size);

	if (index == 0)
	{
		thing = removeFront();
	}
	else if (index == size - 1)
	{
		thing = removeEnd();
	}
	else
	{

		for (int i = 0; i < index; i++)
		{
			if (i == index - 1)
			{
				previous = current;
			}
			else if (i == index)
			{
				toDelete = current;
				thing = toDelete->getValue();
				newNext = current->getNext();
				delete toDelete;
				previous->setNext(newNext);
			}
			current = current->next();
		}
	}

	this->calculateSize();
	return thing;
}

/**
 * Calculates the size of the list by iterating over all of the nodes in the list.
 */
template<class Type>
void CTECList<Type>::calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type>* counterPointer = head;
	int count = 0;

	if (counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;
		}

		this->size = count;
	}
}
