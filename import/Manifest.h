#ifndef MANIFEST_H
#define MANIFEST_H

#include "Inspection.h"
#include "ShippingUnit.h"
#include <vector>

// Concrete Iterator: PRE-ORDER traversal of the whole structure.
class Manifest : public Inspection
{
private:
	ShippingUnit *root;
	std::vector<ShippingUnit *> list;
	int currentIndex;
	void populateList(ShippingUnit *unit);

public:
	Manifest(ShippingUnit *rootNode);
	~Manifest();

	void first() override;
	void next() override;
	bool isDone() override;
	ShippingUnit *currentItem() override;
};

#endif
