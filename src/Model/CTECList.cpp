/*
 * CTECList.cpp
 *
 *  Created on: Feb 18, 2016
 *      Author: clar5254
 */

#include "CTECList.h"

template<class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;
}

template<class Type>
CTECList<Type>::~CTECList()
{

}

template<class Type>
int CTECList<Type>::getSize()
{
	return this->size;
}

template<class Type>
Type CTECList<Type>::getFront()
{
	return nullptr;
}

template<class Type>
Type CTECList<Type>::getEnd()
{
	return nullptr;
}

template<class Type>
Type CTECList<Type>::getAtIndex(int index)
{
	return nullptr;
}

template<class Type>
void CTECList<Type>::set(int index, const Type& value)
{

}

template<class Type>
void CTECList<Type>::addFront(const Type& value)
{

}

template<class Type>
void CTECList<Type>::addEnd(const Type& value)
{

}

template<class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{

}

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

template<class Type>
Type CTECList<Type>::removeEnd()
{
	//make node and point to head
	//Can loop over size(for), or loop until ->getNext() = nullptr(while)
	//Make temp and temp ptr, assign value, set current
	//Delete node
	//return


	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* current = head;
	Type thing;

	if(current->getNext() == nullptr)
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
		previous->next() = nullptr;
		end = previous;
	}

	this->calculateSize();
	return thing;
}

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
		this->size() = 0;
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
