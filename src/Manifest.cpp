#include "../import/Manifest.h"
#include "../import/CargoGroup.h"

Manifest::Manifest(ShippingUnit *rootNode) : root(rootNode), currentIndex(0)
{
	populateList(root); // snapshot the structure NOW
}

Manifest::~Manifest() {}

// Pre-order: visit the node, then its children.
void Manifest::populateList(ShippingUnit *unit)
{
	if (unit == nullptr)
		return;
	list.push_back(unit);
	CargoGroup *group = dynamic_cast<CargoGroup *>(unit);
	if (group != nullptr)
		for (ShippingUnit *child : group->children)
			populateList(child);
}

void Manifest::first() { currentIndex = 0; }
void Manifest::next() { currentIndex++; }
bool Manifest::isDone() { return currentIndex >= static_cast<int>(list.size()); }
ShippingUnit *Manifest::currentItem() { return isDone() ? nullptr : list[currentIndex]; }
