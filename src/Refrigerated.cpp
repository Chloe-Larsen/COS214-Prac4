#include "../import/Refrigerated.h"
#include <iostream>

Refrigerated::Refrigerated(ShippingUnit *unit, double temp) : ShipmentType(unit, "Refrigerated"), targetTemp(temp)
{
    std::cout << ColourHelper::GREEN << unit->getType() << "(#" << unit->getID() << ") is now refrigerated at a target temperature of " << temp << "°C." << ColourHelper::RESET << std::endl;
}

Refrigerated::~Refrigerated()
{
}

void Refrigerated::logTemperatureTelemetry()
{
    std::cout << ColourHelper::GREEN << "refrigerated " << component->getType() << " Unit #" << component->getID() << " maintaining climate at " << targetTemp << "°C." << ColourHelper::RESET << std::endl;
}

void Refrigerated::process()
{
    logTemperatureTelemetry();
    ShipmentType::process();
}

double Refrigerated::estimateShippingCost()
{
    return ShipmentType::estimateShippingCost() + 75.0;
}