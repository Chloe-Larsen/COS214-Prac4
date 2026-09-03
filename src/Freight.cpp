#include "../import/Freight.h"

Freight::Freight(int id, int shipId, string shipName) : CargoGroup(id), shipId(shipId), shipName(shipName){

}

Freight::~Freight()
{}