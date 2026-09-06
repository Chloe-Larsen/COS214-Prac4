#ifndef FREIGHT_H
#define FREIGHT_H

#include "CargoGroup.h"
#include <string>

class Freight : public CargoGroup
{
private:
	int shipId;
	std::string shipName;

public:
	Freight(int id, int shipId, std::string shipName);
	~Freight();
	std::string getShipName();
};

#endif
