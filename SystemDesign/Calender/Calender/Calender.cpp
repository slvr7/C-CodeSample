#include <iostream>
#include "Month.h"
using namespace std;


inline bool ValidMonth(int month)
{
    return (month >= 1) && (month <= 12);
}

inline bool ValidYear(int year)
{
    return year >= 2022;
}

int main()
{
    int yearInput;
    int monthInput;
    cout << "Input year and month to continue..." << endl;
    cin >> yearInput >> monthInput;
    while (!ValidMonth(monthInput) || !ValidYear(yearInput))
    {
        cout << "Error Input!" << endl;
        cin >> yearInput >> monthInput;
    }

    Month* monthToCheck = new Month(yearInput, monthInput);
    cout << endl;
    monthToCheck->Demonstrate();

}

