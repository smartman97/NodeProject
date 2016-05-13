/*
 * HashNode.cpp
 *
 *  Created on: May 9, 2016
 *      Author: clar5254
 */

#include "HashNode.h"


template<class Type>
HashNode<Type> :: HashNode()
{

}

template<class Type>
HashNode<Type> :: HashNode(int key, Type value)
{
	this->key = key;
	this->value = value;
}

template<class Type>
HashNode<Type> :: ~HashNode()
{

}

template<class Type>
void HashNode<Type> :: setKey(int key)
{
	this->key = key;
}

template<class Type>
void HashNode<Type> :: setValue(const Type& value)
{
	this->value = value;
}

template<class Type>
int HashNode<Type> :: getKey()
{
	return this->key;
}

template<class Type>
Type HashNode<Type> :: getValue()
{
	return this->value;
}
