#include "../import/Hazmat.h"

Hazmat::Hazmat(ShippingUnit *unit, string code, bool isPlacarded) : ShipmentType(unit), hazmatClass(code), placarded(isPlacarded)
{
}

bool Hazmat::verifyPlacarding()
{
}

void Hazmat::process()
{
}
