//**********************************************************
// Author: Ford Tang
//
// Test file for safeArray Template
//**********************************************************

#include <iostream>
#include <string>
#include "safeArray_H.h"

using namespace std;

int main()
{
	int first, last, intInput;
	string stringInput;


	cout << "First Array using integers" << endl;
	cout << "Please enter the start of the integer array:  ";
	cin >> first;
	cout << "Please enter the end of the integer array:  ";
	cin >> last;

	safeArray <int> intArray(first, last);

	cout << endl << "First integer Array has " << intArray.length() << " elements." << endl <<
		"Please enter " << last - first << " integers:";

	for (int i = first; i < last; i++)
	{
		cin >> intInput;
		intArray[i] = intInput;
	}

	cout << endl << "The First Array consists of :  ";
	intArray.print();

	cout << endl << "Creating a duplicate of the first array" << endl;
	safeArray <int> intArray2(intArray);

	cout << "Duplicate array has " << intArray2.length() << " elements and they are:" << endl;
	intArray2.print();

	cout << endl << "Second Array using string" << endl;
	cout << "Please enter the start of the string array:  ";
	cin >> first;
	cout << "Please enter the end of the string array:  ";
	cin >> last;

	safeArray <string> stringArray(first, last);

	cout << endl << "The String Array has " << stringArray.length() << " elements." << endl <<
		"Please enter " << last - first << " strings:";

	for (int i = first; i < last; i++)
	{
		cin >> stringInput;
		stringArray[i] = stringInput;
	}

	cout << endl << "Copying all data from string array into another array" << endl;
	safeArray <string> stringArray2;
	stringArray2 = stringArray;

	cout << "New array has " << stringArray2.length() << " elements and they are:" << endl;
	stringArray2.print();

	cout << endl << "Pick a value between " << first << " to " << (last - 1) << ".  This will return the value of the element:  ";
	cin >> intInput;
	cout << "The string is:  " << stringArray2[intInput] << endl;

	return 0;
}