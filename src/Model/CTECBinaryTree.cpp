/*
 * CTECBinaryTree.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: clar5254
 */

#include "CTECBinaryTree.h"

template<class Type>
CTECBinaryTree<Type>::CTECBinaryTree()
{

}

template<class Type>
CTECBinaryTree<Type>::~CTECBinaryTree()
{

}

template<class Type>
void CTECBinaryTree<Type>::inorderTraversal(TreeNode<Type>* currentNode)
{
	if(currentNode != nullptr)
	{
		inorderTraversal(currentNode->getLeftChild());
		cout << currentNode->getValue() << "";
		inorderTraversal(currentNode->getRightChild());
	}
}

template<class Type>
void CTECBinaryTree<Type>::preorderTraversal(TreeNode<Type>* currentNode)
{
	if(currentNode != nullptr)
	{
		cout << currentNode->getValue() << "";
		inorderTraversal(currentNode->getLeftChild());
		inorderTraversal(currentNode->getRightChild());
	}
}

template<class Type>
void CTECBinaryTree<Type>::postorderTraversal(TreeNode<Type>* currentNode)
{
	if(currentNode != nullptr)
	{
		inorderTraversal(currentNode->getLeftChild());
		inorderTraversal(currentNode->getRightChild());
		cout << currentNode->getValue() << "";
	}
}

template<class Type>
int CTECBinaryTree<Type>::getSize()
{
	calculatedSize(root);
	return size;
}

template<class Type>
int CTECBinaryTree<Type>::calculatedSize(TreeNode<Type>* currentNode)
{
	if(currentNode != nullptr)
	{
		postorderTraversal(currentNode->getLeftChild());
		postorderTraversal(currentNode->getrightChild());
		size++;
	}
}



