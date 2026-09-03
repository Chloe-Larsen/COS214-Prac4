#ifndef PALLET_H
#define PALLET_H

#include "CargoGroup.h"
class Pallet : public CargoGroup
{
private:
	double maxCapacity;

public:
	Pallet(int id, double maxCapacity);
	~Pallet();
};

#endif