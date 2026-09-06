#include "../import/Booked.h"
#include "../import/InTransit.h"
#include "../import/Parcel.h"
#include <iostream>

Booked::Booked() : ShippingState() {}

void Booked::handleProcess(Parcel *parcel)
{
	std::cout << "  [Booked] Parcel " << parcel->getID()
			  << " cannot be processed before dispatch (rejected)." << std::endl;
}
bool Booked::dispatch(Parcel *parcel)
{
	std::cout << "  [Booked] Parcel " << parcel->getID() << " dispatched -> InTransit." << std::endl;
	parcel->setState(new InTransit());
	return true;
}
void Booked::placeOnHold(Parcel *parcel)
{
	std::cout << "  [Booked] Parcel " << parcel->getID()
			  << " cannot be held before dispatch (rejected)." << std::endl;
}
void Booked::releaseHold(Parcel *parcel)
{
	std::cout << "  [Booked] Parcel " << parcel->getID() << " is not on hold (rejected)." << std::endl;
}
std::string Booked::getStateName() { return "Booked"; }
