/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: clar5254
 */

#include "NodeController.h"

NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(400);
	numbers = new CTECList<int>();
}

NodeController::~NodeController()
{

}

void NodeController::start()
{
	tryTree();
}

void NodeController::tryTree()
{
	CTECBinaryTree<int> testTree;
	testTree.insert(5);
	testTree.insert(7);
	testTree.insert(3);
	testTree.insert(111);
	testTree.insert(4563);
	testTree.insert(0);
	testTree.insert(-13);

	cout << "INORDER TRAVERSAL" << endl;
	testTree.inorderTraversal(testTree.getRoot());
	cout << " Tree" << endl;

	cout << "PREORDER TRAVERSAL" << endl;
	testTree.preorderTraversal(testTree.getRoot());
	cout << " Tree" << endl;

	cout << "POSTORDER TRAVERSAL" << endl;
	testTree.postorderTraversal(testTree.getRoot());
	cout << " Tree" << endl;

	cout << testTree.contains(5) << endl;

	testTree.remove(5);

	cout << "INORDER TRAVERSAL" << endl;
	testTree.inorderTraversal(testTree.getRoot());
	cout << " Tree" << endl;
}

void NodeController::testLists()
{
	numbers->addFront(3);
	numbers->addEnd(8);

	cout << "Front should be 3 and is : " << numbers->getFront() << endl;
	cout << "End should be 8 and is : " << numbers->getEnd() << endl;
	cout << "The size should now be 2 and is: " << numbers->getSize() << endl;

	numbers->addAtIndex(2, 10);

	cout << "End should now be 10 and is : " << numbers->getEnd() << endl;
	cout << "Returning at index 1, it should be 8 and is: " << numbers->getAtIndex(1) << endl;

	numbers->set(1, 44);

	cout << "Changing index 1, it should be 44 and is: " << numbers->getAtIndex(1) << endl;

	numbers->addFront(65);
	numbers->addFront(11);
	numbers->addFront(21);

	cout << "The size should now be 6 and is: " << numbers->getSize() << endl;

	numbers->removeEnd();
	numbers->removeFront();

	cout << "End should now be 44 and is : " << numbers->getEnd() << endl;
	cout << "Front should be 11 and is : " << numbers->getFront() << endl;
	cout << "The size should now be 4 and is: " << numbers->getSize() << endl;

	numbers->removeAtIndex(2);

	cout << "The size should now be 3 and is: " << numbers->getSize() << endl;
}

void NodeController::checkSorts()
{
	CTECArray<int> numbersInArray(5);
	CTECList<int> numbersInList;

	for (int spot = 0; spot < 5000; spot++)
	{
		int randomValue = rand();
		numbersInArray.set(spot, randomValue);
		numbersInList.addEnd(randomValue);
	}
	arrayTimer.startTimer();

	numbersInList.selectionSort();

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();

	arrayTimer.resetTimer();

	arrayTimer.startTimer();

	numbersInArray.selectionSort();

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}

void NodeController::doMergeSort()
{
	mergeData = new int[500000];
	for (int spot = 0; spot < 500000; spot++)
	{
		int randomValue = rand();
		mergeData[spot] = randomValue;
	}
	mergeSort(mergeData, 500000);

	Timer mergeTimer;
	mergeTimer.startTimer();
	mergeSort(mergeData, 500000);
	mergeTimer.stopTimer();
	mergeTimer.displayTimerInformation();

	delete[] mergeData;
}

void NodeController::mergeSort(int data[], int size)
{
	int sizeOne;
	int sizeTwo;

	if (size > 1)
	{
		sizeOne = size / 2;
		sizeTwo = size - sizeOne;

		mergeSort(data, sizeOne);
		mergeSort(data + sizeOne, sizeTwo);

		merge(data, sizeOne, sizeTwo);
	}
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
	int* temp; //Link for a temp array
	int copied = 0;
	int copied1 = 0;
	int copied2 = 0;
	int index;

	temp = new int[sizeOne + sizeTwo];

	while (copied1 < sizeOne && copied2 < sizeTwo)
	{
		if (data[copied1] < (data + sizeOne)[copied2]) //smaller goes in small half
		{
			temp[copied++] = data[copied1++];
		}
		else //large goes in large half
		{
			temp[copied++] = (data + sizeOne)[copied2++];
		}
	}

	while (copied1 < sizeOne)
	{
		temp[copied++] = data[copied1++];
	}
	while (copied2 < sizeTwo)
	{
		temp[copied++] = (data + sizeOne)[copied2++];
	}

	for (index = 0; index < sizeOne + sizeTwo; index++)
	{
		data[index] = temp[index];
	}
	delete[] temp;
}

void NodeController::quickSort(int first, int last)
{
	int pivotIndex;

	if (first < last)
	{
		pivotIndex = partition(first, last);
		quickSort(first, pivotIndex - 1);
		quickSort(pivotIndex + 1, last);
	}
}

int NodeController::partition(int first, int last)
{
	int pivot;
	int index, smallIndex;
	swap(first, (first + last) / 2);

	pivot = mergeData[first];
	smallIndex = first;

	for (index = first + 1; index <= last; index++)
	{
		if (mergeData[index] < pivot)
		{
			smallIndex++;
			swap(smallIndex, index);
		}
	}
	swap(first, smallIndex);
	return smallIndex;
}

void NodeController::swap(int first, int last)
{
	int temp = mergeData[first];
	mergeData[first] = mergeData[last];
	mergeData[last] = temp;
}

void NodeController::doQuick()
{
	mergeData = new int[500000];

	for (int spot = 0; spot < 500000; spot++)
	{
		int myRandom = rand();
		mergeData[spot] = myRandom;
	}

	Timer mergeTimer;
	mergeTimer.startTimer();
	quickSort(0, 500000);
	mergeTimer.stopTimer();
	mergeTimer.displayTimerInformation();

	delete[] mergeData;
}

void NodeController::doBogo()
{
	int temp[10];
	int check[10];

	for (int index = 0; index < 10; index++)
	{
		check[index] = index;
	}
}
