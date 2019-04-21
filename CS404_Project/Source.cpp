#include <iostream>
#include <fstream>
#include <vector>
#include "EmergencyVehicles.h"
using namespace std;

int main() {
	ifstream vehiclesFile("Vehicles.txt");
	vector<EmergencyVehicles> vehicles;
	EmergencyVehicles temp;
	while (!vehiclesFile.eof()) {
		
		//temp.ID = vehiclesFile.get();
		//temp.Type = vehiclesFile.get();
		//temp.ZipCode = vehiclesFile.get();
		
		vehiclesFile >> temp.ID;
		vehiclesFile >> temp.Type;
		vehiclesFile >> temp.ZipCode;
		
		vehicles.push_back(temp);
	}
	vehiclesFile.close();
	for (vector<EmergencyVehicles>::iterator iter = vehicles.begin(); iter < vehicles.end(); iter++) {
		cout << iter->ID << " " << iter->Type << " " << iter->ZipCode << endl;
	}

}