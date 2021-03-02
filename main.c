/**
timelib - Bibliothek f�r Zeitmanagement
Nico Nowak
25.01.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timelib.h"

#define DEBUG

int main()
{
    printf("timelib.h\r\n");

    int day = 0;
    int month = 0;
    int year = 0;

    input_date(&day, &month, &year);

    int doty = day_of_the_year(day, month, year);

    int leaped = is_leapyear(year);
    char leaped_text[20] = "";

    if(leaped == 1)
    {
        strcpy(leaped_text, "Schaltjahr");
    }
    else
    {
        strcpy(leaped_text, "Kein Schaltjahr");
    }

    printf("Datum: %i.%i.%i\r\n", day, month,year);
    printf("%i. Tag\r\n", doty);
    printf("%s", leaped_text);

    return 0;
}
