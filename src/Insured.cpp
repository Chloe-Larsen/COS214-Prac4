#include "../import/Insured.h"
#include <iostream>

Insured::Insured(ShippingUnit *unit, double value)
	: ShipmentType(unit), declaredValue(value) {}

void Insured::process()
{
	std::cout << "    [Insured] coverage active for declared value " << declaredValue << "." << std::endl;
	ShipmentType::process();
}

double Insured::estimateShippingCost()
{
	return ShipmentType::estimateShippingCost() + declaredValue * 0.01; // 1% premium
}
