#include <iostream>
#include "customerType.h"

using namespace std;

void customerType::print()
{
	cout<<customerAccountNumber<<" ";
	personType::print();
	cout<<" "<<biddeditemTree.treeNodeCount()<<endl;
}

void customerType::setCustInfo(string first, string last,
							   int accountNumber,string email)
{
	personType::setName(first,last);
	customerAccountNumber = accountNumber;
}
 
void customerType::biditem(string item)
{
	biddeditemTree.insert(item);
}
void customerType::returnitem(string item)
{
	biddeditemTree.deleteNode(item);
}

int customerType::getNoOfTotalBids()
{
	return biddeditemTree.treeNodeCount();
}

int customerType::getAccountNumber()
{
	return customerAccountNumber; 
}

customerType::customerType(string first, string last, 
						   int accountNumber)
				:personType(first,last)
{
	customerAccountNumber = accountNumber;
}

customerType::customerType()
{
	customerAccountNumber = 0;
}


bool customerType::operator==(const customerType& right) const
{
	return(customerAccountNumber == right.customerAccountNumber);
}

bool customerType::operator!=(const customerType& right) const
{
	return(customerAccountNumber != right.customerAccountNumber);
}

bool customerType::operator<=(const customerType& right) const
{
	return(customerAccountNumber <= right.customerAccountNumber);
}

bool customerType::operator<(const customerType& right) const
{
	return(customerAccountNumber < right.customerAccountNumber);
}

bool customerType::operator>=(const customerType& right) const
{
	return(customerAccountNumber >= right.customerAccountNumber);
}

bool customerType::operator>(const customerType& right) const
{
	return(customerAccountNumber > right.customerAccountNumber);
}

ostream& operator<<(ostream& os,  customerType& cust)
{
	string fname = cust.getFirstName();
	string lname = cust.getLastName();

	os<<cust.customerAccountNumber<<" "<<fname
	  <<" "<<lname
	  <<" "<<cust.biddeditemTree.treeNodeCount()<<endl;

	return os;
}

void customerType::printbiddeditem()
{ 
	biddeditemTree.inorderTraversal();
}