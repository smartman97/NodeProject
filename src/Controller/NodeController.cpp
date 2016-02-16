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
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	arrayTimer.startTimer();

	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (23 * index));
		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
}
