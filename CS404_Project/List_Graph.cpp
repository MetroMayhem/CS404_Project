#include "List_Graph.h"
#include <iostream>
#include <fstream>

using namespace std;



List_Graph::List_Graph(int n)
{

	ifstream distanceFile("Distances.txt");
	vector<Edge> edges;
	Edge edgeTemp;
	while (!distanceFile.eof()) {
		edgeTemp.setZip1(distanceFile.get());
		edgeTemp.setZip2(distanceFile.get());
		edgeTemp.setDistance(distanceFile.get());

		edges.push_back(edgeTemp);
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
}

void List_Graph::insert(const Edge& edge)
{

}

bool List_Graph::is_edge(int zip1, int zip2) const
{
	return false;
}

List_Graph::~List_Graph()
{
}
