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

void NodeController::start()
{

	testLists();

//	arrayTimer.startTimer();
//
//	for(int index = 0; index < notHipsterInts->getSize(); index++)
//	{
//		notHipsterInts->set(index, (23 * index));
//		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
//	}
//
//	arrayTimer.stopTimer();
//	arrayTimer.displayTimerInformation();
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
	mergeData = new int[5000];
	for (int spot = 0; spot < 5000; spot++)
	{
		int randomValue = rand();
		mergeData[spot] = randomValue;
	}
	mergeSort(mergeData, 5000);
}

void NodeController::mergeSort(int dataArray[], int size)
{

}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{

}
