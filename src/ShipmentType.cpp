#include "../import/ShipmentType.h"

ShipmentType::ShipmentType(ShippingUnit *unit)
{
    component = unit;
}

ShipmentType::~ShipmentType()
{
    delete component;
}

double ShipmentType::getWeight()
{
    return component->getWeight();
}

double ShipmentType::estimateShippingCost()
{
    return component->estimateShippingCost();
}

void ShipmentType::process()
{
    component->process();
}

Inspection *ShipmentType::createManifest()
{
    return component->createManifest();
}

Inspection *ShipmentType::createCustomsAudit()
{
    return component->createCustomsAudit();
}