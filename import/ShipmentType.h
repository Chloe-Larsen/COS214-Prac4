#ifndef SHIPMENTTYPE_H
#define SHIPMENTTYPE_H

#include "ShippingUnit.h"

// Decorator base: wraps a ShippingUnit and forwards every operation to it.
class ShipmentType : public ShippingUnit
{
protected:
	ShippingUnit *component; // owned by the decorator

public:
	ShipmentType(ShippingUnit *unit);
	virtual ~ShipmentType();

	int getID() override;
	double getWeight() override;
	double estimateShippingCost() override;
	void process() override;
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;
};

#endif
