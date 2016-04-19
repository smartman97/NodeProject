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
	root = nullptr;
	balanced = true;
	height = 0;
	size = 0;
}

template<class Type>
CTECBinaryTree<Type>::~CTECBinaryTree()
{

}

template<class Type>
bool CTECBinaryTree<Type>::insert(const Type& value)
{
	TreeNode<Type>* insertedNode(value);
	TreeNode<Type>* current;
	TreeNode<Type>* trailingCurrent;

	assert(insertedNode != nullptr);

	if(contains(value))
	{
		return false;
	}
	else
	{
		if(root == nullptr)
		{
			root = insertedNode;
		}
		else
		{
			current = root;

			while(current != nullptr)
			{
				trailingCurrent = current;

				if(current->getValue() > value)
				{
					current = current->getLeftChild();
				}
				else
				{
					current = current->getRightChild();
				}
			}
			if(trailingCurrent->getValue() > value)
			{
				trailingCurrent->setLeftChild(insertedNode);
				insertedNode->setParent(trailingCurrent);
			}
			else
			{
				trailingCurrent->setRightChild(insertedNode);
			}
			insertedNode->setParent(trailingCurrent);
		}
		return true;
	}
}

template<class Type>
void CTECBinaryTree<Type>::insert(const Type& value, CTECBinaryTree<Type>* currentTree)
{

}

template<class Type>
Type CTECBinaryTree<Type>::remove(const Type& value)
{
	if(!contains(value))
	{
		return value;
	}
	else
	{
		/*
		 * Find the node
		 * Check to see how many child nodes
		 * 	if 0
		 * 		delete
		 * 	else if only left
		 * 		replace with left
		 * 		delete old one
		 * 	(and vise versa)
		 * 	else both
		 * 	find lmc/rmc
		 * 		swap with
		 * 		do - left only/right only
		 */
	}
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

template<class Type>
bool CTECBinaryTree<Type>::contains(Type value)
{
	/*
	 * is the value in root? - return true else.
	 * If the value is not in the root and is less than root - call contains on left child.
	 * Else  the value is not in the root and is greater than root - call contains on right child
	 */

	bool isInTree = false;

	if(root->getValue == value)
	{
		isInTree = true;
	}
	else if(value < root->getValue())
	{
		isInTree = contains(value,root->getLeftChild());
	}
	else
	{
		isInTree = contains(value, root->getRightChild());
	}
	return isInTree;
}

template<class Type>
bool CTECBinaryTree<Type>::contains(Type value, CTECBinaryTree<Type>* currentTree)
{
	/*
	 * is the value in root? - return true else.
	 * If the value is not in the root and is less than root - call contains on left child.
	 * Else  the value is not in the root and is greater than root - call contains on right child
	 */

	if(currentTree == nullptr)
	{
		return false;
	}

	if(root->getValue == value)
	{
		return true;
	}
	else if(value < currentTree->getRoot()->getValue())
	{
		return contains(value,root->getLeftChild());
	}
	else
	{
		return contains(value, root->getRightChild());
	}
}

