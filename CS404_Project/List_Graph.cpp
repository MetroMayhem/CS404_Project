#include "List_Graph.h"
#include <iostream>
#include <fstream>

using namespace std;



List_Graph::List_Graph(int n)
{

	ifstream distanceFile("Distances.txt");
	vector<list<Edge>> edges;
	Edge edgeTemp;
	list<Edge> temp(n, edgeTemp);
	while (!distanceFile.eof()) {
		edgeTemp.setZip1(distanceFile.get());
		edgeTemp.setZip2(distanceFile.get());
		edgeTemp.setDistance(distanceFile.get());

		edges.push_back(temp);
	}
	distanceFile.close();

}

vector<list<Edge>>::iterator List_Graph::begin(int zip1)
{
	return edges.begin();
}

Edge List_Graph::get_edge(int zip1, int zip2)
{
	for (vector<list<Edge>>::iterator it = edges.begin(); it != edges.end(); ++it) {
		for (list<Edge>::iterator listit = it->begin(); listit != it->end(); listit++) {
			if (listit->getZip1() == zip1 && listit->getZip2() == zip2)
				return *listit;
		}
	}
	return Edge();
}

void List_Graph::insert(Edge edge)
{
	int zip1 = edge.getZip1();
	int zip2 = edge.getZip2();
	int distance = edge.getDistance();
	bool found1 = 0; bool found2 = 0;

	for (vector<list<Edge>>::iterator iter = edges.begin(); iter < edges.end(); iter++) {
		if (iter->front().getZip1() == zip1) {
			iter->push_back(edge);
			found1 = true;
		}
		else if (iter->front().getZip1() == zip2) {
			iter->push_back(Edge(zip2, zip1, distance));
			found2 = true;
		}
		if (found1 && found2)
			iter = edges.end();
	}
	list<Edge> temp(1, edge);

	if (!found1) {
		edges.push_back(temp);
	}
	
	temp.front() = Edge(zip2, zip1, distance);
	if (!found2) 
		edges.push_back(temp);
	return;
}

bool List_Graph::is_edge(int zip1, int zip2) const
{
	return false;
}

List_Graph::~List_Graph()
{
}
