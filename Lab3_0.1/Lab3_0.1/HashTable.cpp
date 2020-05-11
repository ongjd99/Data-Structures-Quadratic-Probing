/*
	Ong, Johnny

	April 11, 2020

	CS A200
	Lab 3
*/

#include "HashTable.h"

// default constructor
HashTable::HashTable()
{
	capacity = CAPACITY;
	numOfElements = 0;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table[i] = -1;
	}
}

// overloaded constructor
HashTable::HashTable(int newCapacity)
{
	capacity = newCapacity;
	numOfElements = 0;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table[i] = -1;
	}
}

// copy constructor
HashTable::HashTable(const HashTable& otherTable)
{
	capacity = otherTable.capacity;
	numOfElements = otherTable.numOfElements;
	table = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		table[i] = otherTable.table[i];
	}
}

// move constructor
HashTable::HashTable(HashTable&& otherTable) noexcept
{
	capacity = otherTable.capacity;
	numOfElements = otherTable.numOfElements;
	table = otherTable.table;

	otherTable.table = nullptr;
	otherTable.numOfElements = 0;
	otherTable.capacity = 0;
}

// insert
void HashTable::insert(int key)
{
	if (numOfElements == capacity)
	{
		cout << "Table is full. Cannot insert." << endl;
	}
	else
	{
		int cycleBeginsAt = (capacity + 1) / 2;
		int i = 0;
		bool foundSpot = false;
		while (i < cycleBeginsAt && !foundSpot)
		{
			int hashIndex = hashValue(i, key);
			if (table[hashIndex] == -1)
			{
				table[hashIndex] = key;
				foundSpot = true;
				numOfElements++;
			}
			else
			{
				i++;
			}
		}
		if (i >= cycleBeginsAt)
		{
			cout << "Could not insert key. Need to rehash." << endl;
		}
	}
}

// overloaded assignment operator
HashTable& HashTable::operator=(const HashTable& otherTable)
{
	if (this == &otherTable)
	{
		cerr << "Attempted assignment to self" << endl;
	}
	else
	{
		delete[] table;

		capacity = otherTable.capacity;
		numOfElements = otherTable.numOfElements;
		table = new int[capacity];
		for (int i = 0; i < capacity; i++)
		{
			table[i] = otherTable.table[i];
		}
	}
	return *this;
}

// move assignment operator
HashTable& HashTable::operator=(HashTable&& otherTable) noexcept
{
	if (this == &otherTable)
	{
		cerr << "Attempted assignment to self" << endl;
	}
	else
	{
		delete[] table;

		capacity = otherTable.capacity;
		numOfElements = otherTable.numOfElements;
		table = otherTable.table;

		otherTable.table = nullptr;
		otherTable.numOfElements = 0;
		otherTable.capacity = 0;
	}
	return *this;
}

// search
bool HashTable::search(int numToSearch) const
{
	bool found = false;
	if (numOfElements == 0)
	{
		cout << "Hash table is empty." << endl;
	}
	else
	{
		bool searching = true;
		int i = 0;
		while (searching)
		{
			int hashIndex = hashValue(i, numToSearch);
			if (table[hashIndex] == numToSearch)
			{
				searching = false;
				found = true;
			}
			else if (table[hashIndex] == -1)
			{
				searching = false;
			}
			else
			{
				i++;
			}
		}
	}
	return found;
}

// getCapacity
int HashTable::getCapacity() const
{
	return capacity;
}

// subscript operator
int& HashTable::operator[](int index) 
{
	return table[index];
}

// emptyTable
void HashTable::emptyTable()
{
	for (int i = 0; i < capacity; i++)
	{
		table[i] = -1;
	}
	numOfElements = 0;
}

// Destructor
HashTable::~HashTable()
{
	delete[] table;
}

// hashValue
int HashTable::hashValue(int j, int key) const
{
	return (((2 * key + 5) + (j * j)) % capacity);
}