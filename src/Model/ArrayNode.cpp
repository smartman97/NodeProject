/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: clar5254
 */

#include "ArrayNode.h"

template<class Type>
ArrayNode<Type> :: ArrayNode() : Node<Type>()
{
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type> :: ArrayNode(Type value) : Node<Type>(value)
{
	this->value = value;
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type> :: ArrayNode(Type value, ArrayNode * next) : Node<Type>(value)
{
	this->value = value;
	this->next = next;
}

template<class Type>
ArrayNode<Type> :: ~ArrayNode()
{

}

template<class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
	this->next = next;
}

template<class Type>
ArrayNode<Type> * ArrayNode<Type> :: getNext()
{
	return this->next;
}

