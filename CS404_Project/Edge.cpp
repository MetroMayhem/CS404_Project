#include "Edge.h"
#include <string>


Edge::Edge(int firstZip, int secondZip, double dist = 1.0) {

}

Edge::Edge(const Edge& other) {

}

Edge::Edge() {

}

bool Edge::operator==(const Edge& other) {
	this->getZip1();

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
	
std::string Edge::toString() {

	}




