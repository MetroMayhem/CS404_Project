#pragma once



class List_Graph
{

public:
	List_Graph(int n, bool d);

	iterator begin(int zip1) const;

	Edge get_edge(int zip1, int zip2) const;

	void insert(const Edge& edge);

	bool is_edge(int zip1, int zip2) const;

	~List_Graph();

private:

	std::vector<list<Edge>> edges;

};

