/**
timelib - Bibliothek für Zeitmanagement
Nico Nowak
25.01.2021
**/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

#define DEBUG

int main()
{
    // Testcode
    // Erzeugen der Date-Struktur, definiert in timelib.h
    date userDate;
    userDate.day = 0;
    userDate.month = 0;
    userDate.year = 0;

    int daysOfTheYear = 0;

    printf("Jahr: ");
    scanf("%i", &userDate.year);
    fflush(stdin);

    printf("Monat: ");
    scanf("%i", &userDate.month);
    fflush(stdin);

    printf("Tag: ");
    scanf("%i", &userDate.day);
    fflush(stdin);

    userDate = normalizeDate(userDate);
    daysOfTheYear = dayOfTheYear(userDate);

    printf("Datum: %i.%i.%i\n", userDate.day, userDate.month, userDate.year);
    printf("Das ist der %i. Tag des Jahres %i.", daysOfTheYear, userDate.year);
    #ifdef DEBUG
    #endif // DEBUG
    return 0;
}
