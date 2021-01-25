#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED
// Typ-Definition der Struktur als date
typedef struct
{
    int year;
    int month;
    int day;
} date;

// Variable: Int-Array mit 12 Zahlen
extern int daysPerMonth[12];

// Funktionsprototypen
int isLeapYear(int year);
date normalizeDate(date dateInput);
void normalizeLeapedFebruary(int year);
int dayOfTheYear(date dateInput);
#endif // TIMELIB_H_INCLUDED
