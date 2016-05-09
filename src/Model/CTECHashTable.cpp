/*
 * CTECHashTable.cpp
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#include "CTECHashTable.h"
#include <cmath>

template<class Type>
CTECHashTable<Type> :: CTECHashTable()
{
	this->capacity = 101;
	this-efficiencyPercentage = .667;
	this->size = 0;
	this->internalStorage= new HashNode<Type>[capacity];
}

template<class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
	delete [] internalStorage;
}

template<class Type>
int CTECHashTable<Type> :: getSize()
{
	return this->size;
}

template<class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
	if(!contains(currentNode))
	{
		//Update size if needed. Find where to put the value.
		if(this->size/this->capacity >= this->efficiencyPercentage)
		{
			updateSize();
		}

		int positionToInsert = findPosition(currentNode);

		if(internalStorage[positionToInsert] != nullptr)
		{
			//Loop over the internalStorage to find the next empty slot. Insert the value there.
			while(internalStorage[positionToInsert] != nullptr)
			{
				positionToInsert = (positionToInsert + 1) % capacity;
			}
			internalStorage[positionToInsert] = currentNode;
		}
		else
		{
			internalStorage[positionToInsert] = currentNode;
		}
	}
}

template<class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
	//We are going to "hash" the key of the hashnode to find its storage spot.
	int position = 0;

	position = currentNode.getKey() % capacity;

	return position;
}

template<class Type>
int CTECHashTable<Type> :: getNextPrime()
{
	int nextPrime = (capacity * 2) + 1;

	while(!isPrime(nextPrime))
	{
		nextPrime++;
	}

	return nextPrime;
}

template<class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
	bool isPrime = true;

	if(candidateNumber <= 1)
	{
		return false;
	}
	else if(candidateNumber == 2 || candidateNumber == 3)
	{
		isPrime = true;
	}
	else if(candidateNumber % 2 == 0)
	{
		isPrime = false;
	}
	else
	{
		for(int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
		{
			if(candidateNumber  % next == 0)
			{
				isPrime = false;
				break;
			}
		}
	}

	return isPrime;
}

template<class Type>
void CTECHashTable<Type> :: updateSize()
{
	int updatedCapacity = getNextPrime();
	HashNode<Type> updatedStorage = new HashNode<Type> [updatedCapacity];

	int oldCapacity = capacity;
	capacity = updatedCapacity;

	for(int index = 0; index < capacity; index++)
	{
		if(internalStorage[index] != nullptr)
		{
			 int updatedPosition = findPosition(internalStorage[index]);
			 updatedStorage[updatedPosition] = internalStorage[index];
		}
	}
	internalStorage = updatedStorage;
}
