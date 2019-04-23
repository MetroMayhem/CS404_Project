#include <iostream>
#include <fstream>
#include <vector>
#include "EmergencyVehicles.h"
#include "Request.h"
#include "Edge.h"
using namespace std;

int main() {
	ifstream vehiclesFile("Vehicles.txt");
	vector<EmergencyVehicles> vehicles;
	EmergencyVehicles vtemp;
	while (!vehiclesFile.eof()) {
		vehiclesFile >> vtemp.ID;
		vehiclesFile >> vtemp.Type;
		vehiclesFile >> vtemp.ZipCode;
		
		vehicles.push_back(vtemp);
	}
	vehiclesFile.close();
	ifstream requestsFile("Requests.txt");
	vector<Request> requests;
	Request rtemp = Request(0, 0, 0, -1);
	while (!requestsFile.eof()) {
		rtemp = Request(requestsFile.get(), requestsFile.get(), requestsFile.get(), -1);
		/*rtemp.set_request_id(requestsFile.get());
		rtemp.set_vehicle_type(requestsFile.get());
		rtemp.set_zip(requestsFile.get());
		rtemp.set_
		*/
	}
	for (vector<Request>::iterator iter = requests.begin(); iter < requests.end(); iter++) {
		cout << *iter;
	}

	ifstream distanceFile("Distances.txt");
	vector<Edge> edges;
	Edge edgeTemp;
	while (!distanceFile.eof()) {
		distanceFile >> edgeTemp.setZip1;
		distanceFile >> edgeTemp.setZip2;
		distanceFile >> edgeTemp.getDistance;

		edges.push_back(edgeTemp);
	}
	distanceFile.close();

	return 0;
}