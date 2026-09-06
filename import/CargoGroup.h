#ifndef CARGOGROUP_H
#define CARGOGROUP_H

#include "ShippingUnit.h"
#include <vector>

// Composite
class CargoGroup : public ShippingUnit
{
protected:
	std::vector<ShippingUnit *> children;

	// Concrete iterators are granted access to the internal child list
	// so the hierarchy is never exposed to client (main.cpp) code.
	friend class Manifest;
	friend class CustomsAudit;

public:
	CargoGroup(int id);
	virtual ~CargoGroup();

	void add(ShippingUnit *unit);
	void remove(ShippingUnit *unit);
	ShippingUnit *getChild(int id);

	double getWeight() override;
	double estimateShippingCost() override;
	void process() override;

	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;
};

#endif
