#ifndef HAZMAT_H
#define HAZMAT_H

#include "ShipmentType.h"

class Hazmat : public ShipmentType
{
private:
	std::string hazmatClass;
	bool placarded;
	std::vector<string> validHazmatCodes;

public:
	Hazmat(ShippingUnit *unit, std::string code, bool isPlacarded);
	bool verifyPlacarding();
	void process() override;	
	double estimateShippingCost() override;	
};

#endif
