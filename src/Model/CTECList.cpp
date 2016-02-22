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
	newHead = head->getNext();
	delete this->head;
	this->head = newHead;
}

template<class Type>
Type CTECList<Type>::removeEnd()
{

}

template<class Type>
Type CTECList<Type>::removeAtIndex(int index)
{

}
