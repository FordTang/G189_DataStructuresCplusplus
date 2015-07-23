//*************************************************************
// Author: Ford Tang
// 
// class extClockType_H.h
// This class is derived from clockType and implements
// time zones.
//*************************************************************

#ifndef extClockType_H
#define extClockType_H

#include "clockType.h"

class extClockType: public clockType
{
private:
	int zone;  //Added zone variable to hold timezone data.

public:
	void setTime(int hours, int minutes, int seconds, int timezone);  //Overriding setTime function in base class to add timezone data.

	void printTime() const;  //Overriding printTime function in base class to include timezone in printout.

	bool equalTime(const extClockType& otherClock) const;  //Overriding equalTime function in base class to also test timezone equality.

	extClockType(int hours, int minutes, int seconds, int timezone);  //Constructor for extClockType with defined data.

	extClockType();  //Constructor for extClockType without data.  Default data will be supplied.
};

#endif