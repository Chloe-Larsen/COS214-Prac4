#ifndef SHIPPINGSTATE_H
#define SHIPPINGSTATE_H

class Parcel;
#include <string>

class ShippingState
{
public:
	ShippingState();
	virtual ~ShippingState();
	virtual void handleProcess(Parcel *parcel) = 0;
	virtual bool dispatch(Parcel *parcel) = 0;
	virtual void placeOnHold(Parcel *parcel) = 0;
	virtual void releaseHold(Parcel *parcel) = 0;
	virtual std::string getStateName() = 0;
};

#endif
