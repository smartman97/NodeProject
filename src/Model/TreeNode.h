/*
 * TreeNode.h
 *
 *  Created on: Apr 11, 2016
 *      Author: clar5254
 */

#ifndef MODEL_TREENODE_H_
#define MODEL_TREENODE_H_

#include "Node.h"

template<class Type>
class TreeNode : Node<Type>
{
public:
	TreeNode();
	TreeNode(const Type& value);
	TreeNode(const Type& value, TreeNode<Type>* parent);
	void setLeftChild(TreeNode<Type> leftChild);
	void setRightChild(TreeNode<Type> rightChild);
	void setParent(TreeNode<Type> parent);
	TreeNode<Type>* getLeftChild();
	TreeNode<Type>* getRightChild();
	TreeNode<Type>* getParent();
	virtual ~TreeNode();

private:
	TreeNode<Type>* leftChild;
	TreeNode<Type>* rightChild;
	TreeNode<Type>* parent;
};

#endif /* MODEL_TREENODE_H_ */
