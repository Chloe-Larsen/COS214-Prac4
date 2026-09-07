#ifndef SHIPPINGUNIT_H
#define SHIPPINGUNIT_H

#include <iostream>
#include <string>
#include <vector>

#include "Inspection.h"
#include "ColourHelper.h"

using namespace std;

class ShippingUnit
{
private:
	int id;
	std::string type;

public:
	ShippingUnit(int id, std::string type);
	ShippingUnit();
	virtual ~ShippingUnit();
	int getID();
	std::string getType();

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
