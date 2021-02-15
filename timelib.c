#include "stdio.h"
#include "timelib.h"

/**
timelib.c
Implementierung der definierten Funktionen in der timelib.h.
Beinhaltet die Logik zum arbeiten mit Daten.

Autor: Nico Nowak
Erstellungsdatum: 15.02.2021
**/

/*
    Die Funktion berechnet f�r ein gegebens Datum des gregorianischen Kalendars
    bestehend aus Tag, Monat und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn
    (1. Januar) an.
    Schaltjahre werden bei der Berechnung ber�cksichtigt. Ist das �bergebene Datum
    ung�ltig, betr�gt der R�ckgabewert -1.
*/
int day_of_the_year(int day, int month, int year)
{
    int result = 0;
    /*  Validierung der Eingaben
    *   Eingaben dürfen nicht unter 1 bzw. 1582 (für Jahr) sein,
    *   sowie nicht höher als zugelassene Daten
    */
    if(exists_date(day, month, year) == FALSE)
    {
        return ERROR;
    }

    /*  Iteration
    *   Holt sich die Tagesanzahl alles vollen Monate
    *   Die Tage des nicht vollen Monats werden draufaddiert.
    */
    for(int iteration = 1; iteration < month; iteration++)
    {
        result += get_days_for_month(iteration, year);
    }
    result += day;

    return result;
}

/*
    Die Funktion liest 3 Ganzahlwerte (Integer) ein, f�r Tag, Monat und Jahr.
    Wenn das angegebene Daten ung�ltig ist, wird erneut eingelesen, solange
    bis ein g�ltiges Datum eingegeben wurde.
*/
void input_date(int* day, int* month, int* year)
{
    /*  Schleife von Eingaben
    *   Wenn das Datum existiert, wird die Identifikationsvariable succesful auf 1 gesetzt.
    */

    int successful = 0;
    do
    {
        printf("Tag: ");
        scanf("%i", &day);
        fflush(stdin);

        printf("Monat: ");
        scanf("%i", &month);
        fflush(stdin);

        printf("Jahr: ");
        scanf("%i", &year);
        fflush(stdin);

        if(exists_date(*day, *month, *year) == 1)
        {
            successful = 1;
        }
        else
        {
            printf("Das eingegebene Datum ist nicht gueltig!\n\r");
        }

    } while (!successful);
}

/*
    Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des
    gregorianischen Kalenders ein Schaltjahr ist. Bei Jahreszahlen
    vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
    R�ckgabewerte:
    1, wenn �bergebenes Jahr ein Schaltjahr ist
    0, wenn �bergebenes Jahr kein Schaltjahr ist
    -1, wenn ein ung�ltiges Jahr �bergeben wurde
*/
int is_leapyear(int year)
{
    // Jahre vor 1582 sind nicht im gregorianischen Kalender.
    if(year < 1582)
    {
        return ERROR;
    }

    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        else
        {
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}

/*
    Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele
    Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen.
    Schaltjahre werden ber�cksichtigt.
    R�ckgabewerte:
    1-31, wenn ein g�ltiger Monat eingegeben wurde
    -1, wenn ein ung�ltiger Monat oder ein ung�ltiges Jahr eingegeben wurde
*/
int get_days_for_month(int month, int year)
{
    if(month < 1 || month > 12)
    {
        return ERROR;
    }

    // Wenn das Schaltjahr nicht ermittelt werden kann, dann schlägt diese Funktion auch fehl.
    if(is_leapyear(year) == ERROR)
    {
        return ERROR;
    }

    int days_per_month[12] =
    {
        31,28,31,30,
        31,30,31,31,
        30,31,30,31
    };

    if(month == 2 && is_leapyear(year) == TRUE)
    {
        return 29;
    }
    else
    {
        return days_per_month[month - 1];
    }
}

/*
    Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist.
    Daten vor dem 1.1.1582 sind ung�ltig, genauso wie alle Daten nach dem
    31.12.2400.
    1, wenn g�ltig
    0, wenn ung�ltig
*/
int exists_date(int day, int month, int year)
{
    if(year < 1582 || year > 2400)
    {
        return FALSE;
    }

    if(month < 1 || month > 12)
    {
        return FALSE;
    }

    if(get_days_for_month(month, year) < day || day < 0)
    {
        return FALSE;
    }

    if(get_days_for_month(month, year) == ERROR)
    {
        return FALSE;
    }

    return TRUE;
}
