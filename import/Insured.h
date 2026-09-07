#ifndef INSURED_H
#define INSURED_H

#include "ShipmentType.h"

class Insured : public ShipmentType
{
private:
	double declaredValue;

public:
	Insured(ShippingUnit *unit, double value);
	void process() override;
	double estimateShippingCost() override;
};

#endif
