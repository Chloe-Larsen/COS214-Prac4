#include "../import/InTransit.h"
#include "../import/Delivered.h"
#include "../import/CustomsHold.h"
#include "../import/Parcel.h"
#include <iostream>

InTransit::InTransit() : ShippingState()
{
}

void InTransit::handleProcess(Parcel *parcel)
{
    parcel->setState(new Delivered());
}

bool InTransit::dispatch(Parcel *parcel)
{
    std::cout << "Parcel is already in transit." << std::endl;
    return false;
}

void InTransit::placeOnHold(Parcel *parcel)
{
    parcel->setState(new CustomsHold());
}

void InTransit::releaseHold(Parcel *parcel)
{
    std::cout << "Parcel is not on customs hold." << std::endl;
}

std::string InTransit::getStateName()
{
    return "In Transit";
}