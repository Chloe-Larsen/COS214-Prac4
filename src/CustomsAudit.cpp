#include "../import/CustomsAudit.h"
#include "../import/CargoGroup.h"

CustomsAudit::CustomsAudit(ShippingUnit *root) : root(root), currentIndex(0)
{
	populateList(this->root); // snapshot the structure NOW
}

CustomsAudit::~CustomsAudit() {}

// Post-order: visit the children first, then the node itself.
void CustomsAudit::populateList(ShippingUnit *unit)
{
	if (unit == nullptr)
		return;
	CargoGroup *group = dynamic_cast<CargoGroup *>(unit);
	if (group != nullptr)
		for (ShippingUnit *child : group->children)
			populateList(child);
	list.push_back(unit);
}

void CustomsAudit::first() { currentIndex = 0; }
void CustomsAudit::next() { currentIndex++; }
bool CustomsAudit::isDone() { return currentIndex >= static_cast<int>(list.size()); }
ShippingUnit *CustomsAudit::currentItem() { return isDone() ? nullptr : list[currentIndex]; }
