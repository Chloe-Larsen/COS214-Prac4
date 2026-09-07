#include "../import/CargoGroup.h"
#include <algorithm>
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

CargoGroup::CargoGroup(int id, std::string type) : ShippingUnit(id, type)
{
}

CargoGroup::~CargoGroup()
{
    for (ShippingUnit *child : children)
        delete child;
    children.clear();
}

void CargoGroup::add(ShippingUnit *unit)
{
    if (unit != nullptr)
    {
        children.push_back(unit);
        std::cout << ColourHelper::YELLOW << "\t\t" << unit->getType() << "(id #" << unit->getID() << ") is now a part of " << this->getType() << "(id #" << this->getID() << ")" << ColourHelper::RESET << std::endl;
    }
}

void CargoGroup::remove(ShippingUnit *unit)
{
    children.erase(std::remove(children.begin(), children.end(), unit), children.end());
}

ShippingUnit *CargoGroup::getChild(int id)
{
    for (ShippingUnit *child : children)
    {
        if (child->getID() == id)
        {
            return child;
        }
    }
    return nullptr;
}

void CargoGroup::process()
{
    std::cout << ColourHelper::YELLOW << "CargoGroup #" << this->getID() << " (" << this->getType() << ") Processing " << children.size() << " contained units..." << ColourHelper::RESET << std::endl;
    for (ShippingUnit *child : children)
    {
        child->process();
    }
}

double CargoGroup::getWeight()
{
    double total = 0.0;

    for (ShippingUnit *child : children)
    {
        total += child->getWeight();
    }

    return total;
}

double CargoGroup::estimateShippingCost()
{
    double total = 0.0;

    for (ShippingUnit *child : children)
    {
        total += child->estimateShippingCost();
    }

    return total;
}

Inspection *CargoGroup::createManifest()
{
    return new Manifest(this);
}

Inspection *CargoGroup::createCustomsAudit()
{
    return new CustomsAudit(this);
}

std::vector<ShippingUnit *> CargoGroup::getChildren()
{
    return children;
}