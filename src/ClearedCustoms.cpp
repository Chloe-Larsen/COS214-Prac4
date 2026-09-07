#include "../import/ClearedCustoms.h"
#include "../import/Parcel.h"

ClearedCustoms::ClearedCustoms()
{
}

void ClearedCustoms::handleProcess(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new InTransit());
    }
    std::cout << ColourHelper::B_RED << "State: ClearedCustoms " << ColourHelper::RESET << "\nInspection passed. Unit #" << parcel->getID() << " can now resume transit" << std::endl;
}

bool ClearedCustoms::dispatch(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new InTransit());
    }
    std::cout << ColourHelper::B_RED << "State: ClearedCustoms " << ColourHelper::RESET << " -> " << ColourHelper::B_YELLOW << "InTransit " << ColourHelper::RESET << "\nDispatching unit #" << parcel->getID() << " back to transit." << std::endl;
    return true;
}

void ClearedCustoms::placeOnHold(Parcel *parcel)
{
    if (parcel)
    {
        parcel->setState(new CustomsHold());
    }
    std::cout << ColourHelper::B_RED << "State: ClearedCustoms " << ColourHelper::RESET << " -> " << ColourHelper::B_RED << "CustomsHold  " << ColourHelper::RESET << "\nUnit #" << parcel->getID() << " re-flagged for customs hold." << std::endl;
}

void ClearedCustoms::releaseHold(Parcel *parcel)
{
    std::cout << ColourHelper::B_RED << "State: ClearedCustoms " << ColourHelper::RESET << "\n Unit #" << parcel->getID() << " hold already released; customs is clear." << std::endl;
}

std::string ClearedCustoms::getStateName()
{
    return "ClearedCustoms";
}