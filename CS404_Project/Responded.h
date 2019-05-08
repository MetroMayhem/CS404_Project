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
		int requestZip;
	};

	std::vector<RespondedStruct> tableOfResponded;


	Responded(){};

	//Constructor
	Responded(int tableid, int vehicletype, int zipcode, int vehicleid, int distance, int requestzip) {
		RespondedStruct temp;
		temp.tableID = tableid;
		temp.vehicleType = vehicletype;
		temp.zipCode = zipcode;
		temp.vehicleID = vehicleid;
		temp.distance = distance;
		temp.requestZip = requestzip;
		tableOfResponded.push_back(temp);
	}

	// Adds a new completed vehicle into responded
	void AddResponded(int tableid, int vehicletype, int zipcode, int vehicleid, int distance, int requestzip) {
		RespondedStruct temp;
		temp.tableID = tableid;
		temp.vehicleType = vehicletype;
		temp.zipCode = zipcode;
		temp.vehicleID = vehicleid;
		temp.distance = distance;
		temp.requestZip = requestzip;
		tableOfResponded.push_back(temp);
	}

	// Prints all responded events
	friend std::ostream& operator<<(std::ostream& os, Responded& responded) {
		os << "==================================================================================\n" << left
			<< setw(4) << "||" << right << "Request ID" << "|"
			<< setw(15) << "Vehicle Type" << "|"
			<< setw(12) << "Request Zip" << "|"
			<< setw(12) << "Vehicle ID" << "|"
			<< setw(10) << "Distance" << "|"
			<< setw(12) << "Vehicle Zip" << "||\n"
			<< "==================================================================================\n";
		for (int i = 0; i < responded.tableOfResponded.size(); i++) {
			os << "||" << setw(12) << responded.tableOfResponded[i].tableID << "|"
				<< setw(15) << responded.tableOfResponded[i].vehicleType << "|"
				<< setw(12) << responded.tableOfResponded[i].requestZip << "|"
				<< setw(12) << responded.tableOfResponded[i].vehicleID << "|"
				<< setw(10) << responded.tableOfResponded[i].distance << "|"
				<< setw(12) << responded.tableOfResponded[i].zipCode << "||\n";
		}
		os << "==================================================================================\n";
		return os;
	}

};