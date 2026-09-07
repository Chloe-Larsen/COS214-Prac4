#include "../import/ShipmentType.h"

ShipmentType::ShipmentType(ShippingUnit *unit) : ShippingUnit(unit->getID(), unit->getType()), component(unit)
{
}

ShipmentType::~ShipmentType()
{
    if (component != nullptr)
    {
        delete component;
        component = nullptr;
    }
}

double ShipmentType::getWeight()
{
    return component ? component->getWeight() : 0.0;
}

double ShipmentType::estimateShippingCost()
{
    return component ? component->estimateShippingCost() : 0.0;
}

void ShipmentType::process()
{
    if (component)
    {
        component->process();
    }
}

Inspection *ShipmentType::createManifest()
{
    return component ? component->createManifest() : nullptr;
}

Inspection *ShipmentType::createCustomsAudit()
{
    return component ? component->createCustomsAudit() : nullptr;
}

ShippingUnit *ShipmentType::getComponent()
{
    return component;
}