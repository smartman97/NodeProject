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

	this->setValue(value);
	this->setParent(parent);
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::getLeftChild()
{
	return this->leftChild;
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::getRightChild()
{
	return this->rightChild;
}

template<class Type>
TreeNode<Type>* TreeNode<Type>::getParent()
{
	return this->parent;
}

template<class Type>
void TreeNode<Type>::setLeftChild(TreeNode<Type>* leftChild)
{
	this->leftChild = leftChild;
}

template<class Type>
void TreeNode<Type>::setRightChild(TreeNode<Type>* rightChild)
{
	this->rightChild = rightChild;
}

template<class Type>
void TreeNode<Type>::setParent(TreeNode<Type>* parent)
{
	this->parent = parent;
}

template<class Type>
TreeNode<Type>::~TreeNode()
{

}

