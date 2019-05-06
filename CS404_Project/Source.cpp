#include <iostream>
#include <fstream>
#include <vector>
#include "EmergencyVehicles.h"
#include "Request.h"
#include "Edge.h"
#include "List_Graph.h"
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
	//int h = graph.dijkstras(0);
	//cout << h;
	int* distances = new int[6];
	for (vector<Request>::iterator iter = requests.begin(); iter != requests.end(); iter++) {
		graph.dijkstras(graph.indices[iter->get_zip()], distances);
		for (int i = 0; i < 6; i++)
			cout << distances[i] << endl;

		int temp;
		for (int i = 1; i < 6; i++) {
			int j = i;
			while (j > 0 && distances[j] < distances[j - 1]) {
				temp = distances[j];
				distances[j] = distances[j - 1];
				distances[j - 1] = temp;
				cout << distances[j];
				j--;
			}
		}
		for (int i = 0; i < 6; i++)
			cout << distances[i];

	}
	
	return 0;
}
	