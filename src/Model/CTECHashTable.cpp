/*
 * CTECHashTable.cpp
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#include "CTECHashTable.h"

template<class Type>
CTECHashTable<Type> :: CTECHashTable()
{
	this->capacity = 101;
	this-efficiencyPercentage = .667;
	this->size = 0;
	this->internalStorage= new Type[capacity];
}

template<class Type>
CTECHashTable<Type> :: ~CTECHashTable()
{
	delete [] internalStorage;
}

template<class Type>
int CTECHashTable<Type> :: getSize()
{
	return this->size();
}

template<class Type>
void CTECHashTable<Type> :: add(const Type& value)
{
	//Update size if needed. Find where to put the value.
	if(!contains(value))
	{
		int positionToInsert = findPosition(value);

		if(internalStorage[positionToInsert] != nullptr)
		{
			//Loop over the internalStorage to find the next empty slot. Insert the value there.
			while(internalStorage[positionToInsert != nullptr])
			{
				positionToInsert = (positionToInsert + 1) % size;
			}
			internalStorage[positionToInsert] = value;
		}
		else
		{
			internalStorage[positionToInsert] = value;
		}
	}
}

