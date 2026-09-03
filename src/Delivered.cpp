#include "../import/Delivered.h"

Delivered::Delivered() : ShippingState()
{
}
void Delivered::handleProcess(Parcel *parcel)
{
}

bool Delivered::dispatch(Parcel *parcel)
{
}

void Delivered::placeOnHold(Parcel *parcel)
{
}

void Delivered::releaseHold(Parcel *parcel)
{
}

string Delivered::getStateName()
{
}