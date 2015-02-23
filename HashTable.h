/*
 * HashTable.h
 *
 *  Created on: Feb 15, 2015
 *      Author: alex
 */
#include <vector>
template <class T>
class HashTable {
public:
	//construct an empty Hash table object
	//Sets the default array size to 15
	HashTable(int tableLength=15);\

	//set the size of the hashtable
	void setHashTableSize(int tableLength=15);

	//Add an item to the hash table
	void insertItem(T word);

	//Delete an Item from the Hash Table
	// Returns true if the operation is successful
	bool deleteItem(T itemKey);

	// Returns an item from the Hash Table by key.
	// If item not found, Null Pointer returned
	bool getItemByKey(T itemKey);

	// Display the contents of the Hash Table to console window
	void printHashTable();

	// Prints a histogram showing Item distribution
	void printHistogram();

	//find the largest list
	void largestList();

	// Return the number of Items in a location
	int getLength();

	// Returns the number of Items in the HashTable
	int getNumberOfItems();

	// De-allocates all memory used for the Hash Table
	virtual ~HashTable();
private:
	//reference to an array of type LinkList
	vector <vector <string> > hashObject;

	//length of the hash table
	int length;

	//returns an array location for a given item key
	int hash( T itemKey);

};
