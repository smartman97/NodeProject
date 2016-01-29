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
#include <iostream>

class NodeController
{
private:
	Node<int> myNode;
public:
	NodeController();
	virtual ~NodeController();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
