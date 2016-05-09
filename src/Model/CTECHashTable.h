/*
 * CTECHashTable.h
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECHASHTABLE_H_
#define MODEL_CTECHASHTABLE_H_

#include "CTECArray.cpp"
#include "HashNode.cpp"

template<class Type>
class CTECHashTable
{
private:
	int capacity;
	double efficiencyPercentage;
	int size;
	HashNode<Type>* internalStorage;

	void updateSize();
	int findPosition(HashNode<Type> currentNode);
	int handleCollision(HashNode<Type> currentNode);

	int getNextPrime();
	bool isPrime(int candidateNumber);
public:
	CTECHashTable();
	virtual ~CTECHashTable();

	void add(HashNode<Type> currentNode);
	bool remove(HashNode<Type> currentNode);
	bool contains(HashNode<Type> currentNode);
	int getSize();
};

#endif /* MODEL_CTECHASHTABLE_H_ */
