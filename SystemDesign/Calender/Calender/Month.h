#pragma once

class Month
{
public:
	int year;
	int month;
	int daysCount;
	bool isLeapYear;
	int startWeekday;

	Month(int yearInput, int monthInput);
	void Demonstrate();

private:
	int GetDaysCountOfMonth(int m);
	int GetDaysCountOfYear(int y);
	int GetDaysCountBefore();
};