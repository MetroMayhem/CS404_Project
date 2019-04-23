#pragma once
#include <string>
#include <iostream>

class Edge {

public:

	Edge(int firstZip, int secondZip, int dist);
	Edge(const Edge& other);
	Edge();

	bool operator==(Edge& other);
	int getZip1();
	int getZip2();
	int getDistance();

	void setZip1(int z1);
	void setZip2(int z2);
	void setDistance(int d);

	friend std::ostream& operator<<(std::ostream& os, Edge& edge);


private:


	int zipCode1;
	int zipCode2;
	int distance;


};

