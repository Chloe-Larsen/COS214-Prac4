#ifndef CLEAREDCUSTOMS_H
#define CLEAREDCUSTOMS_H

#include "ShippingState.h"

class ClearedCustoms : public ShippingState
{
    ClearedCustoms();
    void handleProcess(Parcel *parcel) override;
    bool dispatch(Parcel *parcel) override;
    void placeOnHold(Parcel *parcel) override;
    void releaseHold(Parcel *parcel) override;
    string getStateName() override;
};

#endif
