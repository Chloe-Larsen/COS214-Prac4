#include "../import/Booked.h"
#include "../import/InTransit.h"
#include "../import/Parcel.h"
#include <iostream>

Booked::Booked() : ShippingState()
{
}
void Booked::handleProcess(Parcel *parcel)
{
    std::cout << ColourHelper::B_GREEN << "State: Booked. " << ColourHelper::RESET << "\nUnit(#" << parcel->getID() << ") registered in manifest. Ready to dispatch!" << std::endl;
}

bool Booked::dispatch(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new InTransit());
    }
    std::cout << ColourHelper::B_GREEN << "State: Booked. " << ColourHelper::RESET << "-> " << ColourHelper::B_YELLOW << "InTransit " << ColourHelper::RESET << "\nDispatching unit(#" << parcel->getID() << ") into transit." << std::endl;
    return true;
}

void Booked::placeOnHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_GREEN << "State: Booked. " << ColourHelper::RESET << "\nUnit(#" << parcel->getID() << ") is not in transit; cannot flag customs hold yet." << std::endl;
}

void Booked::releaseHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_GREEN << "State: Booked. " << ColourHelper::RESET << "\nUnit(#" << parcel->getID() << ") is not on hold." << std::endl;
}

std::string Booked::getStateName()
{
    return "Booked";
}