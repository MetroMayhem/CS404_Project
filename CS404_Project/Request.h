#pragma once
class Request
{
public:
	Request() {
		requestID = 0;
		zipCode = 0;
		vehicleType = 0;
		vehicleID = 0;
	}

	Request(int rID, int zip, int vType, int vID) {
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

	void set_vehicle_id(int id) {
		vehicleID = id;
	}

	//utility functions
	bool is_completed() {	//a request is completed if it has been assigned a vehicle id
		return (vehicleID != 0);
	}

private:
	int requestID;
	int zipCode;
	int vehicleType;
	int vehicleID;
};

