#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "ShipmentType.h"

class Refrigerated : public ShipmentType
{
private:
	double targetTemp;

public:
	Refrigerated(ShippingUnit *unit, double targetTemp);
	void logTemperatureTelemetry();
	void process() override;
	double estimateShippingCost() override;
};

#endif
