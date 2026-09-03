#ifndef SHIPPINGSTATE_H
#define SHIPPINGSTATE_H

#include "Parcel.h"
class ShippingState
{
public:
	ShippingState();
	virtual ~ShippingState();
	virtual void handleProcess(Parcel *parcel) = 0;
	virtual bool dispatch(Parcel *parcel) = 0;
	virtual void placeOnHold(Parcel *parcel) = 0;
	virtual void releaseHold(Parcel *parcel) = 0;
	virtual string getStateName() = 0;
};

#endif
