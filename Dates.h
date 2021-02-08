/*
C. Gaines
Dates Header
*/

#ifndef DATES_H
#define define DATES_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Dates
{

public:
	Dates(void);
	void getYearly(int year);
	void scheduler(int year);
	void federalholidays(int year);
	void leapYear(int year);

protected:
	int curryear;
	string month[13]; //month array
	string weekdays[8]; //week day array
	int days[13]; //days array
	int firstDayOfMonth(int month, int year);
	static const int YEAR_ROW_WIDTH = 35; // width of a row in yearly display
};

#endif
