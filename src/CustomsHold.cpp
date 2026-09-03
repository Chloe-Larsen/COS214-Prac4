#include "../import/CustomsHold.h"

CustomsHold::CustomsHold() : ShippingState()
{
}
void CustomsHold::handleProcess(Parcel *parcel)
{
}

bool CustomsHold::dispatch(Parcel *parcel)
{
}

void CustomsHold::placeOnHold(Parcel *parcel)
{
}

void CustomsHold::releaseHold(Parcel *parcel)
{
}

string CustomsHold::getStateName()
{
}