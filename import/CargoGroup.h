#ifndef CARGOGROUP_H
#define CARGOGROUP_H

#include "ShippingUnit.h"

class CargoGroup : public ShippingUnit
{
private:
	vector<ShippingUnit *> children;

public:
	CargoGroup(int id);
	virtual ~CargoGroup();
	void add(ShippingUnit *unit);
	void remove(ShippingUnit *unit);
	ShippingUnit *getChild(int id);

	// Composite
	double getWeight() override;
	double estimateShippingCost() override;

	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;
};

#endif
