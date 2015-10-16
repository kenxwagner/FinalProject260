
#ifndef H_customerType
#define H_customerType

#include <iostream>
#include "personType.h"
#include "binarySearchTree.h"

using namespace std;

class customerType: public personType
{
   friend ostream& operator<<(ostream&,  customerType&);
	  // overload stream insertion operator
public:
	void print();
	  // Output account number, first name, last name, and 
	  // number of TotalBids, in the form:
	  // AccountNumber firstName lastName noOfTotalBids
	void setCustInfo(string first, string last, int AccountNumber, string eMail);
	  // set firstName, lastName, account number, number of TotalBids according to the parameters
	  // firstName = first; lastName = last; 
	void biditem(string item);
	  

	void returnitem(string item);
	 

	int getNoOfTotalBids();
	  // This function returns the number of
	  // items bidded by the customer.
	int getAccountNumber();
	  // This function returns the account number of
	  // the customer.
	customerType(string first, string last, int AccountNumber);
	  // constructor with parameters
	  // set firstName and lastName according to the parameters
	  // firstName = first; lastName = last;
  	customerType(); 
  	 // default constructor;
  	 // intialize firstName and lastName, customerAccountNumber, and noOfTotalBids 
  	 // Post condition: firstName = ""; lastName = "";
	 //					customerAccountNumber = 0; 

	void printbiddeditem();

		//overload operators for comparisons 
	bool operator==(const customerType&) const;
	bool operator!=(const customerType&) const;
	bool operator<=(const customerType&) const;
	bool operator<(const customerType&) const;
	bool operator>=(const customerType&) const;
	bool operator>(const customerType&) const;

private:
	int customerAccountNumber; // store account number
	bSearchTreeType<string> biddeditemTree;
};

#endif 