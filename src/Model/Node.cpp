/*
 * Node.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: clar5254
 */

#include "Node.h"

template <class Type>
Node<Type> :: Node()
{
	value = 0;
	pointers = nullptr;
}

template <class Type>
Node<Type> :: ~Node()
{

}

template <class Type>
Type Node<Type> :: getValue()
{
	return this->value;
}

template <class Type>
Node<Type> * Node<Type> :: getPointers()
{
	return this->pointers;
}
