/*
 * CTECBinaryTree.h
 *
 *  Created on: Apr 11, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECBINARYTREE_H_
#define MODEL_CTECBINARYTREE_H_

#include "TreeNode.cpp"

#include <iostream>

using namespace std;

template<class Type>
class CTECBinaryTree
{
private:
	TreeNode<Type>* root;
	int height;
	int size;
	bool balanced;
	bool contains(Type value, CTECBinaryTree<Type>* parent);
	void insert(const Type& value, CTECBinaryTree<Type>* currentTree);
	int calculatedSize(TreeNode<Type>* currentNode);
	TreeNode<Type>* getRightMostChild(CTECBinaryTree* leftSubTree);
	TreeNode<Type>* getLeftMostChild(CTECBinaryTree* rightSubTree);
	void remove(TreeNode<Type>* nodeToRemove);
public:
	CTECBinaryTree();
	virtual ~CTECBinaryTree();
	bool insert(const Type& value);
	bool contains(Type value);
	void remove(const Type& value);
	int getHeight();
	bool isBalanced();
	TreeNode<Type>* getRoot();
	void inorderTraversal(TreeNode<Type>* currentNode);
	void postorderTraversal(TreeNode<Type>* currentNode);
	void preorderTraversal(TreeNode<Type>* currentNode);
	int getSize();

};

#endif /* MODEL_CTECBINARYTREE_H_ */
