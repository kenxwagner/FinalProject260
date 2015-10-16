#include <iostream>
#include <string>
#include "itemBinaryTree.h"

using namespace std;

bool itemBinaryTree::isItemForSale(string item) 
{
	bool found;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	if(found)
		found = (location->info.getQuantityOfItem() > 0);
	else 
		found = false;

	return found;
}

void itemBinaryTree::itemCheck(string item)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	if(found)
		location->info.checkIn();
	else
		cout<<"The item is not in stock."<<endl;
}

void itemBinaryTree::itemBidOnIt(string item)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	if(found)
		location->info.checkOut();
	else
		cout<<"The item is not in stock."<<endl;
}

bool itemBinaryTree::itemCheckitem(string item)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	return found;
}

void itemBinaryTree::itemUpdatenoBidsThisItem(string item, int num)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	if(found)
		location->info.updatenoBidsThisItem(num);
	else
		cout<<"The item is not in stock."<<endl;
}

void itemBinaryTree::itemSetnoBidsThisItem(string item, 
											int num)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	if(found)
		location->info.SetnoBidsThisItem(num);
	else
		cout<<"The item is not in stock."<<endl;
}

bool itemBinaryTree::itemSearch(string item)
{
	bool found = false;
	nodeType<itemType> *location;

	searchitemList(item,found,location);

	return found;
}

void itemBinaryTree::searchitemList(string item, 
									  bool& found,
									  nodeType<itemType>* &current)
{
	found = false;   
   
	itemType temp;

	temp.setitemInfo(item,"","",0.00,"","",0);

	if(root == NULL)  //the tree is empty
		cout<<"Cannot search an empty list. "<<endl;
	else
	{
		current = root;   //set current point to the root node 
		                  //of the binary tree
		found = false;    //set found to false

		while(!found && current != NULL) //search the tree
			if(current->info == temp)    //theitem is found
       			found = true;
			else
				if(current->info > temp)
					current = current->llink;
				else
					current = current->rlink;
	} //end else
}

void itemBinaryTree::itemPrintitem()
{
	inorderitem(root);
}

void itemBinaryTree::inorderitem(nodeType<itemType> *p)
{
	if(p != NULL)
	{
		inorderitem(p->llink);
		p->info.printitem();
		inorderitem(p->rlink);
	}
}

