#include "../import/ShippingUnit.h"

ShippingUnit::ShippingUnit(int id) : id(id) {}
ShippingUnit::ShippingUnit() : id(0) {}
ShippingUnit::~ShippingUnit() {}
int ShippingUnit::getID() { return id; }
