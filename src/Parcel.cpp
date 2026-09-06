#include "../import/Parcel.h"
#include "../import/ShippingState.h"
#include "../import/Booked.h"
#include "../import/Manifest.h"
#include "../import/CustomsAudit.h"

static const double RATE_PER_KG = 2.5;

// Every parcel starts life Booked.
Parcel::Parcel(int id, double weight)
	: ShippingUnit(id), state(new Booked()), weight(weight) {}

Parcel::~Parcel() { delete state; }

double Parcel::getWeight() { return weight; }
double Parcel::estimateShippingCost() { return weight * RATE_PER_KG; }

void Parcel::process()
{
	if (state)
		state->handleProcess(this);
}

Inspection *Parcel::createManifest() { return new Manifest(this); }
Inspection *Parcel::createCustomsAudit() { return new CustomsAudit(this); }

// The state objects call this to move the parcel to its next state.
void Parcel::setState(ShippingState *newState)
{
	if (newState && newState != state)
	{
		delete state;
		state = newState;
	}
}

std::string Parcel::getStateName() { return state ? state->getStateName() : "None"; }
bool Parcel::dispatch() { return state ? state->dispatch(this) : false; }
void Parcel::flagCustomsHold() { if (state) state->placeOnHold(this); }
void Parcel::releaseCustomsHold() { if (state) state->releaseHold(this); }
