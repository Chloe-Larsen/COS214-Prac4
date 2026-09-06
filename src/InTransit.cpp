#include "../import/InTransit.h"
#include "../import/CustomsHold.h"
#include "../import/Delivered.h"
#include "../import/Parcel.h"
#include <iostream>

InTransit::InTransit() : ShippingState() {}

void InTransit::handleProcess(Parcel *parcel)
{
	std::cout << "  [InTransit] Parcel " << parcel->getID()
			  << " processed and delivered -> Delivered." << std::endl;
	parcel->setState(new Delivered());
}
bool InTransit::dispatch(Parcel *parcel)
{
	std::cout << "  [InTransit] Parcel " << parcel->getID()
			  << " is already moving; dispatch rejected." << std::endl;
	return false;
}
void InTransit::placeOnHold(Parcel *parcel)
{
	std::cout << "  [InTransit] Parcel " << parcel->getID()
			  << " flagged by customs -> CustomsHold." << std::endl;
	parcel->setState(new CustomsHold());
}
void InTransit::releaseHold(Parcel *parcel)
{
	std::cout << "  [InTransit] Parcel " << parcel->getID() << " is not on hold (rejected)." << std::endl;
}
std::string InTransit::getStateName() { return "InTransit"; }
