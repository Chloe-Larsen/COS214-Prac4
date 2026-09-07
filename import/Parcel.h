#ifndef PARCEL_H
#define PARCEL_H

#include "ShippingUnit.h"
#include "ShippingState.h"

class Parcel : public ShippingUnit
{
private:
	ShippingState *state;
	double weight;

public:
	Parcel(int id, double weight);
	~Parcel();

	// Composite
	double getWeight() override;
	double estimateShippingCost() override;

	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;		

	void process() override;

	// State Pattern	
	void setState(ShippingState *newState);
	ShippingState* getState();
	bool dispatch();
	void flagCustomsHold();
	void releaseCustomsHold();
};

#endif
