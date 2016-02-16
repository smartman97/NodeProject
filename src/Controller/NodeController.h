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

#include "../Model/Timer.h"
#include "../Model/Timer.cpp"

#include <iostream>
#include <string>

using namespace std;

class NodeController
{
private:
	CTECArray<int> * notHipsterInts;
	Timer arrayTimer;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
