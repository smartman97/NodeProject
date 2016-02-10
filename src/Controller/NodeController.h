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

#include <iostream>
#include <string>

using namespace std;

class NodeController
{
private:
	CTECArray<string> * myStringArray;
public:
	NodeController();
	virtual ~NodeController();
	void start();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
