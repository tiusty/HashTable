/*
 * LinkList.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */

#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

LinkList::LinkList() {
	head = new sName;
	head -> pNext = NULL;
	length = 0;
}
void  LinkList::insertItem(string newWord) {
	sName * newItem = new sName;
	newItem -> key = newWord;
	if(!(head->pNext)) {
		head -> pNext = newItem;
		length++; return;
	}
	else
	{
		//sName * conductor;
		//conductor = head;
		newItem->pNext = head->pNext;
		head->pNext = newItem;
		/*while(conductor -> pNext != NULL)
		{
			//nextList = conductor;
			//conductor = nextList ->pNext;

			cout << "test2" << endl;
			cout << "conductor pointer " << conductor << endl;

			cout << "next conductor pointer " << conductor -> pNext << endl;
			conductor = conductor ->pNext;
			cout << "GJ" << endl;

		}*/
		//conductor -> pNext = newItem; newItem -> pNext = NULL;
		length++;
	}

}
bool LinkList::removeItem (string itemKey)
{
	if(!(head->pNext))
	{ return false;	}
	else {
		sName * conductor = head;
		sName *nextList =head;
		while(conductor)
		{
			if(conductor -> key == itemKey)
			{
				nextList -> pNext = conductor -> pNext;
				delete conductor;
				length--;
				return true;
			}
			nextList = conductor;
			conductor = nextList ->pNext;
		}
	}
	return false;
}
sName * LinkList::getItem (string itemKey)
{
	sName * conductor = head;
	while(conductor!=NULL)
	{
		//cout << "test2" << endl;
		if((conductor != head) && (conductor -> key == itemKey))
		{
			return conductor;
		}
		conductor = conductor -> pNext;
	}
	return NULL;
}
void LinkList::printList()
{
	sName * conductor = head;
	sName * nextList = head;
	if(length==0)
	{
		cout << "Empty List" << endl;
		return;
	}
	cout << "Head --> ";
	while(conductor)
	{
		if(conductor != head)
		{
			cout << conductor -> key;
			if(conductor -> pNext)
			{
				cout << " --> ";
			}
			else
			{
			}
		}
		nextList = conductor;
		conductor = nextList -> pNext;
	}
	cout << endl;
}
int LinkList::getLength()
{
	return length;
}
LinkList::~LinkList() {
	// TODO Auto-generated destructor stub
}

