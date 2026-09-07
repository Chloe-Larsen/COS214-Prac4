#include "../import/CustomsAudit.h"
#include "../import/CargoGroup.h"
#include "../import/Hazmat.h"
#include "../import/Parcel.h"

CustomsAudit::CustomsAudit(ShippingUnit *root) : Inspection(), root(root), currentIndex(0)
{
    first();
}

void CustomsAudit::populateList(ShippingUnit *unit)
{
    if (!unit)
        return;

    bool requiresAudit = false;

    if (dynamic_cast<Hazmat *>(unit) != nullptr)
    {
        requiresAudit = true;
    }

    Parcel *parcel = dynamic_cast<Parcel *>(unit);
    if (parcel && parcel->getState())
    {
        std::string stateName = parcel->getState()->getStateName();
        if (stateName == "CustomsHold")
        {
            requiresAudit = true;
        }
    }

    if (requiresAudit)
    {
        list.push_back(unit);
    }

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

CustomsAudit::~CustomsAudit()
{
    list.clear();
}

void CustomsAudit::first()
{
    list.clear();
    populateList(root);
    currentIndex = 0;
}

void CustomsAudit::next()
{
    if (!isDone())
    {
        currentIndex++;
    }
}

bool CustomsAudit::isDone()
{
    return currentIndex >= list.size();
}

ShippingUnit *CustomsAudit::currentItem()
{
    if (isDone())
    {
        return nullptr;
    }
    return list[currentIndex];
}