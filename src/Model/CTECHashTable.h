/*
 * CTECHashTable.h
 *
 *  Created on: May 5, 2016
 *      Author: clar5254
 */

#ifndef MODEL_CTECHASHTABLE_H_
#define MODEL_CTECHASHTABLE_H_

template<class Type>
class CTECHashTable
{
private:
	int capacity;
	double efficiencyPercentage;
	int size;
	Type* interalStorage;

	void updateSize();
	int findPosition(const Type& value);
	int handleCollision(const Type& value);
public:
	CTECHashTable();
	virtual ~CTECHashTable();
	void add(const Type& value);
	bool remove(const Type& value);
	bool contains(const Type& value);
};

#endif /* MODEL_CTECHASHTABLE_H_ */
