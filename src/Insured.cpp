#include "../import/Insured.h"
#include <iostream>

Insured::Insured(ShippingUnit *unit, double value) : ShipmentType(unit, "Insured"), declaredValue(value)
{
    std::cout << ColourHelper::GREEN << unit->getType() << "(#" << unit->getID() << ") is now insured with a declared value of R" << value << "." << ColourHelper::RESET << std::endl;
}

void Insured::process()
{
    std::cout << ColourHelper::GREEN << component->getType() << "(#" << getID() << ") has a declared liability coverage of R" << declaredValue << "." << ColourHelper::GREEN << std::endl;
    ShipmentType::process();
}

double Insured::estimateShippingCost()
{
    double premium = declaredValue * 0.025;
    return ShipmentType::estimateShippingCost() + premium;
}