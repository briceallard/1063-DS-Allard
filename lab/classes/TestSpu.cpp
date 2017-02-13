#include <iostream>
#include "Spu.h"

using namespace std;

int main()
{
	// Instantiate a single package
	//Spu pkg1("Gary", 76334, "Cerise", 76310, 14, "TX", true, oneDay);
	Spu pkg1;
	// Display info about the package
	cout << pkg1.getSenderName() << " at zip code " << pkg1.getSenderZip();
	cout << " is sending a package weighing " << pkg1.getWeight();
	cout << " ounces to " << pkg1.getReceiverName() << " at zip code ";
	cout << pkg1.getReceiverZip() << endl;
	if (pkg1.getDeliveryStatus())
		cout << "The package has arrived.\n";
	else
		cout << "Package in transit.  Currently in " << pkg1.getLocation() << endl;
	system("pause");
	return 0;

}