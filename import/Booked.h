#ifndef BOOKED_H
#define BOOKED_H

#include "ShippingState.h"
#include "InTransit.h"

class Booked : public ShippingState
{
public:
    Booked();
    void handleProcess(Parcel *parcel) override;
    bool dispatch(Parcel *parcel) override;
    void placeOnHold(Parcel *parcel) override;
    void releaseHold(Parcel *parcel) override;
    std::string getStateName() override;
};

#endif
