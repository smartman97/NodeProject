/*
 * Graph.h
 *
 *  Created on: Apr 25, 2016
 *      Author: clar5254
 */

#ifndef MODEL_GRAPH_H_
#define MODEL_GRAPH_H_
#include <set>

template<class Type>
class Graph
{
private:
	static const int MAXIMUM = 20;
	bool edges [MAXIMUM][MAXIMUM];
	Type labels [MAXIMUM];
	int manyVertices;
public:
	Graph();
	virtual ~Graph();

	void addVertex(const Type& vertexLabel);
	void addEdge(int source, int target);
	void removeEdge(int source, int target);
	Type& operator [] (int vertex);

	int size() const;
	bool isEdge(int source, int target) const;
	std::set<int> neighbors(int vertex) const;
	Type operator [] (int vertex) const;
};

#endif /* MODEL_GRAPH_H_ */
