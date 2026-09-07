#include "../import/CustomsAudit.h"
#include "../import/CargoGroup.h"

CustomsAudit::CustomsAudit(ShippingUnit *rootNode) : Inspection()
{
    root = rootNode;
    currentIndex = 0;
    populateList(rootNode);
}

void CustomsAudit::populateList(ShippingUnit *unit)
{
    if (unit == nullptr)
    {
        return;
    }

    CargoGroup *group = dynamic_cast<CargoGroup *>(unit);

    if (group != nullptr)
    {
        for (int i = 0; i < group->getChildCount(); i++)
        {
            populateList(group->getChildAt(i));
        }
    }

    list.push_back(unit);
}

CustomsAudit::~CustomsAudit()
{
}

void CustomsAudit::first()
{
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
    return currentIndex >= static_cast<int>(list.size());
}

ShippingUnit *CustomsAudit::currentItem()
{
    if (isDone())
    {
        return nullptr;
    }

    return list[currentIndex];
}