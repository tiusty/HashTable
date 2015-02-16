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
#include <fstream>

int main()
{
	vector <string> list;
	// temporary string variable
	string temp;

	//open myFile which is the file inputed and creates an instream for that file
	ifstream myFile("wordList.txt");

	// while loop runs as long as not at the end of the file
	while(!myFile.eof())
	{
		// enter a line into the temporary variable and then add it to the list
		list.push_back((getline(myFile,temp),temp));
	}
	//close the file once all the words have been transfered into the data member wds.
	myFile.close();
	HashTable firstList(2000000);
	for(int i=0; i<list.size();i++)
	{
		firstList.insertItem(list[i]);
	}
	//firstList.printHashTable();
	firstList.printHistogram();

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
