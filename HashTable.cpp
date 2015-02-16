/*
 * HashTable.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */

#include "HashTable.h"

HashTable::HashTable(int tableLength) {
	// TODO Auto-generated constructor stub
	if(tableLength <= 0) tableLength =15;
	array = new LinkList[ tableLength ];
	length = tableLength;

}
// returns the location of the word in the hashtable
int HashTable::hash( string itemKey)
{
	int value=0;
	for(unsigned int i=0; i<itemKey.length(); i++)
	{
		value += itemKey[i];
		return (value * itemKey.length()) % length;
	}
	return value;
}

//Add an item to the hash table
void HashTable::insertItem(string word)
{
	int location = hash(word);
	array[location].insertItem(word);
}

//Delete an Item from the Hash Table
// Returns true if the operation is successful
bool HashTable::deleteItem(string itemKey)
{
	int location = hash(itemKey);
	return array[location].removeItem(itemKey);

}

// Returns an item from the Hash Table by key.
// If item not found, Null Pointer returned
sName * HashTable::getItemByKey(string itemKey)
{
	int location = hash(itemKey);
	return array[location].getItem(itemKey);
}

// Display the contents of the Hash Table to console window
void HashTable::printHashTable()
{
	cout << "The hash Table contents are " << endl;
	for(int i=0;i<length;i++)
	{
		cout << "In location " << i + 1 << ": ";
		array[i].printList();
	}
}

// Prints a histogram showing Item distribution
void HashTable::printHistogram()
{
	cout << "\n\nHash table Contains ";
	cout << getNumberOfItems() << " Items total." << endl;
	for(int i=0;i<length;i++)
	{
		cout << i+1 << ":\t";
		for(int j=0;j<array[i].getLength();j++)
		{
			cout << " X";
		}
		cout << endl;
	}

}

// Return the number of Items in a location
int HashTable::getLength()
{
	return length;
}

// Returns the number of Items in the HashTable
int HashTable::getNumberOfItems()
{
	int totalNum;
	for(int i=0; i<length;i++)
	{
		totalNum += array[i].getLength();
	}
	return totalNum;
}

HashTable::~HashTable() {
	// TODO Auto-generated destructor stub
	delete [] array;
}

