/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: Colm Laro
 */

#include "CTECArray.h"
#include <assert.h>
using namespace std;

template<class Type>
CTECArray<Type>::CTECArray(int size)
{
	this->size = size;
	this->head = nullptr;

	assert(size > 0);

	for (int index = 0; index < size; index++)
	{
		if (head != nullptr)
		{
			//We have more than one ArrayNode.
			ArrayNode<Type> * nextNode = new ArrayNode<Type>();
			nextNode->setNext(head);
			head = nextNode;
		}
		else
		{
			//This is the first node in the array.
			ArrayNode<Type> * first = new ArrayNode<Type>();
			head = first;
		}
	}
}

template<class Type>
CTECArray<Type>::~CTECArray()
{
	ArrayNode<Type> * deleteMe = head;
	for (int index = 0; index < size; index++)
	{
		if (deleteMe->getNext() != nullptr)
		{
			head = deleteMe->getNext();
			deleteMe->setNext(nullptr);
		}
		delete deleteMe->getNext();
		delete deleteMe->getNext();
		deleteMe = head;deleteMe = head;
	}
	delete head;
}

template<class Type>
int CTECArray<Type>::getSize()
{
	return this->size;
}

template<class Type>
Type CTECArray<Type>::get(int position)
{
	//Bounds check for size and negative
	assert(position <= size && position >= 0);

	//Inclusive because I am inside the bounds guaranteed!
	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= position; spot++)
	{
		if (spot != position)
		{
			current = current->getNext();
		}
		else
		{
			return current->getValue();
		}
	}
	return 0;
}

template<class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
	//Bound check for size and negative
	assert(position <= size && position >= 0);

	ArrayNode<Type> * current = head;
	for (int spot = 0; spot <= position; spot++)
	{
		if (spot != position)
		{
			current = current->getNext();
		}
		else
		{
			return current->setValue(value);
		}
	}
}

	/*
	 * searching
	 * assert size > 0
	 * declare return variable assign -1 to it
	 * loop  if match return index, else next
	 * return index
	 */
template<class Type>
int CTECArray<Type>::indexOf(Type searchValue)
{
	assert(this->size > 0);

	int indexNotFound = -1;

	ArrayNode<Type>* current = head;

	for(int index = 0; index < this->size; index++)
	{
		if(current->getValue() == searchValue)
		{
			return index;
		}
		else
		{
			current = current->getNext();
		}
	}
	return indexNotFound;
}

template<class Type>
int CTECArray<Type>::nextIndexOf(int startingIndex, Type searchValue)
{
	assert(this->size > 0);
	assert(startingIndex >= 0 && startingIndex < this->size);

	int indexNotFound = -1;

	ArrayNode<Type>* current = head;
	for(int index = 0; index < startingIndex; index++)
	{
		current = current->getNext();
	}

	for(int index = startingIndex; index < this->size; index++)
	{
		if(current->getValue == searchValue)
		{
			return index;
		}
		else
		{
			current = current->getNext();
		}
	}
	return indexNotFound;
}

template<class Type>
void CTECArray<Type>::swap(int indexOne, int indexTwo)
{
	assert(indexOne< size && indexTwo < size);
	Type temp = get(indexOne);
	set(indexOne, get(indexTwo));
	set(indexTwo, temp);
}

template<class Type>
void CTECArray<Type>::selectionSort()
{
	int innerLoop, outerLoop;

	for(outerLoop = 0; outerLoop < this->size - 1; outerLoop++)
	{
		int selectedMin = outerLoop;

		for(innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
		{
			if(get(innerLoop) < get(selectedMin))
			{
				selectedMin = innerLoop;
			}
		}
		if(selectedMin != outerLoop)
		{
			swap(outerLoop, selectedMin);
		}
	}
}


