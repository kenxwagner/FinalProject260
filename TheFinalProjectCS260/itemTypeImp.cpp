#include <iostream>
#include <string>
#include "itemType.h"

using namespace std;

void itemType::setitemInfo(string item, string itemName, 
							 string itemDescription, double minPrice, 
							 string startDate, 
							 string endDate,
							 int setnoBidsThisItem)
{
	tempItem = item;
	zItemitemName = itemName;
	zItemitemDescription = itemDescription;
	zItemminPrice = minPrice;
	zItemstartDate = startDate;
	zItemendDate = endDate;
	copiesnoBidsThisItem = setnoBidsThisItem;
}

void itemType::checkIn()
{
	copiesnoBidsThisItem++;
}

void itemType::checkOut()
{
	if(getQuantityOfItem() > 0)
		copiesnoBidsThisItem--;
	else
		cout<<"Currently out of Stock"<<endl;
}

int itemType::getQuantityOfItem() const
{
	return copiesnoBidsThisItem;
}

void itemType::printitem() const
{
	cout<<"item item: "<<tempItem<<endl;
}

void itemType::printInfo() const
{
	cout<<"Item ID Number:        "<<tempItem<<endl;
	cout<<"Item Name:             "<<zItemitemName<< endl;
	cout<<"Item Description     : "<<zItemitemDescription<<endl;
	cout<<"Minimum Asking Price : "<<zItemminPrice<<endl;
	cout<<"Auction Start Date:    "<<zItemstartDate<<endl;
	cout<<"Auction End Date:      "<<zItemendDate<<endl;
	cout<<"Number of Bids:        "<<copiesnoBidsThisItem<<endl;
}

bool itemType::checkitem(string item)
{
	return(tempItem == item);
}

void itemType::updatenoBidsThisItem(int num)
{
	copiesnoBidsThisItem += num;
}

void itemType::SetnoBidsThisItem(int num)
{
	copiesnoBidsThisItem = num;
}

string itemType::getitem()
{
	return tempItem;
}

itemType::itemType(string item, string itemName, 
					 string itemDescription, double minPrice, 
					 string startDate, string endDate, 
					 int setnoBidsThisItem)
{
	tempItem = item;
	zItemitemName = itemName;
	zItemitemDescription = itemDescription;
	zItemminPrice = minPrice;
	zItemstartDate = startDate;
	zItemendDate = endDate;
	copiesnoBidsThisItem = setnoBidsThisItem;
}

bool itemType::operator==(const itemType& right) const
{
	return (tempItem == right.tempItem);
}

bool itemType::operator!=(const itemType& right) const
{
	return (tempItem != right.tempItem);
}

bool itemType::operator<(const itemType& right) const
{
	return (tempItem < right.tempItem);
}

bool itemType::operator<=(const itemType& right) const
{
	return (tempItem <= right.tempItem);
}

bool itemType::operator>(const itemType& right) const
{
	return (tempItem > right.tempItem);
}

bool itemType::operator>=(const itemType& right) const
{
	return (tempItem >= right.tempItem);
}

ostream& operator<<(ostream& os, const itemType &item)
{
	os<<endl;
	os<<"Item ID Number:        "<<item.tempItem<<endl;
	os<<"Item Name:             "<<item.zItemitemName<<endl;
	os<<"Item Description     : "<<item.zItemitemDescription<<endl;
	os<<"Minimum Asking Price : "<<item.zItemminPrice<<endl;
	os<<"Auction Start Date:    "<<item.zItemstartDate<<endl;
	os<<"Auction End Date:      "<<item.zItemendDate<<endl;
	os<<"Number of Bids:        "<<item.copiesnoBidsThisItem<<endl;
	os<<"_____________________________________"<<endl;

	
	return os;
}
