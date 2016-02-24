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
	newHead = head->getNext();
	delete this->head;
	this->head = newHead;
	return thing;
}

template<class Type>
Type CTECList<Type>::removeEnd()
{
	//Can loop over size, or loop until ->getNext() = nullptr
	//using end pointer?
	ArrayNode<Type>* newEnd = new ArrayNode<Type>();
	Type thing;

}

template<class Type>
Type CTECList<Type>::removeAtIndex(int index)
{
	ArrayNode<Type>* previous;
	ArrayNode<Type>* toDelete;
	ArrayNode<Type>* newNext;
	ArrayNode<Type>* current = head;
	Type thing;

	assert(index < 0 || index > size);

	if(index == 0)
	{
		removeFront();
	}

	for(int i = 0; i < index + 1; i++)
	{
		if(i == index - 1)
		{
			previous = current;
		}

		if(i == index)
		{
			toDelete = current;
			thing = toDelete->getValue();
			newNext = current->getNext();
			delete toDelete;
			previous->setNext(newNext);
		}
		current = current->next();
	}

	return thing;
	//Check not negative, not greater than size. Using assert
	//node pointers for previous and for ToDelete and new next
	//Find previous next to index, use a for loop(index - 1), loop should have 3 if's
	//Assign previous next,
	//return what was in ToDelete (Type thing = ToDelete      return thing
	//Delete ToDelete
	//set previous to next
}
