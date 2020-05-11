#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
using namespace std;

class HashTable
{
public:
	// default constructor
	HashTable();

	// overloaded constructor
	HashTable(int);

	// copy constructor
	HashTable(const HashTable&);

	// move constructor
	HashTable(HashTable&&) noexcept;

	// insert
	void insert(int);

	// overloaded assignment operator
	HashTable& operator=(const HashTable&);

	// move assignment operator
	HashTable& operator=(HashTable&&) noexcept;

	// search
	bool search(int) const;

	// getCapacity
	int getCapacity() const;

	// subscript operator
	int& operator[](int);

	// emptyTable
	void emptyTable();

	// Destructor
	~HashTable();

private:
	// hashValue
	int hashValue(int, int) const;

	int* table;							//pointer to the hash table
	int numOfElements;					//number of items in the hash table
	int capacity;						//maximum length of the hash table	
	const static int CAPACITY = 11;		//maximum length of the hash table	

};

#endif
