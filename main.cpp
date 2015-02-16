//============================================================================
// Name        : Class.cpp
// Author      : Alex Agudelo, Thurston Brevett
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <vector>
#include "LinkList.h"
#include "HashTable.h"

int main()
{
	vector <string> list(7);

	list[0] = "Hello";
	list[1] = "trust";
	list[2] = "Mine";
	list[3] = "what";
	list[4] = "Possible";
	list[5] = "major";
	HashTable firstList;
	for(int i=0; i<list.size();i++)
	{
		firstList.insertItem(list[i]);
	}
	firstList.printHashTable();
	firstList.printHistogram();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
