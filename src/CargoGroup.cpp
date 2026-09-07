#include "../import/CargoGroup.h"
#include "../import/CargoGroup.h"
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

CargoGroup::CargoGroup(int id) : ShippingUnit(id)
{
}

CargoGroup::~CargoGroup()
{
    for (ShippingUnit *child : children)
    {
        delete child;
    }
}

void CargoGroup::add(ShippingUnit *unit)
{
    if (unit != nullptr)
    {
        children.push_back(unit);
    }
}

void CargoGroup::remove(ShippingUnit *unit)
{
    for (vector<ShippingUnit *>::iterator it = children.begin();
         it != children.end();
         ++it)
    {
        if (*it == unit)
        {
            children.erase(it);
            return;
        }
    }
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

int CargoGroup::getChildCount()
{
    return children.size();
}

ShippingUnit *CargoGroup::getChildAt(int index)
{
    if (index < 0 || index >= static_cast<int>(children.size()))
    {
        return nullptr;
    }

    return children[index];
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