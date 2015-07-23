//**********************************************************
// Author: Ford Tang
//
// Implementation file extClockType.cpp 
// This file extends the functions of clockTypeImp to 
// include the operations of timezones. 
//**********************************************************

#include "extClockType_H.h"
#include <iostream>

using namespace std;

//Constructor for extClockType that uses data supplied for hours, minutes, seconds and timezone.
extClockType::extClockType(int hours, int minutes, int seconds, int timezone)
{
	clockType::setTime(hours, minutes, seconds);  //setTime function from base class to set time.

	if (timezone < 1 || timezone > 4)  //Check for appropriate timezone data.  Invalid data will default to timezone 1 (EST)
		zone = 1;
	else
		zone = timezone;
}

//Constructor for extClockType where no data is given and will use default data of 0 hour, 0 minute, 0 seconds and timezone 1 (EST).
extClockType::extClockType()
{
	clockType::setTime(0, 0, 0);  //setTime function from base class to set time.
	zone = 1;
}

//Override function of setTime in base class.  Uses the setTime function of the base class to set time and sets the new timezone data.
void extClockType::setTime(int hours, int minutes, int seconds, int timezone)
{
	clockType::setTime(hours, minutes, seconds);  //setTime function from base class to set time.
	
	if (timezone < 1 || timezone > 4)  //Check for appropriate timezone data.  Invalid data will default to timezone 1 (EST)
		zone = 1;
	else
		zone = timezone;
}

//Override function of printTime in base class.  Uses the original printTime function and then prints out the new timezone data.
void extClockType::printTime() const
{
	clockType::printTime();  //printTime function of base class to print out time that does not include timezone.

	if (zone == 1)  //checks timezone data and prints out timezone in abbreviated format
		cout <<  " EST" << endl;

	if (zone == 2)  //checks timezone data and prints out timezone in abbreviated format
		cout << " CST" << endl;

	if (zone == 3)  //checks timezone data and prints out timezone in abbreviated format
		cout << " MST" << endl;

	if (zone == 4)  //checks timezone data and prints out timezone in abbreviated format
		cout << " PST" << endl;
}

//Override function of equalTime in base class.  Uses original equalTime function but adds a check to compare timezones between two extClockType objects.
bool extClockType::equalTime(const extClockType& otherClock) const
{
	return (clockType::equalTime(otherClock) && zone == otherClock.zone);
}
