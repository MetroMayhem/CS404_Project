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
		distanceFile >> edgeTemp.setZip1;
		distanceFile >> edgeTemp.setZip2;
		distanceFile >> edgeTemp.getDistance;

		edges.push_back(edgeTemp);
	}
	distanceFile.close();

}

vector<list<Edge>>::iterator List_Graph::begin(int zip1)
{
	return edges.begin();
}

Edge List_Graph::get_edge(int zip1, int zip2) const
{
	return Edge();
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
