#ifndef MANIFEST_H
#define MANIFEST_H

#include "Inspection.h"
#include "ShippingUnit.h"

class Manifest : public Inspection
{
private:
	ShippingUnit *root;
	vector<ShippingUnit *> list;
	size_t currentIndex;
	void populateList(ShippingUnit *unit);

public:
	Manifest(ShippingUnit *root);
	~Manifest();

	void first() override;
	void next() override;
	bool isDone() override;
	ShippingUnit *currentItem() override;
};

#endif
