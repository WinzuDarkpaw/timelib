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

     struct date date;
     date.day = 0;
     date.month = 0;
     date.year = 0;

     input_date(&date);

     int doty = day_of_the_year(date);

     int leaped = is_leapyear(date.year);
     char leaped_text[20] = "";

     if(leaped == 1)
     {
         strcpy(leaped_text, "Schaltjahr");
     }

     else
     {
         strcpy(leaped_text, "Kein Schaltjahr");
     }

     printf("Datum: %i.%i.%i\r\n", date.day, date.month, date.year);
     printf("%i. Tag\r\n", doty);
     printf("%s", leaped_text);

     return 0;
}
