#include "List_Graph.h"
#include <iostream>
#include <fstream>
#include <limits.h>

#define V 6

using namespace std;



List_Graph::List_Graph(int n)
{
	ifstream distanceFile("Distances.txt");
	//vector<list<Edge>> edges;
	Edge edgeTemp;
	list<Edge> temp(n, edgeTemp);
	int zip1; int zip2; int distance;
	while (!distanceFile.eof()) {
		distanceFile >> zip1 >> zip2 >> distance;
		edgeTemp = Edge(zip1, zip2, distance);
		/*edgeTemp.setZip1(distanceFile.get());
		edgeTemp.setZip2(distanceFile.get());
		edgeTemp.setDistance(distanceFile.get());
		*/
		//temp.front() = edgeTemp;
		//this->edges.push_back(temp);
		insert(edgeTemp);
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
			iter = edges.end()-1;
	}
	list<Edge> temp(1, edge);

	if (!found1) {
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

bool List_Graph::is_edge(int zip1, int zip2) const
{
	return false;
}

int List_Graph::minDistance(int dist[], bool sptSet[]){
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}

	return min_index;
}

void List_Graph::printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d tt %d\n", i, dist[i]);
}

void List_Graph::dijkstras(int src, int* &arr) {
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
	// print the constructed distance array 
	printSolution(dist, V);
}




List_Graph::~List_Graph()
{
}
