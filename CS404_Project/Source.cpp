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

	List_Graph graph(V);
	//int h = graph.dijkstras(0);
	//cout << h;
	int* distances = new int[V];
	//map<int, int> costs;
	int minZip = -1, VID = 0, minCost = INT_MAX;
	Responded responded;
	for (vector<Request>::iterator req = requests.begin(); req != requests.end(); req++) {
		graph.dijkstras(graph.indices[req->get_zip()], distances);
		
		for (int i = 0; i < V; i++) {
			for (map<int, int>::iterator zip = graph.indices.begin(); zip != graph.indices.end(); zip++) {
				if (zip->second == i && distances[i] < minCost) {
					//costs[miter->first] = distances[i];

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
		
		responded.AddResponded(req->get_request_id(), req->get_vehicle_type(), minZip, VID, minCost);
		vehicles[--VID].ZipCode = req->get_zip();
		minZip = -1, VID = 0, minCost = INT_MAX;
		/*
		int temp;
		for (int i = 1; i < 6; i++) {
			int j = i;
			while (j > 0 && distances[j] < distances[j - 1]) {
				temp = distances[j];
				distances[j] = distances[j - 1];
				distances[j - 1] = temp;
				j--;
			}
		}*/
	}
	cout << responded;
	
	return 0;
}
	