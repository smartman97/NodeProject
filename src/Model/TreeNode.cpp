/*
 * TreeNode.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: clar5254
 */

#include "TreeNode.h"

template<class Type>
TreeNode<Type>::TreeNode() : Node<Type>()
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;
}

template<class Type>
TreeNode<Type>::TreeNode(const Type& value) : Node<Type>(value)
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;

	this->setValue(value);
}

template<class Type>
TreeNode<Type>::TreeNode(const Type& value, TreeNode<Type>* parent) : Node<Type>(value)
{
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->parent = nullptr;

	this->setValue(value);
	this->setParent(parent);
}

template<class Type>
TreeNode<Type>::~TreeNode()
{

}

