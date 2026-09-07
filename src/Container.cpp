#include "../import/Container.h"

Container::Container(int id, int containerId) : CargoGroup(id, "Container"), containerId(containerId)
{
    std::cout << ColourHelper::YELLOW << "Container (#" << id << ") with the containerId of " << containerId << " has been created." << ColourHelper::RESET << std::endl;
}

Container::~Container()
{
}