#ifndef SHIPMENTTYPE_H
#define SHIPMENTTYPE_H

#include "ShippingUnit.h"

class ShipmentType : public ShippingUnit
{
protected:
	ShippingUnit *component;
public:
	ShipmentType(ShippingUnit *unit);
	virtual ~ShipmentType();
	//Iterator
	Inspection* createManifest() override;
	Inspection* createCustomsAudit() override;
};

#endif
