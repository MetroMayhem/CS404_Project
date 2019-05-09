#include <vector>
#include <iterator>
#include <list>
#include <map>
#include "Edge.h"
#pragma once


using namespace std;
class List_Graph
{

public:
	List_Graph(int n);

	vector<list<Edge>>::iterator begin(int zip1);

	Edge get_edge(int zip1, int zip2);

	void insert(Edge edge);

	int minDistance(int dist[], bool sptSet[]);

	void dijkstras(int src, int* &arr);

	~List_Graph();
	
	map<int, int> indices;

	vector<list<Edge>> edges;

};

