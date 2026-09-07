#include "../import/Delivered.h"
#include <iostream>

Delivered::Delivered() : ShippingState()
{
}
void Delivered::handleProcess(Parcel *parcel)
{
    std::cout << "Parcel has already been delivered." << std::endl;
}

bool Delivered::dispatch(Parcel *parcel)
{
    std::cout << "Delivered parcel cannot be dispatched again." << std::endl;
    return false;
}

void Delivered::placeOnHold(Parcel *parcel)
{
    std::cout << "Delivered parcel cannot be placed on customs hold." << std::endl;
}

void Delivered::releaseHold(Parcel *parcel)
{
    std::cout << "Delivered parcel is not on customs hold." << std::endl;
}

std::string Delivered::getStateName()
{
    return "Delivered";
}