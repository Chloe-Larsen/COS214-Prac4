#include "../import/CustomsHold.h"
#include "../import/ClearedCustoms.h"
#include "../import/Parcel.h"
#include <iostream>

CustomsHold::CustomsHold() : ShippingState()
{
}
void CustomsHold::handleProcess(Parcel *parcel)
{
    std::cout << ColourHelper::B_BLUE << "State: CustomsHold " << ColourHelper::RESET << "\nUnit #" << parcel->getID() << " is locked in customs hold. Inspection required." << std::endl;
}

bool CustomsHold::dispatch(Parcel *parcel)
{
    std::cout << ColourHelper::B_BLUE << "State: CustomsHold " << ColourHelper::RESET << "\nCannot dispatch unit #" << parcel->getID() << " currently on customs hold." << std::endl;
    return false;
}

void CustomsHold::placeOnHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_BLUE << "State: CustomsHold " << ColourHelper::RESET << "\nUnit #" << parcel->getID() << " currently on customs hold." << std::endl;
}

void CustomsHold::releaseHold(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new ClearedCustoms());
    }
    std::cout << ColourHelper::B_BLUE << "State: CustomsHold " << ColourHelper::RESET << " -> " << ColourHelper::B_RED << "ClearedCustoms " << ColourHelper::RESET << "\nCustoms clearance granted for unit #" << parcel->getID() << ". Hold released." << std::endl;
}

std::string CustomsHold::getStateName()
{
    return "CustomsHold";
}