#ifndef CUSTOMSAUDIT_H
#define CUSTOMSAUDIT_H

#include "Inspection.h"
#include "ShippingUnit.h"
#include "ShippingState.h"

class CustomsAudit : public Inspection
{
private:
	ShippingUnit *root;
	std::vector<ShippingUnit *> list;
	size_t currentIndex;
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
