#ifndef SHIPPINGUNIT_H
#define SHIPPINGUNIT_H

#include <string>

class Inspection; // forward declaration breaks the ShippingUnit<->Inspection include cycle

class ShippingUnit
{
protected:
	int id;

public:
	ShippingUnit(int id);
	ShippingUnit();
	virtual ~ShippingUnit();
	virtual int getID();

	// Composite pattern
	virtual double getWeight() = 0;
	virtual double estimateShippingCost() = 0;

	// Behaviour hook (used by Decorator + State)
	virtual void process() = 0;

	// Iterator pattern factory methods
	virtual Inspection *createManifest() = 0;
	virtual Inspection *createCustomsAudit() = 0;
};

#endif
