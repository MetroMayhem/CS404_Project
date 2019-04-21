#include "Edge.h"
#include <string>


Edge::Edge(int firstZip, int secondZip, double dist = 1.0) {

}

Edge::Edge(const Edge& other) {

}

Edge::Edge() {

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
	
std::string Edge::toString() {

	}




