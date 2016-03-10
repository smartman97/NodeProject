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

void NodeController :: testLists()
{
	numbers->addFront(3);
	numbers->addEnd(8);

	cout << "Front should be 3 and is : " << numbers->getFront() << endl;
	cout << "End should be 8 and is : " << numbers->getEnd() << endl;
}

void NodeController :: start()
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
