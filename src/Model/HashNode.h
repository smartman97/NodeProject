/*
 * HashNode.h
 *
 *  Created on: May 9, 2016
 *      Author: clar5254
 */

#ifndef MODEL_HASHNODE_H_
#define MODEL_HASHNODE_H_

template<class Type>
class HashNode
{
private:
	int key;
	Type value;
public:
	HashNode();
	HashNode(int key, Type value);
	virtual ~HashNode();

	void setKey(int key);
	void setValue(const Type& value);
	int getKey();
	Type getValue();
};

#endif /* MODEL_HASHNODE_H_ */
