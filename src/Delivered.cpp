#include "../import/Delivered.h"
#include "../import/Parcel.h"
#include <iostream>

Delivered::Delivered() : ShippingState() {}

void Delivered::handleProcess(Parcel *parcel)
{
	std::cout << "  [Delivered] Parcel " << parcel->getID()
			  << " already delivered (terminal, rejected)." << std::endl;
}
bool Delivered::dispatch(Parcel *parcel)
{
	std::cout << "  [Delivered] Parcel " << parcel->getID()
			  << " already delivered; cannot dispatch (rejected)." << std::endl;
	return false;
}
void Delivered::placeOnHold(Parcel *parcel)
{
	std::cout << "  [Delivered] Parcel " << parcel->getID()
			  << " already delivered; cannot hold (rejected)." << std::endl;
}
void Delivered::releaseHold(Parcel *parcel)
{
	std::cout << "  [Delivered] Parcel " << parcel->getID()
			  << " already delivered (rejected)." << std::endl;
}
std::string Delivered::getStateName() { return "Delivered"; }
