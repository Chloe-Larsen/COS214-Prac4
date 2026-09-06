#ifndef CUSTOMSAUDIT_H
#define CUSTOMSAUDIT_H

#include "Inspection.h"
#include "ShippingUnit.h"
#include <vector>

// Concrete Iterator: POST-ORDER traversal (children before parents) of the
// same structure. Same completeness as Manifest, different visiting order.
class CustomsAudit : public Inspection
{
private:
	ShippingUnit *root;
	std::vector<ShippingUnit *> list;
	int currentIndex;
	void populateList(ShippingUnit *unit);

public:
	CustomsAudit(ShippingUnit *root);
	~CustomsAudit();

	void first() override;
	void next() override;
	bool isDone() override;
	ShippingUnit *currentItem() override;
};

#endif
