#include "../import/InTransit.h"

InTransit::InTransit() : ShippingState()
{
}
void InTransit::handleProcess(Parcel *parcel)
{
}

bool InTransit::dispatch(Parcel *parcel)
{
}

void InTransit::placeOnHold(Parcel *parcel)
{
}

void InTransit::releaseHold(Parcel *parcel)
{
}

string InTransit::getStateName()
{
}