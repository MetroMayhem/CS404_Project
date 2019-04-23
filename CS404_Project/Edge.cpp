#include "Edge.h"
#include <string>


Edge::Edge(int firstZip, int secondZip, int dist = 1) {
	zipCode1 = firstZip;
	zipCode2 = secondZip;
	distance = dist;
}

Edge::Edge(const Edge& other) {
	zipCode1 = other.zipCode1;
	zipCode2 = other.zipCode2;
	distance = other.distance;
}

Edge::Edge() {
	zipCode1 = 0;
	zipCode2 = 0;
	distance = 0;
}

bool Edge::operator==(Edge& other) {
	if (this->getZip1() == other.getZip1() && this->getZip2() == other.getZip2())
		return true;

	return false;
	}
	
int Edge::getZip1() {
	return zipCode1;
	}

int Edge::getZip2() {
	return zipCode2;
	}

int Edge::getDistance() {
	return distance;
	}
	

void Edge::setZip1(int z1)
{
	zipCode1 = z1;
}
void Edge::setZip2(int z2) {
	zipCode2 = z2;
}
void Edge::setDistance(int d) {
	distance = d;
}

std::string Edge::toString() {
	return " ";
	}




