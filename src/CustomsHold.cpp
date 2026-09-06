#include "../import/CustomsHold.h"
#include "../import/ClearedCustoms.h"
#include "../import/Parcel.h"
#include <iostream>

CustomsHold::CustomsHold() : ShippingState() {}

void CustomsHold::handleProcess(Parcel *parcel)
{
	std::cout << "  [CustomsHold] Parcel " << parcel->getID()
			  << " is held; cannot process (rejected)." << std::endl;
}
bool CustomsHold::dispatch(Parcel *parcel)
{
	std::cout << "  [CustomsHold] Parcel " << parcel->getID()
			  << " is held; cannot dispatch (rejected)." << std::endl;
	return false;
}
void CustomsHold::placeOnHold(Parcel *parcel)
{
	std::cout << "  [CustomsHold] Parcel " << parcel->getID()
			  << " is already on hold (rejected)." << std::endl;
}
void CustomsHold::releaseHold(Parcel *parcel)
{
	std::cout << "  [CustomsHold] Parcel " << parcel->getID()
			  << " released -> ClearedCustoms." << std::endl;
	parcel->setState(new ClearedCustoms());
}
std::string CustomsHold::getStateName() { return "CustomsHold"; }
