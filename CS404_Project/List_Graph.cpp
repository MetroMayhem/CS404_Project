#include "List_Graph.h"
#include <iostream>
#include <fstream>
#include <limits.h>

#define V 6

using namespace std;



List_Graph::List_Graph(int n)
{
	ifstream distanceFile("Distances.txt");
	Edge edgeTemp;
	list<Edge> temp(n, edgeTemp);
	int zip1; int zip2; int distance;
	while (!distanceFile.eof()) {
		distanceFile >> zip1 >> zip2 >> distance;
		edgeTemp = Edge(zip1, zip2, distance);
		insert(edgeTemp);
	}
	distanceFile.close();

}

vector<list<Edge>>::iterator List_Graph::begin(int zip1)
{
	return edges.begin();
}

Edge List_Graph::get_edge(int zip1, int zip2)	//Gets the edge between to zipcodes if it exists
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

	//Iterate through the list graph to try and find the zipcodes that are being inserted (both directions)
	for (vector<list<Edge>>::iterator iter = edges.begin(); iter < edges.end(); iter++) {
		if (iter->front().getZip1() == zip1) {		//If found, push the new edge back in the list
			iter->push_back(edge);
			found1 = true;
		}
		else if (iter->front().getZip1() == zip2) {
			iter->push_back(Edge(zip2, zip1, distance));
			found2 = true;
		}
		if (found1 && found2)		//If both are found stop searching
			iter = edges.end()-1;
	}
	list<Edge> temp(1, edge);

	if (!found1) {		//Add new instances of the zip code if it wasn't already found
		edges.push_back(temp);
		indices[edge.getZip1()] = edges.size() - 1;
	}
	
	temp.front() = Edge(zip2, zip1, distance);
	if (!found2) {
		edges.push_back(temp);
		indices[edge.getZip2()] = edges.size() - 1;
	}
	return;
}

int List_Graph::minDistance(int dist[], bool sptSet[]){		//Finds the minimum distance between unvisited nodes
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}

	return min_index;
}

void List_Graph::dijkstras(int src, int* &arr) {		//Dijkstras Algorithm
	int dist[V];
	bool sptSet[V];
	
	for (int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0 
	dist[src] = 0;

	// Find shortest path for all vertices 
	for (int count = 0; count < V; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed 
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (list<Edge>::iterator v = edges[u].begin(); v != edges[u].end(); v++)

			// Update dist[v] only if is not in sptSet, there is an edge from  
			// u to v, and total weight of path from src to  v through u is  
			// smaller than current value of dist[v] 
			if (!sptSet[indices[v->getZip2()]] && dist[u] != INT_MAX && dist[u] + v->getDistance() < dist[indices[v->getZip2()]])
				dist[indices[v->getZip2()]] = dist[u] + v->getDistance();
	}
	for (int i = 0; i < V; i++) {
		arr[i] = dist[i];
	}
}




List_Graph::~List_Graph()
{
}
