/*
 * CTECHashTable.cpp
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#include "CTECHashTable.h"

#include <strings.h>
#include <cmath>
#include <cstddef>

#include "HashNode.h"

template<class Type>
CTECHashTable<Type>::CTECHashTable()
{
	this->capacity = 101;
	this->efficiencyPercentage = .667;
	this->size = 0;
	this->internalStorage = new HashNode<Type>*[capacity];
	this->tableStorage = new CTECList<HashNode<Type> >[capacity];
}

template<class Type>
CTECHashTable<Type>::~CTECHashTable()
{
	delete[] internalStorage;
}

template<class Type>
int CTECHashTable<Type>::getSize()
{
	return this->size;
}

template<class Type>
void CTECHashTable<Type>::add(HashNode<Type> currentNode)
{
	if (!contains(currentNode))
	{
		//Update size if needed. Find where to put the value.
		if (this->size / this->capacity >= this->efficiencyPercentage)
		{
			updateSize();
		}

		int positionToInsert = findPosition(currentNode);

		if (internalStorage[positionToInsert] != nullptr)
		{
			//Loop over the internalStorage to find the next empty slot. Insert the value there.
			while(internalStorage[positionToInsert] != nullptr)
			{
				//positionToInsert = (positionToInsert + 1) % capacity;
				positionToInsert = handleCollision(currentNode);
			}
		}
		internalStorage[positionToInsert] = &currentNode;
		size++;
	}
}

template<class Type>
void CTECHashTable<Type>::addToTable(HashNode<Type> currentNode)
{
	if(this->tableSize / this->tableCapacity >= this->efficiencyPercentage)
	{
	updateTableCapacity();
	}
	int positionToInsert = findPosition(currentNode);

	if(tableStorage[positionToInsert] == nullptr)
	{
		CTECList<HashNode<Type> > hashList;
		tableStorage[positionToInsert] = hashList;
		hashList.addEnd(currentNode);
	}
	else
	{
		tableStorage[positionToInsert].addEnd(currentNode);
	}
}

template<class Type>
int CTECHashTable<Type>::findPosition(HashNode<Type> currentNode)
{
	//We are going to "hash" the key of the hashnode to find its storage spot.
	int position = 0;

	position = currentNode.getKey() % capacity;

	return position;
}

template<class Type>
int CTECHashTable<Type>::findTablePosition(HashNode<Type> currentNode)
{
	//We are going to "hash" the key of the hashnode to find its storage spot.
	int position = 0;

	position = currentNode.getKey() % tableCapacity;

	return position;
}

template<class Type>
void CTECHashTable<Type>::updateTableCapacity()
{
	int updatedCapacity = getNextPrime();
	CTECList<HashNode<Type> > * updateTable = new CTECList<HashNode<Type> >[updatedCapacity];

	int oldTableCapacity = tableCapacity;
	tableCapacity = updatedCapacity;

	for(int index = 0; index < oldTableCapacity; index++)
	{
		if(tableStorage[index] != nullptr)
		{
			CTECList<HashNode<Type> > temp = tableStorage[index];

			for(int innerIndex = 0; innerIndex < tableStorage[index].getSize(); innerIndex++)
			{
				int updatedTablePosition = findPosition(temp.getAtIndex(index));
				if(updateTable[updatedTablePosition] == nullptr)
				{
					CTECList<HashNode<Type> > updatedList;
					updatedList.addEnd(temp.getAtIndex(index));
				}
				else
				{
					updateTable[updatedTablePosition].addEnd(temp.getAtIndex(index));
				}
			}
		}
	}
	tableStorage = updateTable;
}

template<class Type>
int CTECHashTable<Type>::getNextPrime()
{
	int nextPrime = (capacity * 2) + 1;

	while (!isPrime(nextPrime))
	{
		nextPrime++;
	}

	return nextPrime;
}

template<class Type>
bool CTECHashTable<Type>::isPrime(int candidateNumber)
{
	bool isPrime = true;

	if (candidateNumber <= 1)
	{
		return false;
	}
	else if (candidateNumber == 2 || candidateNumber == 3)
	{
		isPrime = true;
	}
	else if (candidateNumber % 2 == 0)
	{
		isPrime = false;
	}
	else
	{
		for (int next = 3; next <= sqrt(candidateNumber) + 1; next += 2)
		{
			if (candidateNumber % next == 0)
			{
				isPrime = false;
				break;
			}
		}
	}

	return isPrime;
}

template<class Type>
void CTECHashTable<Type>::updateSize()
{
	int updatedCapacity = getNextPrime();
	HashNode<Type>** updatedStorage = new HashNode<Type>*[updatedCapacity];

	int oldCapacity = capacity;
	capacity = updatedCapacity;

	for (int index = 0; index < capacity; index++)
	{
		if (internalStorage[index] != nullptr)
		{
			int updatedPosition = findPosition(*internalStorage[index]);
			updatedStorage[updatedPosition] = internalStorage[index];
		}
	}
	internalStorage = updatedStorage;
}

template<class Type>
bool CTECHashTable<Type>::contains(HashNode<Type> currentNode)
{
	bool isInTable = false;

	int index = findPosition(currentNode);
	while (internalStorage[index] != nullptr&& !isInTable)
	{
		if(internalStorage[index]->getValue() == currentNode.getValue())
		{
			isInTable = true;
		}
		else
		{
			index = (index + 1) % capacity;
		}
	}

	return isInTable;
}

template<class Type>
bool CTECHashTable<Type>::remove(HashNode<Type> currentNode)
{
	bool wasRemoved = false;

	if (contains(currentNode))
	{
		int index = findPosition(currentNode);
		while (internalStorage[index] != nullptr&& !wasRemoved)
		{
			if(internalStorage[index].getValue() == currentNode.getValue())
			{
				wasRemoved = true;
				internalStorage[index] = nullptr;
			}
			else
			{
				index = (index + 1) % capacity;
			}
		}
	}
	return wasRemoved;
}

template<class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
	int reHashedPosition = findPosition(currentNode);
	int randomEven = rand() % capacity;

	reHashedPosition = (randomEven + (reHashedPosition * reHashedPosition)) % capacity;

	return reHashedPosition;
}

