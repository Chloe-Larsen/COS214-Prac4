#include "../import/ShippingUnit.h"

ShippingUnit::ShippingUnit(int id, std::string type) : id(id), type(type)
{
}

ShippingUnit::~ShippingUnit()
{
}

int ShippingUnit::getID()
{
    return id;
}

std::string ShippingUnit::getType()
{
    return type;
}