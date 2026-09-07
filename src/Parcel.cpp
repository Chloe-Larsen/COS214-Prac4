#include "../import/Parcel.h"
#include "../import/Booked.h"
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

Parcel::Parcel(int id, double weight) : ShippingUnit(id, "Parcel"), weight(weight)
{
    std::cout << ColourHelper::YELLOW << "Parcel (#" << id << ") has been created. It has a weight of " << weight << "kg" << ColourHelper::RESET << std::endl;
    state = new Booked();
}

Parcel::~Parcel()
{
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
    }
}

void Parcel::setState(ShippingState *newState)
{
    if (state == nullptr)
        return;
    delete this->state;
    this->state = newState;
}

ShippingState *Parcel::getState()
{
    return state;
}

bool Parcel::dispatch()
{
    if (state)
    {
        return state->dispatch(this);
    }
    return false;
}

void Parcel::flagCustomsHold()
{
    if (state)
    {
        state->placeOnHold(this);
    }
}

void Parcel::releaseCustomsHold()
{
    if (state)
    {
        state->releaseHold(this);
    }
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

void Parcel::process()
{
    std::cout << ColourHelper::YELLOW << "Parcel #" << this->getID() << " has a weight of " << weight << "kg" << ColourHelper::RESET << std::endl;
    if (state)
    {
        state->handleProcess(this);
    }
}