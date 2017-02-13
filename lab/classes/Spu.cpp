#include<iostream>
#include"Spu.h"

using namespace std;

Spu::Spu(){
	senderName = "From";
	senderZip = 11111;
	receiverName = " To";
	receiverZip = 99999;
	weight = 1;
	deliveryStatus = false;
	location = "TX";
	shipType = ground;
}

Spu::Spu(string sn, int sz, string rn, int rz, double w, string loc, bool del, ShippingType st){
	senderName = sn;
	senderZip = sz;
	receiverName = rn;
	receiverZip = rz;
	weight = w;
	deliveryStatus = del;
	location = loc;
	shipType = st;
}

string Spu::getSenderName(){
	return senderName;
}
int Spu::getSenderZip(){
	return senderZip;
}
string Spu::getReceiverName(){
	return receiverName;
}
int Spu::getReceiverZip(){
	return receiverZip;
}
double Spu::getWeight(){
	return weight;
}
string Spu::getLocation(){
	return location;
}
bool Spu::getDeliveryStatus(){
	return deliveryStatus;
}
ShippingType Spu::getShipType(){
	return shipType;
}
void Spu::setLocation(string loc){
	location = loc;
}
void Spu::setStatus(bool isDeliveredYet){
	deliveryStatus = isDeliveredYet;
}
Spu::~Spu(){

}