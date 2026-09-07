#ifndef HAZMAT_H
#define HAZMAT_H

#include "ShipmentType.h"

class Hazmat : public ShipmentType
{
private:
	string hazmatClass;
	bool placarded;
	vector<string> validHazmatCodes;

public:
	Hazmat(ShippingUnit *unit, string code, bool isPlacarded);
	bool verifyPlacarding();
	void process() override;	
	double estimateShippingCost() override;	
};

#endif
