/*
Corinne Gaines
Date Class: This program prints a calendar of the year of the users choosing, determining if the chosen year is a leap year...ADD MORE
Corinne Gaines, Jairon Dixon, Jeremiah Gathers
COSC 214
Fall 2017
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Dates.h"

using namespace std;

int main()
{
	int year;
	char selection, selection2;
	Dates calendar;

	cout << "!!WELCOME TO YOUR YEARLY CALENDAR!!" << endl << endl;

	cout << "PLEASE ENTER A YEAR BETWEEN 2000 AND 2100: ";
	cin >> year;

	calendar.leapYear(year);

	cout << "Would you like to know how many federal holidays are in the year " <<year<<" and what they are? Y or N? ";
	cin >> selection2;

	if (selection2 == 'y' || selection2 == 'Y')
	{
		calendar.federalholidays(year);
		cout << endl << endl;
	}

	else if (selection2 == 'n' || selection2 == 'N')
		cout << "You have selected no, no holidays will be shown." << endl << endl;

	calendar.getYearly(year);

	system("pause");
	return 0;
}