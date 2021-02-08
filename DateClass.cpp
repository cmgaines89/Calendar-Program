/*
C. Gaines
Date Class: This program prints a calendar of the year of the users choosing, determining if the chosen year is a leap year
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Dates.h"

using namespace std;

//constructor
Dates::Dates(void)
{
	month[0] = "";    // no zero month, starts at 1
	month[1] = "JANUARY";
	month[2] = "FEBRUARY";
	month[3] = "MARCH";
	month[4] = "APRIL";
	month[5] = "MAY";
	month[6] = "JUNE";
	month[7] = "JULY";
	month[8] = "AUGUST";
	month[9] = "SEPTEMBER";
	month[10] = "OCTOBER";
	month[11] = "NOVEMBER";
	month[12] = "DECEMBER";

	days[0] = 0;	// no zero month
	days[1] = 31;
	days[2] = 28;
	days[3] = 31;
	days[4] = 30;
	days[5] = 31;
	days[6] = 30;
	days[7] = 31;
	days[8] = 31;
	days[9] = 30;
	days[10] = 31;
	days[11] = 30;
	days[12] = 31;

	weekdays[0] = "";	// no zero day
	weekdays[1] = "SUN";
	weekdays[2] = "MON";
	weekdays[3] = "TUE";
	weekdays[4] = "WED";
	weekdays[5] = "THU";
	weekdays[6] = "FRI";
	weekdays[7] = "SAT";
}

//figures out the day of the week - PRIVATE
int Dates::firstDayOfMonth(int month, int year)
{
	int day = 1;
	int a, y, m;
	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	
	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	
	//Working Alternative
	/*int wd = 0;
	int day = 1;
	int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	wd = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
	*/

	//return wd;
}

void Dates::leapYear(int year)
	curryear = year;

	//check for a leap year - if leap year show message
	if ((curryear % 4 == 0 && curryear % 100 != 0) || (curryear % 400 == 0))
	{
		days[2] = 29;
		cout << "THE YEAR " << year << " IS A LEAP YEAR" << endl << endl;
	}
}

//print out the calendar - PUBLIC
void Dates::getYearly(int year)
{
	curryear = year;

	if (curryear < 2000 || curryear > 2100)
	{
		cout << "YEAR MUST BE BETWEEN 2000 AND 2100" << endl;
		return;
	}


	int space = 0;

	for (int i = 1; i <= 12; i++)
	{//print month label in center of calendar
		space = (YEAR_ROW_WIDTH - month[i].size()) / 2;

		for (int x = 0; x < space; x++)
		{
			cout << "  ";
		}

		cout << month[i] << endl;

		//print weekday names
		for (int j = 1; j <= 7; j++)
		{
			cout << setw(5) << weekdays[j] << setw(2) << "   ";
		}

		cout << endl;

		//print days
		int printdays = 0;

		for (int j = 1; j <= days[i]; j++)
		{//moves display to the correct day of week for 1st
			if (j == 1)
			{
				int wd = firstDayOfMonth(i, curryear);

				for (int spaces = 0; spaces < wd; spaces++)
				{
					cout << setw(5) << " " << setw(2) << "   ";
					printdays++;
				}
			}

			cout << setw(5) << j << setw(2) << "   ";
			printdays++;

			if (printdays % 7 == 0)
			{
				cout << endl;
				printdays = 0;
			}
		}

		cout << endl << setw(35) << "*******************************************************" << endl;
	}
}

void Dates::scheduler(int year)
{
	char selection;
	int month;
	string e1, e2, e3, e4, e5;
	int count;

		cout << "PLEASE ENTER THE NUMBER OF EVENTS YOU WOULD LIKE TO SCHEDULE: ";
		cin >> count;

		while (count < 1 || count>5)
		{
			cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 5: ";
			cin >> count;
		}

		cout << "PLEASE ENTER THE NUMBER OF THE MONTH THAT YOU WOULD LIKE TO SCHEDULE YOUR EVENT: ";
		cin >> month;

		while (month < 1 || month > 13)
		{
			cout << "PLEASE ENTER A MONTH BETWEEN 1 AND 12: ";
			cin >> month;
		}

		cout << "PLEASE ENTER THE NUMBER OF THE MONTH THAT YOU WOULD LIKE TO SCHEDULE YOUR EVENT: ";
		cin >> month;

		while (month < 1 || month > 13)
		{
			cout << "PLEASE ENTER A MONTH BETWEEN 1 AND 12: ";
			cin >> month;
		}

}

void Dates::federalholidays(int year)
{
	cout << endl << "FEDERAL HOLIDAYS: " << endl;
	cout << "January: New Years Day - January 1st" << endl;
	cout << "February: MLK Day - February 16th" << endl;
	cout << "May: Memorial Day - May 29th" << endl;
	cout << "July: Independence Day - July 4th" << endl;
	cout << "September: Labpr Day - September 4th" << endl;
	cout << "October: Colombus Day - October 9th" << endl;
	cout << "November: Veterens Day - November 11th" << endl;
}
	
