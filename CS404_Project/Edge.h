#pragma once
#include <string>

class Edge {

public:

	Edge(int firstZip, int secondZip, double dist = 1.0);
	Edge(const Edge& other);
	Edge();

	bool operator==(const Edge& other);
	int getZip1();
	int getZip2();
	double getWeight();
	string toString();


private:


	int zipCode1;
	int zipCode2;
	double distance;


};

