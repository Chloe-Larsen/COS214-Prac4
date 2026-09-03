#include "../import/Booked.h"

Booked::Booked() : ShippingState()
{
}
void Booked::handleProcess(Parcel *parcel)
{
}

bool Booked::dispatch(Parcel *parcel)
{
}

void Booked::placeOnHold(Parcel *parcel)
{
}

void Booked::releaseHold(Parcel *parcel)
{
}

string Booked::getStateName()
{
}