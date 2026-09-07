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
    bool testing = false;
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

    ShippingUnit *hazmatFail = new Hazmat(p2, "UN1993-Flammable", false);
    ShippingUnit *hazmatPass = new Hazmat(p3, "UN3480-LithiumBattery", true);

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


    delete vessel;
    return 0;
}