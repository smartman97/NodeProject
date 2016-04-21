/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: clar5254
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include "../Model/Node.h"
#include "../Model/Node.cpp" //Must include a reference to .h and .cpp

#include "../Model/ArrayNode.h"
#include "../Model/ArrayNode.cpp"

#include "../Model/CTECArray.h"
#include "../Model/CTECArray.cpp"

#include "../Model/CTECList.h"
#include "../Model/CTECList.cpp"

#include "../Model/CTECBinaryTree.h"
#include "../Model/CTECBinaryTree.cpp"

#include "../Model/Timer.h"


#include <iostream>
#include <string>

using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterInts;
	CTECList<int> * numbers;
	Timer arrayTimer;
	void testLists();
	void checkSorts();
	int * mergeData;
	void doMergeSort();
	void mergeSort(int data[], int size);
	void merge(int data[], int sizeOne, int sizeTwo);
	void doBogo();
	void quickSort(int first, int last);
	int partition(int first, int last);
	void swap(int first, int last);
	void doQuick();
	void tryTree();
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
