#ifndef safeArray_H
#define safeArray_H

//**********************************************************
// Author: Ford Tang
//
// Template file safeArray_H.h
// This template specifies members of safeArray lists.
//**********************************************************

#include <iostream>
#include <cassert>

using namespace std;

template <class elemType>
class safeArray
{
protected:
	elemType *arr;
	int start, end;

public:
	safeArray(int first = 0, int last = 1);
	//Constructor
	//creates an array with the size consisting of the last value subtracted
	//from the first value.
	//Defaults to array with a size of 1

	safeArray(const safeArray<elemType> &otherArray);
	//Copy Constructor

	~safeArray();
	//Destructor

	elemType &operator[](int number);
	//Overloads [] operator
	//Returns data in array

	safeArray<elemType> &operator=(const safeArray<elemType> &otherArray);
	//Overloads = operator
	//Functions like copy

	void print() const;
	//Function to output elements of the array

	int length() const;
	//Function returns length of array
};

template <class elemType>
safeArray<elemType>::safeArray(int first = 0, int last = 1)
{
	start = first;
	end = last;
	if (first < last)
	{
		arr = new elemType[end - start];
		assert(arr != NULL);
	}
	else
		cerr << "error!";
}

template <class elemType>
safeArray<elemType>::safeArray(const safeArray<elemType> &otherArray)
{
	start = otherArray.start;
	end = otherArray.end;
	
	arr = new elemType[end - start];
	assert(arr != NULL);
	
	for (int j = 0; j < (end - start); j++)  //copy otherList
		arr [j] = otherArray.arr[j];
}

template <class elemType>
safeArray<elemType>::~safeArray()
{
	delete [] arr;
}

template <class elemType>
elemType &safeArray<elemType>::operator[](int number)
{
	if (number >= start && number < end)
		return arr[number - start];
	else
		cout << "Error, number is out of bounds" << endl;
}

template <class elemType>
safeArray<elemType> &safeArray<elemType>::operator=(const safeArray<elemType> &otherArray)
{
	if (this != &otherArray)   //avoid self-assignment
		{
			delete [] arr;
			start = otherArray.start;
			end = otherArray.end;
			
			arr = new elemType[(end - start)];  //create the array
			assert(arr != NULL);   //if unable to allocate memory
			                       //space, terminate the program
			for (int i = 0; i < (end - start); i++)
				arr[i] = otherArray.arr[i];
		}

    return *this;
}

template <class elemType>
void safeArray<elemType>::print() const
{
	for (int i = 0; i < (end - start); i++)
		cout << arr[i] << " ";

	cout << endl;
}

template <class elemType>
int safeArray<elemType>::length() const
{
	return (end - start);
};

#endif