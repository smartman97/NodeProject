/*
 * Graph.h
 *
 *  Created on: Apr 25, 2016
 *      Author: clar5254
 */

#ifndef MODEL_GRAPH_H_
#define MODEL_GRAPH_H_

template<class Type>
class Graph
{
private:
	static const int MAXIMUM = 20;
public:
	Graph();
	virtual ~Graph();

	void addVertex(const Type& label);
	void addEdge(int source, int target);
	void removeEdge(int source, int target);
	Type& operator [] (int vertex);
};

#endif /* MODEL_GRAPH_H_ */
