#include "../import/Manifest.h"
#include "../import/CargoGroup.h"

Manifest::Manifest(ShippingUnit *rootNode) : Inspection()
{
    root = rootNode;
    currentIndex = 0;
    populateList(rootNode);
}

void Manifest::populateList(ShippingUnit *unit)
{
    if (unit == nullptr)
    {
        return;
    }

    list.push_back(unit);

    CargoGroup *group = dynamic_cast<CargoGroup *>(unit);

    if (group != nullptr)
    {
        for (int i = 0; i < group->getChildCount(); i++)
        {
            populateList(group->getChildAt(i));
        }
    }
}

Manifest::~Manifest()
{
}

void Manifest::first()
{
    currentIndex = 0;
}

void Manifest::next()
{
    if (!isDone())
    {
        currentIndex++;
    }
}

bool Manifest::isDone()
{
    return currentIndex >= static_cast<int>(list.size());
}

ShippingUnit *Manifest::currentItem()
{
    if (isDone())
    {
        return nullptr;
    }

    return list[currentIndex];
}
