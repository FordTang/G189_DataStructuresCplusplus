//**********************************************************
// Author: Ford Tang
//
// Implementation file safeArray.cpp
// This file creates arrays that uses checks to ensure the
// safe use of arrays.
//**********************************************************

#include <iostream>
#include <cassert>

using namespace std;

class safeArray
{
private:
	int *arr;
	int start, end;

public:
	//constructor
	safeArray(int first = 0, int last = 1)
	{
		start = first;
		end = last;

		if (first < last)
		{
			arr = new int[end - start];
			assert(arr != NULL);
			for (int i = 0; i < (end - start); i++)
			{
				arr[i] = i;
			}
		}
		else
			cerr << "error!";
	}

	//copy constructor
	safeArray(const safeArray &otherArray)
	{
		start = otherArray.start;
		end = otherArray.end;
		
		arr = new int[end - start];
		assert(arr != NULL);

		for (int j = 0; j < (end - start); j++)  //copy otherList
			arr [j] = otherArray.arr[j];
	}

	//destructor
	~safeArray()
	{
		delete [] arr;
	}
	
	//returns value from array
	int &safeArray::operator[](int number)
	{
		if (number >= start && number < end)
			return arr[number - start];
		else
			cout << "Error, number is out of bounds" << endl;
	}

	//copy-like function
	safeArray &safeArray::operator=(const safeArray &otherArray)
	{
		if (this != &otherArray)   //avoid self-assignment
			{
				delete [] arr;
				start = otherArray.start;
				end = otherArray.end;
				
				arr = new int[(end - start)];  //create the array
				assert(arr != NULL);   //if unable to allocate memory
				                       //space, terminate the program
				for (int i = 0; i < (end - start); i++)
					arr[i] = otherArray.arr[i];
			}

    return *this;
	}
	
	//print function
	void safeArray::print() const
	{
		for (int i = 0; i < (end - start); i++)
			cout << arr[i] << " ";

		cout << endl;
	}

	//reports length of array
	int safeArray::length() const
	{
		return (end - start);
	}
};

int main()
{
	int first, last, input;
	cout << "Please enter the start of the array:  ";
	cin >> first;
	cout << "Please enter the end of the array:  ";
	cin >> last;

	safeArray test(first, last);
	
	cout << endl << "First Array has " << test.length() << " elements." << endl <<
		"Please enter " << last - first << " integers:";

	for (int i = first; i < last; i++)
	{
		cin >> input;
		test[i] = input;
	}

	cout << endl << "The First Array consists of :  ";
	test.print();

	cout << endl << "Creating a duplicate of the first array" << endl;
	safeArray test2(test);

	cout << "Duplicate array has " << test2.length() << " elements and they are:" << endl;
	test2.print();

	cout << endl << "Pick a value between " << first << " to " << (last - 1) << ".  This will return the value of the element:  ";
	cin >> input;
	cout << "The value is:  " << test[input] << endl;

	cout << endl << "Copying all data from first array into second array" << endl;
	safeArray test3;
	test3 = test;

	cout << "New array has " << test3.length() << " elements and they are:" << endl;
	test3.print();

	return 0;
}