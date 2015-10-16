#ifndef H_itemType
#define H_itemType
#include <iostream>
#include <string>

using namespace std;

class itemType
{
	friend ostream& operator<<(ostream&, const itemType&);
public:
    void setitemInfo(string item, string itemName, 
					  string itemDescription, double minPrice, 
					  string startDate, string endDate, 
					  int setnoBidsThisItem);
    int getQuantityOfItem() const;
    void checkOut();
	void checkIn();
    void printitem() const;
    void printInfo() const;
    bool checkitem(string item);
    void updatenoBidsThisItem(int num);
    void SetnoBidsThisItem(int num);
    string getitem();
    itemType(string item = "" , string itemName = "", 
			  string itemDescription = "", double minPrice = 0.00, 
			  string startDate = "", string endDate = "", 
      		  int setnoBidsThisItem = 0);
    bool operator==(const itemType&) const;
    bool operator!=(const itemType&) const;
	bool operator<(const itemType&) const;
	bool operator<=(const itemType&) const;
	bool operator>(const itemType&) const;
	bool operator>=(const itemType&) const;

private:
    string tempItem;	
    string zItemitemName;	
    string zItemitemDescription;	
    double zItemminPrice;  
    string zItemstartDate; 
    string zItemendDate;  
    int copiesnoBidsThisItem; 
};

#endif