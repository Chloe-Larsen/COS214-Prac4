#include "../import/Manifest.h"
#include "../import/CargoGroup.h"
#include "../import/ShipmentType.h"

Manifest::Manifest(ShippingUnit *root) : Inspection(), root(root), currentIndex(0)
{
    first();
}

void Manifest::populateList(ShippingUnit *unit)
{
    if (!unit)
        return;
    list.push_back(unit);

    CargoGroup *group = dynamic_cast<CargoGroup *>(unit);
    if (group)
    {
        for (ShippingUnit *child : group->getChildren())
        {
            populateList(child);
        }
        return;
    }

    ShipmentType *decorator = dynamic_cast<ShipmentType *>(unit);
    if (decorator)
    {
        populateList(decorator->getComponent());
    }
}

Manifest::~Manifest()
{
    list.clear();
}

void Manifest::first()
{
    list.clear();
    populateList(root);
    currentIndex = 0;
}

void Manifest::next()
{
    if (!isDone())
    {
        ++currentIndex;
    }
}

bool Manifest::isDone()
{
    return currentIndex >= list.size();
}

ShippingUnit *Manifest::currentItem()
{
    if (isDone())
    {
        return nullptr;
    }
    return list[currentIndex];
}
