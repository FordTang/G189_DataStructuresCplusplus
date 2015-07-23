//**********************************************************
// Author: Ford Tang
//
// Test file for extClockType
//**********************************************************

#include "extClockType_H.h"
#include <iostream>

using namespace std;

int main()
{
	int hours, hours2, minutes, minutes2, seconds, seconds2, timezone, timezone2;

	cout << "Enter Hours (0-23):  ";
	cin >> hours;
	cout << "Enter Minutes (0-59):  ";
	cin >> minutes;
	cout << "Enter Seconds (0-59):  ";
	cin >> seconds;
	cout << "1 for Eastern Time" << endl << "2 for Central Time" << endl << "3 for Mountain Time" << endl << "4 for Pacific Time" << endl << "Enter Timezone:  ";
	cin >> timezone;

	extClockType myTime(hours,minutes,seconds,timezone);

	cout << "incrementing by one second" << endl;

	myTime.incrementSeconds();

	myTime.printTime();

	cout << "Another clock to compare against the first one" << endl << "Enter Hours (0-23):  ";
	cin >> hours2;
	cout << "Enter Minutes (0-59):  ";
	cin >> minutes2;
	cout << "Enter Seconds (0-59):  ";
	cin >> seconds2;
	cout << "1 for Eastern Time" << endl << "2 for Central Time" << endl << "3 for Mountain Time" << endl << "4 for Pacific Time" << endl << "Enter Timezone:  ";
	cin >> timezone2;

	extClockType anotherTime(hours2,minutes2,seconds2,timezone2);

	cout << "Comparing time" << endl;

	if (myTime.equalTime(anotherTime))
		cout << "The two clocks have the same time" << endl;
	else
		cout << "The two clocks have different time" << endl;

	return 0;
}