#include "../import/Pallet.h"

Pallet::Pallet(int id, double maxCapacity) : CargoGroup(id, "Pallet"), maxCapacity(maxCapacity)
{
    std::cout << ColourHelper::YELLOW << "Pallet (#" << id << ") has been created it has a max capacity of " << maxCapacity << "kg" << ColourHelper::RESET << std::endl;
}

Pallet::~Pallet()
{
}

void Pallet::add(ShippingUnit *unit)
{
    if (!unit)
        return;
    if (this->getWeight() + unit->getWeight() > maxCapacity)
    {
        std::cout << ColourHelper::YELLOW << "Cannot add unit #" << unit->getID() << " to Pallet #" << getID() << ": Exceeds max capacity of " << maxCapacity << " kg." << ColourHelper::RESET << std::endl;
        return;
    }
    CargoGroup::add(unit);
}