/*
 * CTECList.h
 *
 *  Created on: Feb 18, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_

#include "ArrayNode.h"

template <class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
public:
	CTECList();
	virtual ~CTECList();
	int getSize();
	Type getFront();
	Type getEnd();
	Type getAtIndex(int index);
	void set(int index, const Type& value);
	void addFront(const Type& value);
	void addEnd(const Type& value);
	void addAtIndex(int index, const Type& value);
	Type removeFront();
	Type removeEnd();
	Type removeAtIndex(int index);

};

#endif /* MODEL_CTECLIST_H_ */
