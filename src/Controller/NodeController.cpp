/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: clar5254
 */

#include "NodeController.h"

NodeController::NodeController()
{
	myStringArray = new CTECArray<string>(5);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	string first = "first";
	string second = "second";
	string third = "third";
	string fourth = "fourth";
	string fifth = "fifth";

	myStringArray->set(0, first);
	myStringArray->set(1, second);
	myStringArray->set(2, third);
	myStringArray->set(3, fourth);
	myStringArray->set(4, fifth);

	for(int index = 0; index < myStringArray->getSize(); index++)
	{
		cout << "The contents at " << index << " are: " << myStringArray->get(index) << endl;
	}
}
