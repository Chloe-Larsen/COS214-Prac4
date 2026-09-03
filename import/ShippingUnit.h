#ifndef SHIPPINGUNIT_H
#define SHIPPINGUNIT_H

#include <iostream>
#include <string>
#include <vector>

#include "Inspection.h"

using namespace std;

class ShippingUnit
{
private:
	int id;

public:
	ShippingUnit(int id);
	ShippingUnit();
	virtual ~ShippingUnit();
	int getID();

	// Composite pattern
	virtual double getWeight() = 0;
	virtual double estimateShippingCost() = 0;

	// Decorator Pattern
	virtual void process() = 0;

	// Iterator Pattern
	virtual Inspection *createManifest() = 0;
	virtual Inspection *createCustomsAudit() = 0;
};

#endif
