//**********************************************************
// Author: Ford Tang
//
// Implementation file for fractionType.cpp
// This file overloads the arithmetic and relational
// operations on fracitons.
//**********************************************************

#include "fractionType_H.h"
#include <iostream>

using namespace std;

//overloaded output stream operator
ostream& operator << (ostream& osObject, 
					  const fractionType& fractionType)
{
    osObject << fractionType.numerator << "/" << fractionType.denominator;

    return osObject;
}

//overloaded input stream operator
istream& operator >> (istream& isObject, 
					  fractionType& fractionType)
{
	char fractionBar;  //Used to discard fractionBar from the data input

	isObject >> fractionType.numerator >> fractionBar >> fractionType.denominator;

    return isObject;
}

//overloaded addition operator
fractionType fractionType::operator+(const fractionType& otherFraction) const
{
	fractionType tempFraction;

	tempFraction.numerator = (numerator * otherFraction.denominator) + (denominator * otherFraction.numerator);
	tempFraction.denominator = denominator * otherFraction.denominator;

	return tempFraction;
}

//overloaded subtraction operator
fractionType fractionType::operator-(const fractionType& otherFraction) const
{
	fractionType tempFraction;
	
	tempFraction.numerator = (numerator * otherFraction.denominator) - (denominator * otherFraction.numerator);
	tempFraction.denominator = denominator * otherFraction.denominator;

	return tempFraction;
}

//overloaded multiplication operator
fractionType fractionType::operator*(const fractionType& otherFraction) const
{
	fractionType tempFraction;

	tempFraction.numerator = numerator * otherFraction.numerator;
	tempFraction.denominator = denominator * otherFraction.denominator;

	return tempFraction;
}

//overloaded division operator
fractionType fractionType::operator/(const fractionType& otherFraction) const
{
	fractionType tempFraction;

	//unsure if this is working correctly, when dividing by same fraction values, it returns the tempFraction value.
	if (((float)otherFraction.numerator / (float)otherFraction.denominator) == 0)
		return tempFraction;
	else
	{		
		tempFraction.numerator = numerator * otherFraction.denominator;
		tempFraction.denominator = denominator * otherFraction.numerator;

		return tempFraction;
	}
}

//overloaded "less than" relational operator
bool fractionType::operator<(const fractionType& otherFraction) const
{
	if ((numerator * otherFraction.denominator) < (denominator * otherFraction.numerator))
		return true;
	else
		return false;
}

//overloaded "greater than" relational operator
bool fractionType::operator>(const fractionType& otherFraction) const
{
	if ((numerator * otherFraction.denominator) > (denominator * otherFraction.numerator))
		return true;
	else
		return false;
}

//overloaded "equality" relational operator
bool fractionType::operator==(const fractionType& otherFraction) const
{
	//this will check to see if fractions have the same base.  If not, it willt test them with common denominators.
	if (denominator != otherFraction.denominator)
	{
		fractionType testOne, testTwo;

		testOne.numerator = numerator * otherFraction.denominator;
		testOne.denominator = denominator * otherFraction.denominator;
		testTwo.numerator = otherFraction.numerator * denominator;
		testTwo.denominator = otherFraction.denominator * denominator;

		if (testOne.numerator == testTwo.numerator && testOne.denominator == testTwo.denominator)
			return true;
		else
			return false;
	}

	else if (numerator == otherFraction.numerator && denominator == otherFraction.denominator)
		return true;
	else
		return false;
}

//overloaded "not equal to" relational operator
bool fractionType::operator!=(const fractionType& otherFraction) const
{
	//this will check to see if fractions have the same base.  If not, it willt test them with common denominators.
	if (denominator != otherFraction.denominator)
	{
		fractionType testOne, testTwo;

		testOne.numerator = numerator * otherFraction.denominator;
		testOne.denominator = denominator * otherFraction.denominator;
		testTwo.numerator = otherFraction.numerator * denominator;
		testTwo.denominator = otherFraction.denominator * denominator;

		if (testOne.numerator != testTwo.numerator && testOne.denominator != testTwo.denominator)
			return true;
		else
			return false;
	}

	else if (numerator != otherFraction.numerator && denominator != otherFraction.denominator)
		return true;
	else
		return false;
}

//fractionType constructor with defined data
fractionType::fractionType(int top, int bottom)
{
	numerator = top;
	denominator = bottom;
}

//fractionType constructor without defined data.  Default data values will be used.
fractionType::fractionType()
{
	numerator = 0;
	denominator = 0;
}