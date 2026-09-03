#include "../import/Insured.h"

Insured::Insured(ShippingUnit *unit, double value) : ShipmentType(unit), declaredValue(value)
{
}

void Insured::process()
{
}