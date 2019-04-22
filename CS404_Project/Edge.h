#pragma once
#include <string>

class Edge {

public:

	Edge(int firstZip, int secondZip, int dist);
	Edge(const Edge& other);
	Edge();

	bool operator==(Edge& other);
	int getZip1();
	int getZip2();
	int getDistance();
	std::string toString();


private:


	int zipCode1;
	int zipCode2;
	int distance;


};

