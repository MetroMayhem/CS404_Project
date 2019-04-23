#include <vector>
#include <iterator>
#include <list>
#include "Edge.h"
#pragma once


using namespace std;
class List_Graph
{

public:
	List_Graph(int n);

	vector<list<Edge>>::iterator begin(int zip1);

	Edge get_edge(int zip1, int zip2) const;

	void insert(const Edge& edge);

	bool is_edge(int zip1, int zip2) const;

	~List_Graph();

private:

	vector<list<Edge>> edges;

};

