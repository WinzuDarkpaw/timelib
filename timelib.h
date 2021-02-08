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
int is_leapyear(int year);
date normalize_date(date dateInput);
void normalize_leaped_february(int year);
int day_of_the_year(date dateInput);
#endif // TIMELIB_H_INCLUDED
