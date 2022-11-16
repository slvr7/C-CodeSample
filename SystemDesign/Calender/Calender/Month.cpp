#include <iostream>
#include "Month.h"
using namespace std;

Month::Month(int yearInput, int monthInput)
{
	year = yearInput;
	month = monthInput;

	if (year % 4 == 0)
	{
		isLeapYear = true;
	}
	else
	{
		isLeapYear = false;
	}

    daysCount = GetDaysCountOfMonth(month);
    startWeekday = (GetDaysCountBefore() + 5) % 7;
}

void Month::Demonstrate()
{
	cout << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat " << "Sun " << endl;

    int start = startWeekday;
    int count = 1;

    for (int i = 1; i < 7; i++)
    {
        cout << " ";
        for (int j = 1; j < 8; j++)
        {
            if (start > 0)
            {
                start--;
                cout << "    ";
            }
            else
            {
                if (count <= daysCount)
                {
                    cout << count;
                    if (count / 10 > 0)
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << "   ";
                    }
                    count++;
                }
            }
        }
        cout << endl;
    }
}

int Month::GetDaysCountOfMonth(int m)
{
    switch (m)
    {
    case 1: return 31;
    case 2: return isLeapYear ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}

int Month::GetDaysCountOfYear(int y)
{
    return (y % 4 == 0 ? 366 : 365);
}

int Month::GetDaysCountBefore()
{
    int sum = 0;
    for (int i = 2022; i < year; i++)
    {
        sum += GetDaysCountOfYear(i);
    }
    for (int j = 1; j < month; j++)
    {
        sum += GetDaysCountOfMonth(j);
    }
    return sum;
}


