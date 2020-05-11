#include "HashTable.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test_1(const vector<int>&);
void test_2(const vector<int>&);
void test_3(const vector<int>&);
void test_4(const vector<int>&);
void test_5(const vector<int>&);
void test_6(const vector<int>&);
void printTable(const HashTable&);
void printIndexedTable(const HashTable&);

int main()
{
	vector<int> data = { 12, 886, 23, 99, 658, 240, 22, 59, 31, 582, 88, 126, 50 };

	cout << "TEST: default constructor, overloaded subscript operator\n";
	test_1(data);

	cout << "TEST: overloaded constructor, insert\n";
	test_2(data);

	cout << "TEST: copy constructor, emptyTable\n";
	test_3(data);

	cout << "TEST: move constructor, insert\n";
	test_4(data);

	cout << "TEST: overloaded assignment operator\n";
	test_5(data);

	cout << "TEST: move assignment operator\n";
	test_6(data);

	cout << endl;
	system("Pause");
	return 0;
}

void test_1(const vector<int>& data)
{
	// TEST: default constructor, overloaded subscript operator
	cout << "\nCreate and insert data into ht...\n\t";
	HashTable ht;
	printTable(ht);
	cout << "\n----------------------------------------------------\n";
}

void test_2(const vector<int>& data)
{
	// TEST: overloaded constructor, insert
	cout << "\nCreate and insert data into ht...\n";
	HashTable ht(19);
	for (const int& i : data)
		ht.insert(i);
	printIndexedTable(ht);
	cout << "\n----------------------------------------------------\n";
}

void test_3(const vector<int>& data)
{
	//TEST: copy constructor, emptyTable
	cout << "\nCreate and insert data into ht...\n";
	HashTable ht(19);
	for (const int& i : data)
		ht.insert(i);
	cout << "Print ht...\n";
	printTable(ht);

	cout << "\nCreate htCopy using the copy constructor and empty ht...\n";
	HashTable htCopy(ht);
	ht.emptyTable();
	cout << "Print ht (should be empty)...\n";
	printTable(ht);
	cout << "Print htCopy...\n";
	printTable(htCopy);
	cout << "\n----------------------------------------------------\n";
}

void test_4(const vector<int>& data)
{
	// TEST: move constructor, insert
	cout << "TEST: move constructor, insert\n";
	cout << "\nCreate and insert data into ht...\n";
	HashTable ht(19);
	for (const int& i : data)
		ht.insert(i);
	cout << "Print ht...\n";
	printTable(ht);

	cout << "\nCreate htCopy using the move constructor and empty ht...\n";
	HashTable htCopy = move(ht);
	cout << "Print ht...\n";
	ht.emptyTable();
	printTable(ht);  // should be empty
	cout << "Print htCopy...\n";
	printTable(htCopy);
	cout << "\n----------------------------------------------------\n";
}

void test_5(const vector<int>& data)
{
	// TEST: overloaded assignment operator
	cout << "\nCreate and insert data into ht...\n";
	HashTable ht(19);
	for (const int& i : data)
		ht.insert(i);
	cout << "Print ht...\n";
	printTable(ht);
	cout << "\nCreate htCopy using the default constructor...\n";
	HashTable htCopy;
	cout << "Print htCopy...\n";
	printTable(htCopy);

	cout << "\nCopy ht into htCopy (htCopy = ht) and empty ht...\n";
	htCopy = ht;
	ht.emptyTable();
	cout << "Print ht...\n";
	printTable(ht);
	cout << "Print htCopy...\n";
	printTable(htCopy);
}

void test_6(const vector<int>& data)
{
	// TEST: move assignment operator
	HashTable ht, htCopy(19);
	cout << "\nInsert the data into ht...";
	for (const int& i : data)
		htCopy.insert(i);
	cout << "Print ht...\n";
	printTable(ht);
	cout << "Print htCopy...\n";
	printTable(htCopy);

	cout << "\nMove ht into htCopy (htCopy = move(ht)) and empty ht...\n";
	htCopy = move(ht);
	cout << "Print ht...\n";
	ht.emptyTable();
	printTable(ht);  // should be empty
	cout << "Print htCopy...\n";
	printTable(htCopy);
}

void printTable(const HashTable& ht)
{
	int tableSize = ht.getCapacity();
	cout << "\t";
	if (tableSize == 0)
		cerr << "Table is empty.";
	else
		for (int i = 0; i < tableSize; ++i)
			cout << ht[i] << " ";
	cout << endl;
}

void printIndexedTable(const HashTable& ht)
{
	int tableSize = ht.getCapacity();
	if (tableSize == 0)
		cerr << "\nTable is empty.";
	else
		for (int i = 0; i < tableSize; ++i)
			cout << "\tIDX " << i << " = " << ht[i] << endl;
}