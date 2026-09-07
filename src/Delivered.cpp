#include "../import/Delivered.h"

Delivered::Delivered() : ShippingState()
{
}

void Delivered::handleProcess(Parcel *parcel)
{
    std::cout << ColourHelper::B_MAGENTA << "State: Delivered " << ColourHelper::RESET << "\nUnit #" << parcel->getID() << " has reached its destination. Lifecycle complete." << std::endl;
}

bool Delivered::dispatch(Parcel *parcel)
{
    std::cout << ColourHelper::B_MAGENTA << "State: Delivered " << ColourHelper::RESET << "\nCannot dispatch unit #" << parcel->getID() << " is already delivered." << std::endl;
    return false;
}

void Delivered::placeOnHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_MAGENTA << "State: Delivered " << ColourHelper::RESET << "\nCannot place unit #" << parcel->getID() << "on a customs hold, it is already delivered." << std::endl;
}

void Delivered::releaseHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_MAGENTA << "State: Delivered " << ColourHelper::RESET << "\nCannot release hold on unit #" << parcel->getID() << " it is already delivered." << std::endl;
}

std::string Delivered::getStateName()
{
    return "Delivered";
}