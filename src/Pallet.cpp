#include "../import/Pallet.h"

Pallet::Pallet(int id, double maxCapacity) : CargoGroup(id), maxCapacity(maxCapacity)
{
}

Pallet::~Pallet()
{
}