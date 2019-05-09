#pragma once
#include <string>
#include <iostream>

class Edge {

public:

	// Constructors
	Edge(int firstZip, int secondZip, int dist);
	Edge(const Edge& other);
	Edge();

	bool operator==(Edge& other);
	
	// Getters
	int getZip1();
	int getZip2();
	int getDistance();

	// Setters
	void setZip1(int z1);
	void setZip2(int z2);
	void setDistance(int d);

	friend std::ostream& operator<<(std::ostream& os, Edge& edge);

private:

	int zipCode1;
	int zipCode2;
	int distance;  // Weight of each edge

};