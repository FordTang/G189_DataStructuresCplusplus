//**********************************************************
// Author: Ford Tang
//
// Header file for fractionType dataype.
// This file specifies the overloaded functions for
// fractions.
//**********************************************************

#ifndef fractionType_H
#define fractionType_H

#include <iostream>

using namespace std;

class fractionType
{
	friend ostream& operator << (ostream&, const fractionType &);  //overloaded output stream operator
    friend istream& operator >> (istream&, fractionType &);  //overloaded input stream operator

private:
	int numerator,denominator;

public:
	
	fractionType operator+(const fractionType& otherFraction) const;  //overloaded addition operator
	fractionType operator-(const fractionType& otherFraction) const;  //overloaded subtraction operator
	fractionType operator*(const fractionType& otherFraction) const;  //overloaded multiplication operator
	fractionType operator/(const fractionType& otherFraction) const;  //overloaded division operator
	bool operator<(const fractionType& otherFraction) const;  //overloaded "less than" relational operator
	bool operator>(const fractionType& otherFraction) const;  //overloaded "greater than" relational operator
	bool operator==(const fractionType& otherFraction) const;  //overloaded "equality" relational operator
	bool operator!=(const fractionType& otherFraction) const;  //overloaded "not equal to" relational operator

	fractionType(int top,int bottom);  //fractionType constructor with defined data

	fractionType();  //fractionType constructor without defined data.  Default data values will be used.
};

#endif