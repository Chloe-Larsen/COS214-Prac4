#include "../import/Parcel.h"
#include "../import/Booked.h"
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

Parcel::Parcel(int id, double weight) : ShippingUnit(id), weight(weight)
{
    state = new Booked();
}

Parcel::~Parcel()
{
    delete state;
}

void Parcel::setState(ShippingState *newState)
{
    delete state;
    state = newState;
}

void Parcel::handleProcess()
{
    state->handleProcess(this);
}

bool Parcel::dispatch()
{
    return state->dispatch(this);
}

void Parcel::flagCustomsHold()
{
    state->placeOnHold(this);
}

void Parcel::releaseCustomsHold()
{
    state->releaseHold(this);
}

double Parcel::getWeight()
{
    return weight;
}

double Parcel::estimateShippingCost()
{
    return weight * 10.0;
}

Inspection *Parcel::createManifest()
{
    return new Manifest(this);
}

Inspection *Parcel::createCustomsAudit()
{
    return new CustomsAudit(this);
}