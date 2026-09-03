#ifndef FREIGHT_H
#define FREIGHT_H
#include "CargoGroup.h"

class Freight : public CargoGroup
{
private:
	int shipId;
	string shipName;

public:
	Freight(int id, int shipId, string shipName);
	~Freight();
};

#endif
