#include <iostream>
#include <fstream>
#include "itemType.h"
#include "itemBinaryTree.h"
#include "customerType.h"
#include "customerBinaryTree.h"

using namespace std;

void createitemList(ifstream& infile, 
					 itemBinaryTree& itemList);
void createCustomerList(ifstream& infile,
				        customerBTreeType& custList);
void addCustomer(customerBTreeType& custList);

void displayMenu();


int main()
{
	itemBinaryTree  itemList;
	ifstream infile, infile1;

	int choice;
	//char ch;
	string itemID;
	int id;
	string custEmail;
	string chosen;
	char chosenA[5];
	
	customerBTreeType custList;

	infile.open("itemDat.txt");
	if(!infile)
	{
		cout<<"Input file does not exist"<<endl;
		return 1;
	}

	createitemList(infile, itemList);
	infile.close();

	infile1.open("custDat.txt");
	if(!infile1)
	{
		cout<<"Input file does not exist"<<endl;
		return 1;
	}

	createCustomerList(infile1,custList);
	infile1.close();

	displayMenu();
	cout<<"Please Choose: ";
	//cin>>choice;
	//cout<<endl;
	getline(cin,chosen);
	while (!isdigit(chosen[0]))
	{
		cout<<"not a number"<<endl;
		cout<<"please reenter"<<endl;
		getline(cin,chosen);
	}
	
	chosen.copy(chosenA,5);
	choice= atoi(chosenA);
cout<<endl;

	while(choice != 8)
		//while(choice != 11)
	{
		switch(choice)
		{
		case 1: addCustomer(custList);

				break;
		case 2: cout<<"Enter customer ID: ";
						cin>>id;
						cout<<endl;
						if(custList.custSearchId(id))
						{
							itemList.itemBidOnIt(itemID);
							custList.custBiditem(id, itemID);
							cout<<"Thanks for Bidding: "<<itemID<<endl;
						}
						else
							cout<<"Not a customer"<<endl;
		

				break;

		case 3: cout<<"Enter the item: ";
				getline(cin,itemID);
				cout<<endl;
				if(itemList.itemSearch(itemID))
				{
					cout<<"Enter customer id: ";
					cin>>id;
					cout<<endl;
					if(custList.custSearchId(id))
					{
						itemList.itemCheck(itemID);
						custList.custReturnitem(id, itemID);
						cout<<"Thanks for returning "
							<<itemID<<endl;
					}
					else
						cout<<"Not a customer"<<endl;
				}
				else
					cout<<"This item is not from our store"<<endl;

				break;
		case 4: cout<<"Enter the item: ";
				getline(cin,itemID);
				cout<<endl;
				if(itemList.itemSearch(itemID))
				{
					if(itemList.isItemForSale(itemID))
						cout<<"Currently in stock"<<endl;
					else
						cout<<"Out of stock"<<endl;
				}
				else
					cout<<"item not in store "<<endl;
				break;
		case 5: itemList.itemPrintitem();
			    break;
		case 6: itemList.inorderTraversal();
			    break;
		case 7: cout<<" ";
			    custList.inorderTraversal();
			    break;
		case 8: custList.itemsBidInfo();
			    break;
		/*case 9: bidList.bidPrintitem();
				break;
		case 10:bidList.inorderTraversal();
				break;*/

		default: cout<<"You Chose Poorly..."<<endl;
		}

		displayMenu();
		cout<<"Enter choice: ";
		getline(cin,chosen);
	while (!isdigit(chosen[0]))
	{
		cout<<"not a number"<<endl;
		cout<<"please reenter"<<endl;
		getline(cin,chosen);
	}
	
	chosen.copy(chosenA,5);
	choice= atoi(chosenA);
cout<<endl;
	}//end while

	return 0;
}

void createitemList(ifstream& infile, 
					 itemBinaryTree& itemList)
{
	string itemID;
	string itemName;
	string itemDescription;
	double minPrice;
	string startDate;
	string endDate;
	char   ch;
	int   noBidsThisItem;

	itemType newitem;

	getline(infile, itemID);
	while(infile)
	{
		getline(infile, itemName);
		getline(infile, itemDescription);
		infile>>minPrice;
		getline(infile, startDate);
		getline(infile, endDate);
		infile>>noBidsThisItem;
		infile.get(ch);
		newitem.setitemInfo(itemID,itemName,itemDescription,minPrice,
			                   startDate,endDate,noBidsThisItem);
		itemList.insert(newitem);

		getline(infile, itemID);
	}//end while

}//end createitemList

void displayMenu()
{
	cout << "              Welcome! " << endl;
	cout << "    Online Junk Menu System  " << endl << endl;
	cout << "1.  Add a Customer " << endl;
	cout << "2.  Add a New Item to Sell " << endl;
	cout << "3.  Show All Items For A Customer " << endl;
	cout << "4.  Show Single Customer List " << endl;
	cout << "5.  Show All Items for Sale " << endl;
	cout << "6.  Show All Items Sold " << endl;
	cout << "7.  Show Current Items With Bids "<< endl;
	cout << "8.  Exit       "<< endl;
	/*cout << "8.  Enter a New Bid " << endl;
	cout << "9. Show All Bids" << endl;
	cout << "10. Exit " << endl;
*/
}
void addCustomer(customerBTreeType& custList)
{
	string  fname;
	string  lname;
	int id;
	string custEmail;
	
	
	
	customerType cust;
	cout << "Enter Customer's First Name: " << endl;
	getline(cin,fname);
	cout << "Enter Customer's Last Name: " << endl;
	getline(cin,lname);
	cout << "Enter Customer's Email: " << endl;
	getline(cin,custEmail);
	cout << "Enter Customer's ID number: " << endl;
	cin >> id;
	if(custList.custSearchId(id)) //search for existing ID numbers
						{
							cout<<"That ID is being used"<<endl; 
						}
						else
							cust.setCustInfo(fname,lname,id,custEmail);
							custList.insert(cust);
							cout << "Welcome To The Club!! " << endl;
	
}

void createCustomerList(ifstream& infile,
				   customerBTreeType& custList)
{
	string fname;
	string lname;
	int id;
	string custEmail;

	customerType cust;

	infile>>fname>>lname>>id>>custEmail;
	while(infile)
	{
		cust.setCustInfo(fname,lname,id,custEmail);
		custList.insert(cust);
		infile>>fname>>lname>>id>>custEmail;
	}
}

