#include "../import/CargoGroup.h"
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

CargoGroup::CargoGroup(int id) : ShippingUnit(id) {}

// A group OWNS its children: destroying it destroys everything beneath it.
CargoGroup::~CargoGroup()
{
	for (ShippingUnit *child : children)
		delete child;
	children.clear();
}

void CargoGroup::add(ShippingUnit *unit)
{
	if (unit != nullptr)
		children.push_back(unit);
}

// remove() only DETACHES the unit (ownership passes back to the caller);
// it does not delete, so a unit can be safely moved between groups.
void CargoGroup::remove(ShippingUnit *unit)
{
	for (std::vector<ShippingUnit *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (*it == unit)
		{
			children.erase(it);
			return;
		}
	}
}

ShippingUnit *CargoGroup::getChild(int id)
{
	for (ShippingUnit *child : children)
		if (child->getID() == id)
			return child;
	return nullptr;
}

double CargoGroup::getWeight()
{
	double total = 0.0;
	for (ShippingUnit *child : children)
		total += child->getWeight();
	return total;
}

double CargoGroup::estimateShippingCost()
{
	double total = 0.0;
	for (ShippingUnit *child : children)
		total += child->estimateShippingCost();
	return total;
}

void CargoGroup::process()
{
	for (ShippingUnit *child : children)
		child->process();
}

Inspection *CargoGroup::createManifest() { return new Manifest(this); }
Inspection *CargoGroup::createCustomsAudit() { return new CustomsAudit(this); }
