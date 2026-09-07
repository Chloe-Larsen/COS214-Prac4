#include "../import/Freight.h"

Freight::Freight(int id, int shipId, std::string shipName) : CargoGroup(id, "Freight"), shipId(shipId), shipName(shipName)
{
    std::cout << ColourHelper::YELLOW << "Freight (#" << id << ") was created. The ships is called " << shipName << " with an id of " << shipId << "." << ColourHelper::RESET << std::endl;
}

Freight::~Freight()
{
}