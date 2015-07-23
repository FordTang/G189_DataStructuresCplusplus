//**********************************************************
// Author: Ford Tang
//
// Test file for fractionType
//**********************************************************

#include "fractionType_H.h"
#include <iostream>

using namespace std;

int main()
{
	fractionType fractionOne, fractionTwo;

	cout << "This program will test arithmetic and relational operations between two fractions." << endl;
	cout << endl << "Please enter the first fraction (in the form #/#):  ";

	cin >> fractionOne;

	cout << endl << "Please enter the second fraction (in the form #/#):  ";

	cin >> fractionTwo;

	cout << endl << fractionOne << " + " << fractionTwo << " = " << fractionOne + fractionTwo << endl;

	cout << fractionOne << " - " << fractionTwo << " = " << fractionOne - fractionTwo << endl;

	cout << fractionOne <<  " X " << fractionTwo << " = " << fractionOne * fractionTwo << endl;

	cout << fractionOne << " / " << fractionTwo << " = " << fractionOne / fractionTwo << endl;

	cout << fractionOne << " < " << fractionTwo << " :  ";
	if (fractionOne < fractionTwo)
		cout << "True"  << endl;
	else
		cout << "False" << endl;

	cout << fractionOne << " > " << fractionTwo << " :  ";
	if (fractionOne > fractionTwo)
		cout << "True"  << endl;
	else
		cout << "False" << endl;

	cout << fractionOne << " = " << fractionTwo << " ?  ";
	if (fractionOne == fractionTwo)
		cout << "True"  << endl;
	else
		cout << "False" << endl;

	cout << fractionOne << " != " << fractionTwo << " ?  ";
	if (fractionOne != fractionTwo)
		cout << "True"  << endl;
	else
		cout << "False" << endl;

	return 0;
}