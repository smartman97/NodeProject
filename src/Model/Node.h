/*
 * Node.h
 *
 *  Created on: Jan 27, 2016
 *      Author: clar5254
 */

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <iostream>

template <class Type>
class Node
{
private:
	Type value;
	Node * pointers;
public:
	Node();
	Node(Type value);
	virtual ~Node();
	Type getValue();
	void setValue(Type value);
	Node * getPointers();
};

#endif /* MODEL_NODE_H_ */
