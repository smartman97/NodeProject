/*
 * CTECHashTable.h
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECHASHTABLE_H_
#define MODEL_CTECHASHTABLE_H_


#include "CTECList.h"
#include "HashNode.cpp"


template<class Type>
class CTECHashTable
{
private:
	int capacity;
	int tableCapacity;
	double efficiencyPercentage;
	int size;
	int tableSize;
	HashNode<Type>** internalStorage;
	CTECList<HashNode<Type> > * tableStorage;

	void updateTableCapacity();
	void updateSize();

	int findPosition(HashNode<Type> currentNode);
	int findTablePosition(HashNode<Type> currentNode);

	int handleCollision(HashNode<Type> currentNode);

	int getNextPrime();
	bool isPrime(int candidateNumber);
public:
	CTECHashTable();
	virtual ~CTECHashTable();

	void addToTable(HashNode<Type> currentNode);
	void add(HashNode<Type> currentNode);

	bool remove(HashNode<Type> currentNode);
	bool contains(HashNode<Type> currentNode);
	int getSize();
};

#endif /* MODEL_CTECHASHTABLE_H_ */
