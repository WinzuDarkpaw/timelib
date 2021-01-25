#include "timelib.h"
int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

// Gibt 1 zurück, wenn das angegebene Jahr ein Schaltjahr ist.
int isLeapYear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

// Normalisiert das Datum, gibt ein Datum zurück und nimmt eines entgegen.
date normalizeDate(date dateInput)
{
    int day = dateInput.day;
    int month = dateInput.month;
    int year = dateInput.year;

    // Normalisiert die Jahres-Anzahl
    while(month > 12)
    {
        month -= 12;
        year += 1;
    }

    // Ändert falls Ausgangsjahr Schaltjahr ist, die Tagesanzahl von Februar
    normalizeLeapedFebruary(year);

    // Normalisiert Tages-Anzahl.
    if(month <= 0)
    {
        month = 1;
    }
    while(day > daysPerMonth[month - 1])
    {
        day -= daysPerMonth[month - 1];
        month += 1;

        if(month > 12)
        {
            month -= 12;
            year += 1;
        }
    }

    date dateOutput;
    dateOutput.day = day;
    dateOutput.month = month;
    dateOutput.year = year;

    return dateOutput;
}

// Ändert die maximale Tag-Anzahl des Februars, basierend darauf, ob das Jahr ein Schaltjahr ist.
void normalizeLeapedFebruary(int year)
{
    if(isLeapYear(year) == 1)
    {
        daysPerMonth[1] = 29;
    }
    else if(isLeapYear(year) == 0)
    {
        daysPerMonth[1] = 28;
    }
}

int dayOfTheYear(date dateInput)
{
    int month = dateInput.month;
    int day = dateInput.day;

    int result = 0;

    month -= 1;

    while(month != 0)
    {
        result += daysPerMonth[month - 1];
        month -= 1;
    }

    result += day;

    return result;
}
