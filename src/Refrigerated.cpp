#include "../import/Refrigerated.h"
#include <iostream>

Refrigerated::Refrigerated(ShippingUnit *unit, double targetTemp)
	: ShipmentType(unit), targetTemp(targetTemp) {}

void Refrigerated::logTemperatureTelemetry()
{
	std::cout << "    [Refrigerated] holding " << targetTemp << " C." << std::endl;
}

void Refrigerated::process()
{
	logTemperatureTelemetry();
	ShipmentType::process();
}

double Refrigerated::estimateShippingCost()
{
	return ShipmentType::estimateShippingCost() + 80.0; // cooling surcharge
}
