#include <iostream>
#include "import/Freight.h"
#include "import/Container.h"
#include "import/Pallet.h"
#include "import/Parcel.h"
#include "import/Refrigerated.h"
#include "import/Insured.h"
#include "import/Hazmat.h"
#include "import/Inspection.h"

using namespace std;

// Helper: walk any subtree with a Manifest iterator and print each unit.
// The hierarchy is never exposed to this client code -- only the iterator is.
static void printManifest(ShippingUnit *root)
{
	Inspection *it = root->createManifest();
	for (it->first(); !it->isDone(); it->next())
	{
		ShippingUnit *u = it->currentItem();
		cout << "     unit #" << u->getID()
			 << "  weight=" << u->getWeight()
			 << "  cost=" << u->estimateShippingCost() << endl;
	}
	delete it;
}

int main()
{
	cout << "=========== TaskForge: Shipping Logistics ===========\n\n";

	// ---------------------------------------------------------------
	// Build the cargo hierarchy (Composite + Decorator)
	// ---------------------------------------------------------------
	Freight *ship = new Freight(1, 501, "MV Aurora");

	Container *contA = new Container(10, 7001);
	Parcel *p1 = new Parcel(101, 12.5);
	Parcel *p2raw = new Parcel(102, 8.0);
	Refrigerated *p2 = new Refrigerated(p2raw, -18.0); // one decorator
	contA->add(p1);
	contA->add(p2);

	Pallet *pallet = new Pallet(20, 500.0);
	Parcel *p3raw = new Parcel(103, 30.0);
	Hazmat *p3haz = new Hazmat(p3raw, "3", true);   // stacked...
	Insured *p3 = new Insured(p3haz, 25000.0);      // ...decorators
	pallet->add(p3);

	ship->add(contA);
	ship->add(pallet);

	// ===============================================================
	cout << "SCENARIO 1: Loading and dispatching the MV Aurora\n";
	cout << "-------------------------------------------------\n";
	cout << "  Full manifest (pre-order traversal of the nested cargo):\n";
	printManifest(ship);
	cout << "  Ship total weight: " << ship->getWeight() << " kg\n";
	cout << "  Ship total cost (decorator surcharges included): "
		 << ship->estimateShippingCost() << "\n\n";

	cout << "  Processing all cargo once -- decorators run, parcels react by state:\n";
	ship->process();
	cout << "\n";

	cout << "  Dispatching the parcels (State transitions):\n";
	p1->dispatch();     // Booked -> InTransit
	p2raw->dispatch();  // Booked -> InTransit
	p3raw->dispatch();  // Booked -> InTransit
	cout << "\n";

	cout << "  Delivering parcel 101 (process now that it is InTransit):\n";
	p1->process();      // InTransit -> Delivered
	cout << "  Parcel 101 state is now: " << p1->getStateName() << "\n";
	cout << "  Invalid-transition demo -- dispatch a Delivered parcel:\n";
	p1->dispatch();     // rejected, stays Delivered
	cout << "\n";

	// ===============================================================
	cout << "SCENARIO 2: Customs inspection and a runtime change\n";
	cout << "---------------------------------------------------\n";

	cout << "  Customs audit (post-order traversal -- a different iterator):\n";
	Inspection *audit = ship->createCustomsAudit();
	for (audit->first(); !audit->isDone(); audit->next())
		cout << "     audit visits unit #" << audit->currentItem()->getID() << "\n";
	cout << "\n";

	cout << "  Two independent traversals running at once over the SAME structure:\n";
	Inspection *m = ship->createManifest();
	Inspection *a2 = ship->createCustomsAudit();
	m->first();
	a2->first();
	cout << "     manifest starts at #" << m->currentItem()->getID()
		 << ", audit starts at #" << a2->currentItem()->getID() << "\n";
	m->next();
	m->next();
	cout << "     manifest advanced to #" << (m->isDone() ? -1 : m->currentItem()->getID())
		 << " while audit still at #" << a2->currentItem()->getID() << "\n\n";
	delete m;
	delete a2;
	delete audit;

	cout << "  Customs holds parcel 103 (State):\n";
	p3raw->flagCustomsHold();     // InTransit -> CustomsHold
	cout << "  Trying to dispatch while held (invalid):\n";
	p3raw->dispatch();            // rejected
	cout << "  Releasing the hold:\n";
	p3raw->releaseCustomsHold();  // CustomsHold -> ClearedCustoms
	p3raw->dispatch();            // ClearedCustoms -> InTransit
	cout << "  Parcel 103 state now: " << p3raw->getStateName() << "\n\n";

	cout << "  RUNTIME CHANGE (snapshot-traversal policy):\n";
	Inspection *before = ship->createManifest(); // snapshot taken here
	int countBefore = 0;
	for (before->first(); !before->isDone(); before->next())
		countBefore++;

	Parcel *p4 = new Parcel(104, 5.0);
	contA->add(p4); // structure grows AFTER the snapshot was taken

	int countSameIter = 0;
	for (before->first(); !before->isDone(); before->next())
		countSameIter++;

	Inspection *after = ship->createManifest(); // fresh snapshot
	int countFresh = 0;
	for (after->first(); !after->isDone(); after->next())
		countFresh++;

	cout << "     snapshot captured " << countBefore << " units; after add() it still\n";
	cout << "     reports " << countSameIter << " -- the in-progress traversal is unaffected.\n";
	cout << "     a fresh manifest reports " << countFresh << " units (now includes #104).\n\n";
	delete before;
	delete after;

	cout << "  Final delivery sweep for the remaining parcels:\n";
	p2raw->process(); // InTransit -> Delivered
	p3raw->process(); // InTransit -> Delivered
	cout << "\n";

	// ---------------------------------------------------------------
	cout << "=========== Shutting down ===========\n";
	delete ship; // owns everything below it -> one clean cascade of deletes
	cout << "All cargo, decorators and states destroyed cleanly.\n";
	return 0;
}
