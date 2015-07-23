
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashT.h"
#include "arrayListType.h"

using namespace std;

int main()
{
	cout << "Creating default Hash Table with a size of 101" << endl;

	hashT<int> hashTest;

	int initialHashIndex;
	int foundHashIndex;
	int indexAt;
	int num;
	int record;
	bool found;
	
	cout << "Please enter a number for the hash index:  ";
	cin >> initialHashIndex;
	
	cout << "Insert numbers into Hash Table, end with -999:  " << endl;
	cin >> num;

	while (num != -999)                         
    {
		hashTest.insert(initialHashIndex, num);
		cin >> num;
	}
	
	cout << endl << "Search for a number in the Hash Table:  " << endl;
	cin >> num;

	foundHashIndex = initialHashIndex;

	hashTest.search(foundHashIndex, num, found);

	if (found == true)
		cout << num << " is in the Hash Table at " << foundHashIndex << endl;
	else
		cout << num << " is not in the Hash Table." << endl;
	
	cout << endl << "Testing isItemAtEqual, please enter index location:  ";
	cin >> indexAt;
	
	cout << endl << "please enter record:  ";
	cin >> num;

	cout << endl << num << " is " << hashTest.isItemAtEqual(indexAt, num) << endl;
	
	cout << endl << "Retrieve a record by index.  Please enter index location:  ";
	record = NULL;
	cin >> num;

	hashTest.retrieve(num, record);

	if (record != NULL)
		cout << endl << "The record at " << num << " is " << record << endl;
	
	cout << endl << "Enter a number to remove from the Hash Table:  ";
	cin >> num;

	hashTest.remove(initialHashIndex, num);

	cout << endl << "Printing the Hash Table:  ";
	hashTest.print();
	cout << endl << endl;

	//----------------------------------------------------------------
	//Begin Chapter 10, Problem 5
	//----------------------------------------------------------------

	/* initialize random seed: */
	srand (time(NULL));

	
	arrayListType<int> insertSort1000(1000);	
	arrayListType<int> insertSort10k(10000);
	
	cout << endl << "Creating Array of 1000 random elements" << endl;

	while (!insertSort1000.isFull())
		insertSort1000.insert(rand() % 100000 + 1);

	cout << endl << "Creating Array of 10000 random elements" << endl;

	while (!insertSort10k.isFull())
		insertSort10k.insert(rand() % 1000000 + 1);

	cout << endl << "Duplicating Array of 1000 random elements" << endl;

	arrayListType<int> shellSort1000(insertSort1000);

	cout << endl << "Duplicating Array of 10000 random elements" << endl;

	arrayListType<int> shellSort10k(insertSort10k);

	shellSort1000.print();
	//shellSort10k.print();

	cout << endl << "Using insertionSort on 1000 random elements Array" << endl;

	insertSort1000.insertionSort();
	//insertSort1000.print();

	cout << endl << "Using shellSort on 1000 random elements Array" << endl;

	shellSort1000.shellSort();
	//shellSort1000.print();

	cout << endl << "Using insertionSort on 10000 random elements Array" << endl;

	insertSort10k.insertionSort();
	//insertSort10k.print();

	cout << endl << "Using shellSort on 10000 random elements Array" << endl;

	shellSort10k.shellSort();
	//shellSort10k.print();

	cout << endl << "Finished" << endl;

	return 0;
}