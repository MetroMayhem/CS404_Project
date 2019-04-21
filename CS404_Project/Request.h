#pragma once
#include <iostream>
class Request
{
public:
	Request() {
		requestID = 0;
		zipCode = 0;
		vehicleType = 0;
		vehicleID = 0;
	}

	Request(int rID, int zip, int vType, int vID = -1) {
		requestID = rID;
		zipCode = zip;
		vehicleType = vType;
		vehicleID = vID;
	}

	~Request(){

	}

	//getters and setters
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

	//utility functions
	bool is_completed() {	//a request is completed if it has been assigned a vehicle id
		return (vehicleID != 0);
	}

	friend ostream& operator<<(ostream& os, const Request& req);
	

private:
	int requestID;
	int zipCode;
	int vehicleType;
	int vehicleID;
};

ostream& operator<<(ostream& os, const Request& req) {
	os << req.get_request_id() << " " << req.get_vehicle_type() << " " << req.get_zip() << " " << req.get_vehicle_id() << endl;
}