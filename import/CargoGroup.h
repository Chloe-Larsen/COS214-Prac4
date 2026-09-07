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
	virtual void add(ShippingUnit *unit);
	void remove(ShippingUnit *unit);
	ShippingUnit *getChild(int id);
	vector<ShippingUnit *> getChildren();	

	// Composite
	double getWeight() override;
	double estimateShippingCost() override;

	void process() override;

	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;
};

#endif
