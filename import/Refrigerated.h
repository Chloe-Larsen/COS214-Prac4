#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "ShipmentType.h"
#include "ShippingUnit.h"

class Refrigerated : public ShipmentType
{
private:
	double targertTemp;

public:
	Refrigerated(ShippingUnit *unit);
	void logTemperatureTelemetry();
	void process() override;
};

#endif
