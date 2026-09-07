#ifndef CUSTOMSHOLD_H
#define CUSTOMSHOLD_H

#include "ShippingState.h"
#include "ClearedCustoms.h"

class CustomsHold : public ShippingState
{
public:
    CustomsHold();
    void handleProcess(Parcel *parcel) override;
    bool dispatch(Parcel *parcel) override;
    void placeOnHold(Parcel *parcel) override;
    void releaseHold(Parcel *parcel) override;
    std::string getStateName() override;
};

#endif
