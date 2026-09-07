#include "../import/Hazmat.h"
#include <iostream>


Hazmat::Hazmat(ShippingUnit *unit, string code, bool isPlacarded) : ShipmentType(unit), hazmatClass(code), placarded(isPlacarded)
{
}

bool Hazmat::verifyPlacarding()
{
    std::cout << "Hazardous material placarding verified." << std::endl;
    return true;
}

void Hazmat::process()
{
    ShipmentType::process();
    verifyPlacarding();
}
