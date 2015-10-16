#ifndef H_itemLinkedListType
#define H_itemLinkedListType

#include <iostream>
#include <string>
#include "binarySearchTree.h"
#include "itemType.h"

using namespace std;

class itemBinaryTree:public bSearchTreeType<itemType>
{
public:
    bool itemSearch(string item);
		//Function to search the list to see whether a 
		//particular item, specified by the parameter 
		//item, is in stock. 
		
	bool isItemForSale(string item);
		//Function to determine whether at least one copy of
		//a particular item is in the auction

	void itemBidOnIt(string item);
		//Function to bid on an item

	void itemCheck(string item);
		

    bool itemCheckitem(string item);
		//Function to determine whether a particular item is
		//in stock.
		
    void itemUpdatenoBidsThisItem(string item, int num);
   		//update the number of bids of a item

    void itemSetnoBidsThisItem(string item, int num);
		//Function to reset the number of bids of a item.

    void itemPrintitem();
		//Function to print the items 


private:
    void searchitemList(string item, bool& found,
			       nodeType<itemType>* &current);
		//Function to search the item list for a 
		//particular item, specified by the parameter item. 
		//Postcondition: If the item is found, the parameter
		//               found is set to true, false otherwise. 
		//               The parameter current points to the 
		//               node containing the item.

	void inorderitem(nodeType<itemType> *p);
		//Function to print the items of all the items in stock. 
};

#endif