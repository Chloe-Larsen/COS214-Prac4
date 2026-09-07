#include "../import/Hazmat.h"
#include "../import/Parcel.h"
#include <algorithm>

Hazmat::Hazmat(ShippingUnit *unit, string code, bool isPlacarded) : ShipmentType(unit, "Hazmat"), hazmatClass(code), placarded(isPlacarded)
{
    validHazmatCodes.push_back("UN1993");
    validHazmatCodes.push_back("UN1203");
    validHazmatCodes.push_back("UN2794");
    validHazmatCodes.push_back("UN1075");
    validHazmatCodes.push_back("UN3480");
    std::cout << ColourHelper::GREEN << unit->getType() << "(#" << unit->getID() << ") is now placarded to be of hazmat class of " << code << "." << ColourHelper::RESET << std::endl;
}

bool Hazmat::verifyPlacarding()
{
    bool codeFound = std::find(validHazmatCodes.begin(), validHazmatCodes.end(), hazmatClass) != validHazmatCodes.end();
    return codeFound && placarded;
}

void Hazmat::process()
{
    std::cout << ColourHelper::GREEN << "Hazmat inspecting placarding for " << component->getType() << " unit #" << getID() << " (Code: " << hazmatClass << ")" << ColourHelper::RESET << std::endl;

    if (!verifyPlacarding())
    {
        std::cout << ColourHelper::GREEN << "  --> REJECTED: Unit #" << component->getID() << " failed placarding verification! Flagging customs hold." << ColourHelper::RESET << std::endl;
        ShippingUnit *curr = component;
        while (curr)
        {
            Parcel *parcel = dynamic_cast<Parcel *>(curr);
            if (parcel)
            {
                parcel->flagCustomsHold();
                break;
            }
            ShipmentType *dec = dynamic_cast<ShipmentType *>(curr);
            curr = dec ? dec->getComponent() : nullptr;
        }
    }
    else
    {
        std::cout << ColourHelper::GREEN << "  --> PASSED: Placard verified for UN Class " << hazmatClass << "." << ColourHelper::RESET << std::endl;
    }

    ShipmentType::process();
}

double Hazmat::estimateShippingCost()
{
    return ShipmentType::estimateShippingCost() + 150.0;
}