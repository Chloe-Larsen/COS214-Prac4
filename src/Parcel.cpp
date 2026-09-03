#include "../import/Parcel.h"

Parcel::Parcel(int id, double weight) : ShippingUnit(id), weight(weight)
{
}

Parcel::~Parcel()
{
}

void Parcel::setState()
{
}

bool Parcel::dispatch()
{
}

void Parcel::flagCustomsHold()
{
}

void Parcel::releaseCustomsHold()
{
}

double Parcel::getWeight()
{
}

double Parcel::estimateShippingCost()
{
}

Inspection *Parcel::createManifest()
{
}

Inspection *Parcel::createCustomsAudit()
{
}