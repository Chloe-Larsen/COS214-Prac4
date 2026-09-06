#ifndef INTRANSIT_H
#define INTRANSIT_H

#include "ShippingState.h"

class InTransit : public ShippingState
{
public:
	InTransit();
	void handleProcess(Parcel *parcel) override;
	bool dispatch(Parcel *parcel) override;
	void placeOnHold(Parcel *parcel) override;
	void releaseHold(Parcel *parcel) override;
	std::string getStateName() override;
};

#endif
