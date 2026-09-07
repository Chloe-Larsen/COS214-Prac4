#ifndef CARGOGROUP_H
#define CARGOGROUP_H

#include "ShippingUnit.h"

class CargoGroup : public ShippingUnit
{
private:
	std::vector<ShippingUnit *> children;

public:
	CargoGroup(int id, std::string type);
	virtual ~CargoGroup();
	virtual void add(ShippingUnit *unit);
	void remove(ShippingUnit *unit);
	ShippingUnit *getChild(int id);
	std::vector<ShippingUnit *> getChildren();	

	// Composite
	double getWeight() override;
	double estimateShippingCost() override;

	void process() override;

	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;
};

#endif
