#include <iostream>
#include <fstream>
#include <vector>
#include "EmergencyVehicles.h"
#include "Request.h"
#include "Edge.h"
#include "List_Graph.h"
#include "Responded.h"

#define V 6

using namespace std;

int main() {
	//Reading in files
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
		requestsFile >> requestID >> vehicleType >> zip;
		rtemp = Request(requestID, vehicleType, zip);
		requests.push_back(rtemp);
	}
	requestsFile.close();

	//Initializes graph of the data
	List_Graph graph(V);
	int* distances = new int[V];
	int minZip = -1, VID = 0, minCost = INT_MAX;
	Responded responded;
	for (vector<Request>::iterator req = requests.begin(); req != requests.end(); req++) {
		//For each request, find the shortest cost path to each node with Dijkstras Algorithm
		graph.dijkstras(graph.indices[req->get_zip()], distances);
		for (int i = 0; i < V; i++) {
			for (map<int, int>::iterator zip = graph.indices.begin(); zip != graph.indices.end(); zip++) {
				//Iterates through the zipcode/index map to find which zip code matches
				//to each cost
				if (zip->second == i && distances[i] < minCost) {
					for (vector<EmergencyVehicles>::iterator cars = vehicles.begin(); cars != vehicles.end(); cars++) {
						if (zip->first == cars->ZipCode && cars->Type == req->get_vehicle_type()) {
							minCost = distances[i];
							minZip = zip->first;
							VID = cars->ID;
						}
					}
					zip = graph.indices.end();
					zip--;
				}
			}
		}
		
		responded.AddResponded(req->get_request_id(), req->get_vehicle_type(), minZip, VID, minCost, req->get_zip());
		vehicles[--VID].ZipCode = req->get_zip();
		minZip = -1, VID = 0, minCost = INT_MAX;
	}
	cout << responded;
	return 0;
}
	