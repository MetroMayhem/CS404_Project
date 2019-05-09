#pragma once
#include <iostream>

using namespace std;
class Request
{
public:
	//Default Constructor
	Request() {
		requestID = 0;
		zipCode = 0;
		vehicleType = 0;
		vehicleID = 0;
	}

	//Custom Constructor
	Request(int rID, int vType, int zip, int vID = -1) {
		requestID = rID;
		zipCode = zip;
		vehicleType = vType;
		vehicleID = vID;
	}

	~Request(){

	}

	//Getters and setters
	int get_vehicle_type() const {
		return vehicleType;
	}

	int get_vehicle_id() const {
		return vehicleID;
	}

	int get_zip() const {
		return zipCode;
	}

	int get_request_id() const {
		return requestID;
	}

	void set_vehicle_type(int type) {
		vehicleType = type;
	}

	void set_vehicle_id(int id) {
		vehicleID = id;
	}

	void set_zip(int zip) {
		zipCode = zip;
	}

	void set_request_id(int rID) {
		requestID = rID;
	}

	//Utility functions
	//A request is completed if it has been assigned a vehicle id
	bool is_completed() {	
		return (vehicleID != -1);
	}

	friend ostream& operator<<(ostream& os, const Request& req);
	

private:
	int requestID;
	int zipCode;
	int vehicleType;
	int vehicleID;
};

//Overloading output operator
ostream& operator<<(ostream& os, const Request& req) {
	os << req.get_request_id() << " " << req.get_vehicle_type() << " " << req.get_zip() << " " << req.get_vehicle_id() << endl;
	return os;
}