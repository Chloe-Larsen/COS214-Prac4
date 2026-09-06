#ifndef DELIVERED_H
#define DELIVERED_H

#include "ShippingState.h"

class Delivered : public ShippingState
{
public:
	Delivered();
	void handleProcess(Parcel *parcel) override;
	bool dispatch(Parcel *parcel) override;
	void placeOnHold(Parcel *parcel) override;
	void releaseHold(Parcel *parcel) override;
	std::string getStateName() override;
};

#endif
