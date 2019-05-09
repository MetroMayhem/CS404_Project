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

Responded HandleRequests(vector<Request> requests, map<int, vector<EmergencyVehicles>> vehicles);

int main() {
	//Reading in files
	ifstream vehiclesFile("Vehicles.txt");
	//vector<EmergencyVehicles> cars;
	EmergencyVehicles vtemp;
	map<int, vector<EmergencyVehicles>> vehicles;
	while (!vehiclesFile.eof()) {
		vehiclesFile >> vtemp.ID;
		vehiclesFile >> vtemp.Type;
		vehiclesFile >> vtemp.ZipCode;
		vehicles[vtemp.ZipCode].push_back(vtemp);
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


	/*
	//Initializes graph of the data
	List_Graph graph(V);
	int* distances = new int[V];
	int minZip = -1, minIdx = -1, VID = 0, minCost = INT_MAX;
	Responded responded;

	for (vector<Request>::iterator req = requests.begin(); req != requests.end(); req++) {
		//For each request, find the shortest cost path to each node with Dijkstras Algorithm
		graph.dijkstras(graph.indices[req->get_zip()], distances);
		for (int i = 0; i < V; i++) {
			for (map<int, int>::iterator zip = graph.indices.begin(); zip != graph.indices.end(); zip++) {
				//Iterates through the zipcode/index map to find which zip code matches
				//to each cost, and if the indices match + that cost is less than the min
				//See if the desired vehicle type is at that zip code
				if (zip->second == i && distances[i] < minCost) {
					//Iteratess through the emergency vehicles at the location from zip
					//and sees if the desired vehicle is there, updates the cost if so
					for (int car = 0; car < vehicles[zip->first].size(); car++) {
						if (vehicles[zip->first][car].Type == req->get_vehicle_type()) {
							minCost = distances[i];
							minZip = zip->first;
							VID = vehicles[zip->first][car].ID;
							minIdx = car;
							car = vehicles[zip->first].size();
						}
					}
				}
			}
		}
		//Adds the chosen vehicle to the responded table, moves the vehicle to the request zip code
		//and resets the min vehicles variables
		responded.AddResponded(req->get_request_id(), req->get_vehicle_type(), minZip, VID, minCost, req->get_zip());
		vehicles[req->get_zip()].push_back(vehicles[minZip][minIdx]);
		(vehicles[req->get_zip()].end()-1)->ZipCode = req->get_zip();
		vehicles[minZip].erase(vehicles[minZip].begin() + minIdx);
		minZip = -1, VID = 0, minCost = INT_MAX;
	}
	*/
	Responded r = HandleRequests(requests, vehicles);
	cout << r;
	return 0;
}
	
Responded HandleRequests(vector<Request> requests, map<int, vector<EmergencyVehicles>> vehicles) {
	//Handles each Request by matching it to its desired emergency vehicle O(n^2)
	//Initializes graph of the data
	List_Graph graph(V);
	int* distances = new int[V];
	int minZip = -1, minIdx = -1, VID = 0, minCost = INT_MAX;
	Responded responded;

	for (vector<Request>::iterator req = requests.begin(); req != requests.end(); req++) {
		//For each request, find the shortest cost path to each node with Dijkstras Algorithm
		graph.dijkstras(graph.indices[req->get_zip()], distances);
		for (int i = 0; i < V; i++) {
			for (map<int, int>::iterator zip = graph.indices.begin(); zip != graph.indices.end(); zip++) {
				//Iterates through the zipcode/index map to find which zip code matches
				//to each cost, and if the indices match and that cost is less than the min
				//See if the desired vehicle type is at that zip code
				if (zip->second == i && distances[i] < minCost) {
					//Iteratess through the emergency vehicles at the location from zip
					//and sees if the desired vehicle is there, updates the cost if so
					for (int car = 0; car < vehicles[zip->first].size(); car++) {
						if (vehicles[zip->first][car].Type == req->get_vehicle_type()) {
							minCost = distances[i];
							minZip = zip->first;
							VID = vehicles[zip->first][car].ID;
							minIdx = car;
							car = vehicles[zip->first].size();		//Stops iterations
						}
					}
					zip = --graph.indices.end();		//Stops iterations
				}
				else if (zip->second == i)
					zip = --graph.indices.end();
			}
		}
		//Adds the chosen vehicle to the responded table, moves the vehicle to the request zip code
		//and resets the min vehicles variables
		responded.AddResponded(req->get_request_id(), req->get_vehicle_type(), minZip, VID, minCost, req->get_zip());
		vehicles[req->get_zip()].push_back(vehicles[minZip][minIdx]);
		(vehicles[req->get_zip()].end() - 1)->ZipCode = req->get_zip();
		vehicles[minZip].erase(vehicles[minZip].begin() + minIdx);
		minZip = -1, VID = 0, minCost = INT_MAX;
		
	}
	return responded;
}

