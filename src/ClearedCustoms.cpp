#include "../import/ClearedCustoms.h"
#include "../import/InTransit.h"
#include "../import/Parcel.h"
#include <iostream>

ClearedCustoms::ClearedCustoms()
{
}

void ClearedCustoms::handleProcess(Parcel *parcel)
{
    std::cout << "Parcel must be dispatched again before processing." << std::endl;
}

bool ClearedCustoms::dispatch(Parcel *parcel)
{
    parcel->setState(new InTransit());
    return true;
}

void ClearedCustoms::placeOnHold(Parcel *parcel)
{
    std::cout << "Parcel has already cleared customs." << std::endl;
}

void ClearedCustoms::releaseHold(Parcel *parcel)
{
    std::cout << "Parcel has already cleared customs." << std::endl;
}

std::string ClearedCustoms::getStateName()
{
    return "Cleared Customs";
}