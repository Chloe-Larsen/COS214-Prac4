#include "../import/ShipmentType.h"

// A decorator OWNS the component it wraps.
ShipmentType::ShipmentType(ShippingUnit *unit)
	: ShippingUnit(unit ? unit->getID() : 0), component(unit) {}

ShipmentType::~ShipmentType() { delete component; }

int ShipmentType::getID() { return component ? component->getID() : id; }
double ShipmentType::getWeight() { return component ? component->getWeight() : 0.0; }
double ShipmentType::estimateShippingCost() { return component ? component->estimateShippingCost() : 0.0; }
void ShipmentType::process() { if (component) component->process(); }
Inspection *ShipmentType::createManifest() { return component ? component->createManifest() : nullptr; }
Inspection *ShipmentType::createCustomsAudit() { return component ? component->createCustomsAudit() : nullptr; }
