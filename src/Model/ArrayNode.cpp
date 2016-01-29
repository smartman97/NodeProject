/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: clar5254
 */

#include <iostream>
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

}

template<class Type>
ArrayNode<Type> :: ~ArrayNode()
{

}

