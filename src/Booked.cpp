#include "../import/Booked.h"
#include "../import/InTransit.h"
#include "../import/Parcel.h"
#include <iostream>

Booked::Booked() : ShippingState()
{
}
void Booked::handleProcess(Parcel *parcel)
{
    std::cout << "Parcel must be dispatched before it can be processed." << std::endl;
}

bool Booked::dispatch(Parcel *parcel)
{
    parcel->setState(new InTransit());
    return true;
}

void Booked::placeOnHold(Parcel *parcel)
{
    std::cout << "Parcel cannot be placed on customs hold before dispatch." << std::endl;
}

void Booked::releaseHold(Parcel *parcel)
{
    std::cout << "Parcel is not on customs hold." << std::endl;
}

std::string Booked::getStateName()
{
    return "Booked";
}