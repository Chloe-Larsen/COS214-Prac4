#include "../import/ClearedCustoms.h"
#include "../import/InTransit.h"
#include "../import/Parcel.h"
#include <iostream>

ClearedCustoms::ClearedCustoms() : ShippingState() {}

void ClearedCustoms::handleProcess(Parcel *parcel)
{
	std::cout << "  [ClearedCustoms] Parcel " << parcel->getID()
			  << " must resume transit before delivery (rejected)." << std::endl;
}
bool ClearedCustoms::dispatch(Parcel *parcel)
{
	std::cout << "  [ClearedCustoms] Parcel " << parcel->getID()
			  << " resumes journey -> InTransit." << std::endl;
	parcel->setState(new InTransit());
	return true;
}
void ClearedCustoms::placeOnHold(Parcel *parcel)
{
	std::cout << "  [ClearedCustoms] Parcel " << parcel->getID()
			  << " already cleared; cannot hold (rejected)." << std::endl;
}
void ClearedCustoms::releaseHold(Parcel *parcel)
{
	std::cout << "  [ClearedCustoms] Parcel " << parcel->getID()
			  << " is not on hold (rejected)." << std::endl;
}
std::string ClearedCustoms::getStateName() { return "ClearedCustoms"; }
