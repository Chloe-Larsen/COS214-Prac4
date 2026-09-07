#include "../import/Refrigerated.h"
#include <iostream>

Refrigerated::Refrigerated(ShippingUnit *unit) : ShipmentType(unit), targetTemp(4.0)
{
}

void Refrigerated::logTemperatureTelemetry()
{
    std::cout << "Temperature telemetry logged at target temperature: " << targetTemp << " C" << std::endl;
}

void Refrigerated::process()
{
    ShipmentType::process();
    logTemperatureTelemetry();
}