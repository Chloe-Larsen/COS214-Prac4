#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "ShipmentType.h"
#include "ShippingUnit.h"

class Refrigerated : public ShipmentType
{
private:
	double targetTemp;

public:
	Refrigerated(ShippingUnit *unit);
	~Refrigerated();
	void logTemperatureTelemetry();
	void process() override;
	double estimateShippingCost() override;
};

#endif
