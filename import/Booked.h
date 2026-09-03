#ifndef BOOKED_H
#define BOOKED_H

#include "ShippingState.h"

class Booked : public ShippingState
{
public:
    Booked();
    void handleProcess(Parcel *parcel) override;
    bool dispatch(Parcel *parcel) override;
    void placeOnHold(Parcel *parcel) override;
    void releaseHold(Parcel *parcel) override;
    string getStateName() override;
};

#endif
