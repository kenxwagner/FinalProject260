#include <iostream>

#include "customerBinaryTree.h"

using namespace std;

bool customerBTreeType::custSearchId(int id)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);
	return found;

}

void customerBTreeType::custReturnitem(int id, string item)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);
	current->info.returnitem(item);
}

void customerBTreeType::custBiditem(int id, string item)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);
	current->info.biditem(item);
}

int customerBTreeType::custGetNoOfTotalBids(int id)
{
	bool found;
	nodeType<customerType> *current;

	searchCust(id, found, current);

	return current->info.getNoOfTotalBids();
}


void customerBTreeType::searchCust(int id, bool& found,
						           nodeType<customerType>* &current)
{
	found = false;   //set found to false
   
	current = NULL;

   if(root == NULL)  // list is empty
      cout<<"Cannot search an empty list. "<<endl;
   else
   {
		current = root;  // set current point to root node of the tree
		found = false;       // set found to false

		while(!found && current != NULL) //search the tree
			if(current->info.getAccountNumber() == id)   //item is found
       			found = true;
			else
				if(current->info.getAccountNumber() > id)
					current = current->llink;
				else
					current = current->rlink;
	} //end else
}

void customerBTreeType::itemsBidInfo()
{
	nodeType<customerType> *current;
	current = root;

	cout<<"         ######## bidded item Info ########"
		<<endl<<endl;
	
	inorderbiddeditemInfo(root);
}

void customerBTreeType::inorderbiddeditemInfo(nodeType<customerType>* p)
{
	if(p != NULL)
	{
		inorderbiddeditemInfo(p->llink);
		if(p->info.getNoOfTotalBids() > 0)
		{
			cout<<"Customer ID: "<<p->info.getAccountNumber()
				<<endl;
			cout<<"items bidded: ";
			p->info.printbiddeditem();
			cout<<"*****************"<<endl<<endl;
		}
		inorderbiddeditemInfo(p->rlink);

	}
}