#include <iostream>
#include <fstream>
#include <vector>
#include "EmergencyVehicles.h"
#include "Request.h"
#include "Edge.h"
#include "List_Graph.h"
#include "Responded.h"
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
	int requestID, zip, vehicleType;
	while (!requestsFile.eof()) {
		//rtemp = Request(requestsFile.get(), requestsFile.get(), requestsFile.get(), -1);
		requestsFile >> requestID >> vehicleType >> zip;
		rtemp = Request(requestID, vehicleType, zip);
		requests.push_back(rtemp);
		//cout << rtemp.get_request_id() << " " << rtemp.get_vehicle_type() << " " << rtemp.get_zip() << endl;
		/*rtemp.set_request_id(requestsFile.get());
		rtemp.set_vehicle_type(requestsFile.get());
		rtemp.set_zip(requestsFile.get());
		rtemp.set_
		*/
	}

	List_Graph graph(6);
	graph.dijkstras(0);



	/*for (vector<list<Edge>>::iterator iter = graph.edges.begin(); iter < graph.edges.end(); iter++) {
		for (list<Edge>::iterator lstIter = iter->begin(); lstIter != iter->end(); lstIter++)
			cout << *lstIter;
	}
	*/

	Responded responded(0, 1, 64012, 6, 5);
	responded.AddResponded(01, 1, 64080, 14, 12);

	cout << responded;

	return 0;
}