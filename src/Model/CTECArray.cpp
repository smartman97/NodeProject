/*
 * CTECArray.cpp
 *
 *  Created on: Feb 2, 2016
 *      Author: Colm Laro
 */

#include "CTECArray.h"
using namespace std;

template <class Type>
CTECArray<Type> :: CTECArray(int size)
{
	this->size = size;
	head = nullptr;

	if(size <= 0)
	{
		cerr << "Impossible!" << endl;
		return;
	}
}

template <class Type>
CTECArray<Type> :: ~CTECArray()
{

}

template <class Type>
int CTECArray<Type> :: getSize()
{
	return this->size;
}

template <class Type>
Type* CTECArray<Type> :: get(int position)
{
	//Bounds check for size and negative
	if(position > size || position < 0)
	{
		return nullptr;
	}
	else
	{
		//Inclusive because I am inside the bounds guaranteed!
		for(int spot = 0; spot <= position; spot++)
		{
			ArrayNode<Type> * current = head;
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->getValue();
			}
		}
	}
}

template <class Type>
void CTECArray<Type> :: set(int position, Type value)
{
	//Bound check for size and negative
	if(position >= size || position < 0)
	{
		cerr << "Don't do this!! Out of bounds!!" << endl;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot <= position; spot++)
		{
			if(spot != position)
			{
				current = current->getNext();
			}
			else
			{
				return current->setValue(value);
			}
		}
	}
}
