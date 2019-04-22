#include "List_Graph.h"



List_Graph::List_Graph(int n , bool d)
{
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
