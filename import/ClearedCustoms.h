#ifndef CLEAREDCUSTOMS_H
#define CLEAREDCUSTOMS_H

#include "ShippingState.h"
#include "InTransit.h"
#include "CustomsHold.h"

class ClearedCustoms : public ShippingState
{
    public:
    ClearedCustoms();
        void handleProcess(Parcel *parcel) override;
        bool dispatch(Parcel *parcel) override;
        void placeOnHold(Parcel *parcel) override;
        void releaseHold(Parcel *parcel) override;
        std::string getStateName() override;
};

#endif
