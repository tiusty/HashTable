/*
 * HashTable.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: Alex, Thurston
 */

using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

template <class T>
HashTable <T> ::HashTable(int tableLength) {
	// TODO Auto-generated constructor stub
	if(tableLength <= 0){throw invalid_argument("In 'mergeSort': invalid argument\n");}
	hashObject.resize(tableLength);
	length = tableLength;

}
template <class T>
void HashTable<T>::setHashTableSize(int tableLength)
{
	if(tableLength <= 0) {throw invalid_argument("In 'mergeSort': invalid argument\n");}
	hashObject.resize(tableLength);
	length = tableLength;
}
// returns the location of the word in the hashtable
template <class T>
int HashTable<T>::hash( T itemKey)
{
	int result=1;
	for(int i=0; i<3;i++)
	{
		//if the character at that spot is a a-z then find its ascii value subtracted
		//by 95 to put it into the range of 1-27 to reduce the size of the hash table
		if((int)itemKey[i] >=97 && (int)itemKey[i] <= 122)
		{
			result *= (int)itemKey[i]-95;
		}
		//if the character is not a-z then arbitrary give that character
		//the value of 24
		else
		{
			result *= 24;
		}
	}
	//add some more elements to the hash to make it more unique
	result += (int)itemKey[1];
	result += (int)itemKey[2];
	result += (int)itemKey[3];
	result -= (int)itemKey[4];
	result = result % 10000;
	//return the result which is the location of the word
	return result;

}

// find the largest linked list and prints out its size
template <class T>
void HashTable<T>::largestList()
{
	//sets the initalize size to the first element
	T largestListIndex = hashObject[0].size();
	int largestListIndexLocation=0;
	//loops through every link list created
	for(int i=1; i<length;i++)
	{
		//if the size of the list is bigger then the biggest list
		//then set that link list as the biggest list
		if(hashObject[i].size()> largestListIndex)
		{
			largestListIndex = hashObject[i].size();
			largestListIndexLocation = i;
		}
	}
	//print out the result of the search
	cout << "The largest size is " << largestListIndex << endl;
	cout << "The location of this is " << largestListIndexLocation << endl;
}

//Add an item to the hash table
template <class T>
void HashTable<T>::insertItem(T itemKey)
{
	//find the location for the given key
	int location = hash(itemKey);
	//insert the element to the back of the vector
	hashObject[location].push_back(itemKey);

}
// Returns an item from the Hash Table by key.
// If item not found, false returned
template <class T>
bool HashTable<T>::getItemByKey(T itemKey)
{
	//finds the location that the item would be at
	int location = hash(itemKey);
	//searches all the chained elements at that hash location
	for(int i=0; i< hashObject[location].size();i++)
	{
		//if the same exact key is found then return true
		//else return false
		if(itemKey == hashObject[location].at(i))
		{
			return true;
		}
	}
	return false;

}

// Prints a histogram showing Item distribution
template <class T>
void HashTable<T>::printHistogram()
{
	cout << "\n\nHash table Contains ";
	cout << getNumberOfItems() << " Items total." << endl;
	//Iterates for every item in the Hash Table
	for(int i=0;i<length;i++)
	{
		cout << i+1 << ":\t";
		//iterates through the chaining elements in each location of the hash table
		//prints out an X for each element in that location as to indicate
		//one element per X
		for(int j=0;j<hashObject[i].size();j++)
		{
			cout << " X";
		}
		cout << endl;
	}

}

// Return the number of Items in a location
template <class T>
int HashTable<T>::getLength()
{
	//returns the length of the hashTable
	return length;
}

// Returns the number of Items in the HashTable
template <class T>
int HashTable<T>::getNumberOfItems()
{
	int totalNum;
	//iterates through every element in the hash table and
	//adds up all the chaining elements at each location
	//to find the total amount of elements currently in the hash table
	for(int i=0; i<length;i++)
	{
		totalNum += hashObject[i].size();
	}
	return totalNum;
}
template <class T>
HashTable<T>::~HashTable() {
	// TODO Auto-generated destructor stub
}
