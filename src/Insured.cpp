#include "../import/Insured.h"
#include <iostream>

Insured::Insured(ShippingUnit *unit, double value) : ShipmentType(unit), declaredValue(value)
{
}

void Insured::process()
{
    ShipmentType::process();
    std::cout << "Insurance coverage applied: " << declaredValue << std::endl;
}