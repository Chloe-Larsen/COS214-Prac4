#include "../import/Freight.h"

Freight::Freight(int id, int shipId, std::string shipName)
	: CargoGroup(id), shipId(shipId), shipName(shipName) {}
Freight::~Freight() {}
std::string Freight::getShipName() { return shipName; }
