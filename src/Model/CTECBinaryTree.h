/*
 * CTECBinaryTree.h
 *
 *  Created on: Apr 11, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECBINARYTREE_H_
#define MODEL_CTECBINARYTREE_H_

#include "TreeNode.cpp"

template<class Type>
class CTECBinaryTree
{
public:
	CTECBinaryTree();
	virtual ~CTECBinaryTree();
	bool insert(const Type* value);
	bool contains(Type value);
	Type remove(const Type& value);
	int getHeight();
	bool isBalanced();
	TreeNode<Type>* getRoot();
private:
	TreeNode<Type>* root;
	int height;
	bool balanced;
};

#endif /* MODEL_CTECBINARYTREE_H_ */
