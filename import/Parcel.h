#ifndef PARCEL_H
#define PARCEL_H

#include "ShippingUnit.h"

class ShippingState; // forward declaration breaks the Parcel<->ShippingState cycle

// Leaf (also the Context for the State pattern)
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
	void process() override;

	// Iterator
	Inspection *createManifest() override;
	Inspection *createCustomsAudit() override;

	// State pattern
	void setState(ShippingState *newState);
	std::string getStateName();
	bool dispatch();
	void flagCustomsHold();
	void releaseCustomsHold();
};

#endif
