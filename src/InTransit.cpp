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
    if (parcel)
    {
        parcel->setState(new Delivered());
    }
    std::cout << ColourHelper::B_YELLOW << "State: InTransit " << ColourHelper::RESET << " -> " << ColourHelper::B_MAGENTA << "Delivered " << ColourHelper::RESET << "\nFinalizing delivery for unit #" << parcel->getID() << "." << std::endl;
}

bool InTransit::dispatch(Parcel *parcel)
{
    std::cout << ColourHelper::B_YELLOW << "State: InTransit " << ColourHelper::RESET << "\nUnit (#" << parcel->getID() << ") is already in transit." << std::endl;
    return false;
}

void InTransit::placeOnHold(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new CustomsHold());
    }
    std::cout << ColourHelper::B_YELLOW << "State: InTransit " << ColourHelper::RESET << " -> " << ColourHelper::B_BLUE << "CustomsHold " << ColourHelper::RESET << "\nUnit (#" << parcel->getID() << ") was intercepted by border authorities. Placing on hold!" << std::endl;
}

void InTransit::releaseHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_YELLOW << "State: InTransit "  << ColourHelper::RESET  << "\nUnit (#" << parcel->getID() << ") is not on hold." << std::endl;
}

std::string InTransit::getStateName()
{
    return "InTransit";
}