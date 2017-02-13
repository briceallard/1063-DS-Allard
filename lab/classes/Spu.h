#pragma once
// This class uses strings
#include<string>
using namespace std;
// An enumerated type will be used to indicate the type of shipping
enum ShippingType { oneDay, twoDay, ground };
class Spu
{
private:
	string senderName;
	int senderZip;
	string receiverName;
	int receiverZip;
	double weight;
	string location;
	bool deliveryStatus;
	ShippingType shipType;

public:
	Spu();
	Spu(string sn, int sz, string rn, int rz, double w, string loc, bool del, ShippingType st);

	// Accessor functions
	string getSenderName();
	int getSenderZip();
	string getReceiverName();
	int getReceiverZip();
	double getWeight();
	string getLocation();
	bool getDeliveryStatus();
	ShippingType getShipType();

	// Mutator functions
	void setLocation(string loc);
	void setStatus(bool isDeliveredYet);

	// Destructor
	~Spu();
};