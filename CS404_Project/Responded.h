#include <vector>
#include <iostream>
#include <iomanip>
#pragma once

class Responded
{
public:
	struct RespondedStruct {
		int tableID;
		int vehicleType;
		int zipCode;
		int vehicleID;
		int distance;
	};

	std::vector<RespondedStruct> tableOfResponded;


	Responded(){};

	//Constructor
	Responded(int tableid, int vehicletype, int zipcode, int vehicleid, int distance) {
		RespondedStruct temp;
		temp.tableID = tableid;
		temp.vehicleType = vehicletype;
		temp.zipCode = zipcode;
		temp.vehicleID = vehicleid;
		temp.distance = distance;
		tableOfResponded.push_back(temp);
	}

	// Adds a new completed vehicle into responded
	void AddResponded(int tableid, int vehicletype, int zipcode, int vehicleid, int distance) {
		RespondedStruct temp;
		temp.tableID = tableid;
		temp.vehicleType = vehicletype;
		temp.zipCode = zipcode;
		temp.vehicleID = vehicleid;
		temp.distance = distance;
		tableOfResponded.push_back(temp);
	}

	// Prints all responded events
	friend std::ostream& operator<<(std::ostream& os, Responded& responded) {
		os << "================================================================\n"
			<< setw(10) << "|| Table ID" << "|"
			<< setw(15) << "Vehicle Type" << "|"
			<< setw(10) << "Zip Code" << "|"
			<< setw(12) << "Vehicle ID" << "|"
			<< setw(10) << "Distance" << "||\n"
			<< "================================================================\n";
		for (int i = 0; i < responded.tableOfResponded.size(); i++) {
			os << "||" << setw(9) << responded.tableOfResponded[i].tableID << "|"
				<< setw(15) << responded.tableOfResponded[i].vehicleType << "|"
				<< setw(10) << responded.tableOfResponded[i].zipCode << "|"
				<< setw(12) << responded.tableOfResponded[i].vehicleID << "|"
				<< setw(10) << responded.tableOfResponded[i].distance << "||\n";
		}
		os << "================================================================\n";
		return os;
	}

};