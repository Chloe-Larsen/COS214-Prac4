#include "import/Booked.h"
#include "import/CargoGroup.h"
#include "import/ClearedCustoms.h"
#include "import/Container.h"
#include "import/CustomsAudit.h"
#include "import/CustomsHold.h"
#include "import/Delivered.h"
#include "import/Freight.h"
#include "import/Hazmat.h"
#include "import/Inspection.h"
#include "import/Insured.h"
#include "import/InTransit.h"
#include "import/Manifest.h"
#include "import/Pallet.h"
#include "import/Parcel.h"
#include "import/Refrigerated.h"
#include "import/ShipmentType.h"
#include "import/ShippingState.h"
#include "import/ShippingUnit.h"
#include "import/ColourHelper.h"

void printSeparator(const std::string &title = "")
{
    std::cout << ColourHelper::BOLD << "\n"
              << std::string(60, '=') << ColourHelper::RESET << std::endl;
    if (!title.empty())
    {
        std::cout << ColourHelper::BOLD << ColourHelper::UNDERLINE << ColourHelper::RED << "\t" << title << ColourHelper::RESET << std::endl;
        std::cout << ColourHelper::BOLD << std::string(60, '=') << ColourHelper::RESET << std::endl;
    }
    std::cout << std::endl;
}

void waitForUser()
{
    std::cout << ColourHelper::BOLD << ColourHelper::UNDERLINE << ColourHelper::RED << "\nPress Enter to continue..." << ColourHelper::RESET;
    std::cin.get();
}

int main()
{
    bool testing = true;
    printSeparator("Creating composite tree");

    Freight *vessel = new Freight(1, 101, "MSC Oscar");
    Container *dryContainer = new Container(10, 201);
    Container *refridContainer = new Container(11, 202);
    Pallet *pallet1 = new Pallet(100, 1500.0);
    Pallet *pallet2 = new Pallet(101, 1200.0);

    Parcel *p1 = new Parcel(1001, 20.0);
    Parcel *p2 = new Parcel(1002, 35.0);
    Parcel *p3 = new Parcel(1003, 15.0);
    Parcel *p4 = new Parcel(1004, 50.0);

    ShippingUnit *hazmatFail = new Hazmat(p2, "UN1993", false);
    ShippingUnit *hazmatPass = new Hazmat(p3, "UN3480", true);

    ShippingUnit *insuredParcel = new Insured(p4, 15000.0);
    ShippingUnit *coldInsuredParcel = new Refrigerated(insuredParcel, -18.0);

    pallet1->add(p1);
    pallet1->add(hazmatFail);

    pallet2->add(hazmatPass);
    pallet2->add(coldInsuredParcel);

    dryContainer->add(pallet1);
    refridContainer->add(pallet2);

    vessel->add(dryContainer);
    vessel->add(refridContainer);

    std::cout << "\nRoot Load: " << ColourHelper::BOLD << vessel->getType() << " (ID: #" << vessel->getID() << ")" << ColourHelper::RESET << std::endl;
    std::cout << "Total Consignment Weight: " << ColourHelper::BOLD << vessel->getWeight() << " kg" << ColourHelper::RESET << std::endl;
    std::cout << "Estimated Shipping Cost: R" << ColourHelper::BOLD << vessel->estimateShippingCost() << ColourHelper::RESET << std::endl;

    if (!testing)
        waitForUser();

    printSeparator("Manifest Traversal (All Units)");

    Inspection *manifest = vessel->createManifest();
    int count = 0;

    for (manifest->first(); !manifest->isDone(); manifest->next())
    {
        ShippingUnit *unit = manifest->currentItem();
        if (unit)
        {
            std::cout << " [" << count++ << "] "
                      << ColourHelper::YELLOW << unit->getType() << ColourHelper::RESET
                      << "\t| ID: #" << unit->getID()
                      << "\t| Weight: " << unit->getWeight() << " kg"
                      << "\t| Est. Cost: R" << unit->estimateShippingCost() << std::endl;
        }
    }
    delete manifest;

    if (!testing)
        waitForUser();

    printSeparator("State Transitions (Booked -> InTransit)");

    p1->dispatch();
    std::cout << std::endl;
    p4->dispatch();
    std::cout << std::endl;
    p1->dispatch();
    std::cout << std::endl;
    p2->dispatch();
    std::cout << std::endl;
    p3->dispatch();

    if (!testing)
        waitForUser();

    printSeparator("Customs Audit Inspection");

    Inspection *audit = vessel->createCustomsAudit();

    for (audit->first(); !audit->isDone(); audit->next())
    {
        ShippingUnit *flaggedUnit = audit->currentItem();
        if (flaggedUnit)
        {
            std::cout << ColourHelper::CYAN << "\n[AUDITING UNIT] " << ColourHelper::RESET
                      << ColourHelper::BOLD << flaggedUnit->getType() << " (#" << flaggedUnit->getID() << ")" << ColourHelper::RESET << std::endl;

            flaggedUnit->process();
        }
    }
    delete audit;
    audit = nullptr;

    if (!testing)
        waitForUser();

    printSeparator("Structural Change - Offloading Rejected Unit");

    std::cout << ColourHelper::BOLD << "Offloading non-compliant Hazmat unit #1002 from Pallet #100:" << ColourHelper::RESET << std::endl;
    pallet1->remove(hazmatFail);

    std::cout << "\nConsignment metrics after offloading unit #1002:" << std::endl;
    std::cout << "Pallet #100 Updated Weight: " << ColourHelper::BOLD << pallet1->getWeight() << " kg" << ColourHelper::RESET << std::endl;
    std::cout << "Vessel Total Consignment Weight: " << ColourHelper::BOLD << vessel->getWeight() << " kg" << ColourHelper::RESET << std::endl;
    std::cout << "Vessel Updated Shipping Cost: R" << ColourHelper::BOLD << vessel->estimateShippingCost() << ColourHelper::RESET << std::endl;

    audit = vessel->createCustomsAudit();

    for (audit->first(); !audit->isDone(); audit->next())
    {
        ShippingUnit *flaggedUnit = audit->currentItem();
        if (flaggedUnit)
        {
            std::cout << ColourHelper::CYAN << "\n[AUDITING UNIT] " << ColourHelper::RESET
                      << ColourHelper::BOLD << flaggedUnit->getType() << " (#" << flaggedUnit->getID() << ")" << ColourHelper::RESET << std::endl;

            flaggedUnit->process();
        }
    }
    delete audit;

    if (!testing)
        waitForUser();

    printSeparator("Resolving Holds & Finalising Delivery");

    std::cout << ColourHelper::BOLD << "Attempting to dispatch held unit #1002 while on hold:" << ColourHelper::RESET << std::endl;
    p2->dispatch();

    std::cout << ColourHelper::BOLD << "\nReleasing customs hold after placarding remediation:" << ColourHelper::RESET << std::endl;
    p2->releaseCustomsHold();

    std::cout << ColourHelper::BOLD << "\nResuming transit for unit #1002:" << ColourHelper::RESET << std::endl;
    p2->dispatch();

    std::cout << ColourHelper::BOLD << "\nFinalising deliveries at destination:" << ColourHelper::RESET << std::endl;
    p1->process();
    std::cout << std::endl;
    p2->process();
    std::cout << std::endl;
    p4->process();

    if (!testing)
        waitForUser();

    delete hazmatFail;
    delete vessel;
    return 0;
}