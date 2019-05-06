#include <vector>
#pragma once

using namespace std;

class Responded
{
private:
	struct RespondedStruct {
		int tableID;
		int vehicleType;
		int zipCode;
		int vehicleID;
		int distance;
	};

	vector<RespondedStruct> tableOfResponded;

public:



};