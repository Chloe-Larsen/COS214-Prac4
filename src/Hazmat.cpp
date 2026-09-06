#include "../import/Hazmat.h"
#include <iostream>

Hazmat::Hazmat(ShippingUnit *unit, std::string code, bool isPlacarded)
	: ShipmentType(unit), hazmatClass(code), placarded(isPlacarded) {}

bool Hazmat::verifyPlacarding() { return placarded; }

void Hazmat::process()
{
	std::cout << "    [Hazmat] class " << hazmatClass << " placarding: "
			  << (placarded ? "OK" : "MISSING") << std::endl;
	ShipmentType::process();
}

double Hazmat::estimateShippingCost()
{
	return ShipmentType::estimateShippingCost() + 150.0; // hazardous handling surcharge
}
