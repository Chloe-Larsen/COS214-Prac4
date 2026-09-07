#ifndef SHIPMENTTYPE_H
#define SHIPMENTTYPE_H

#include "ShippingUnit.h"

class ShipmentType : public ShippingUnit
{
protected:
	ShippingUnit *component;

public:
	ShipmentType(ShippingUnit *unit, std::string type = "ShipmentType");
	virtual ~ShipmentType();
	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;

	// Decorator overides
	double getWeight() override;
	double estimateShippingCost() override;
	void process() override;
	ShippingUnit *getComponent();
};

#endif
