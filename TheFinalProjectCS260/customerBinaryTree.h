#ifndef H_customerListType
#define H_customerListType

#include <iostream>
#include "binarySearchTree.h"
#include "customerType.h"

using namespace std;

class customerBTreeType:public bSearchTreeType<customerType>
{
public:
	bool custSearchId(int id);
	void custReturnitem(int id, string item);
	void custBiditem(int id, string item);
	int  custGetNoOfTotalBids(int id);

	void itemsBidInfo();

private:
	void searchCust(int id, bool& found,
					nodeType<customerType>* &current);

	void inorderbiddeditemInfo(nodeType<customerType>* p);
	// Function to do an inorder traversal and print
	// bid item information

};

#endif