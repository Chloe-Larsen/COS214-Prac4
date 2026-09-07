#include "../import/CustomsHold.h"
#include "../import/ClearedCustoms.h"
#include "../import/Parcel.h"
#include <iostream>

CustomsHold::CustomsHold() : ShippingState()
{
}
void CustomsHold::handleProcess(Parcel *parcel)
{
    std::cout << "Parcel cannot be processed while on customs hold." << std::endl;
}

bool CustomsHold::dispatch(Parcel *parcel)
{
    std::cout << "Parcel cannot be dispatched while on customs hold." << std::endl;
    return false;
}

void CustomsHold::placeOnHold(Parcel *parcel)
{
    std::cout << "Parcel is already on customs hold." << std::endl;
}

void CustomsHold::releaseHold(Parcel *parcel)
{
    parcel->setState(new ClearedCustoms());
}

std::string CustomsHold::getStateName()
{
    return "Customs Hold";
}