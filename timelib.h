#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED
/**

Timelib.h
Header-Datei f�r timelib.c
Beinhaltet Funktionsprototypen und symbolische Konstanten zum arbeiten mit
Daten.

Autor: Nico Nowak
Erstellungsdatum: 15.02.2021
**/

/**     SYMBOLISCHE KONSTANTEN  **/
#define TRUE 1
#define FALSE 0
#define ERROR -1

/**     FUNKTIONSPROTOTYPEN     **/

/*
    Prototyp
    Die Funktion berechnet f�r ein gegebens Datum des gregorianischen Kalendars
    bestehend aus Tag, Monat und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn
    (1. Januar) an.
    Schaltjahre werden bei der Berechnung ber�cksichtigt. Ist das �bergebene Datum
    ung�ltig, betr�gt der R�ckgabewert -1.
*/
int day_of_the_year(int day, int month, int year);

/*
    Prototyp
    Die Funktion liest 3 Ganzahlwerte (Integer) ein, f�r Tag, Monat und Jahr.
    Wenn das angegebene Daten ung�ltig ist, wird erneut eingelesen, solange
    bis ein g�ltiges Datum eingegeben wurde.
*/
void input_date(int* day, int* month, int* year);

/*
    Prototyp
    Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des
    gregorianischen Kalenders ein Schaltjahr ist. Bei Jahreszahlen
    vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
    R�ckgabewerte:
    1, wenn �bergebenes Jahr ein Schaltjahr ist
    0, wenn �bergebenes Jahr kein Schaltjahr ist
    -1, wenn ein ung�ltiges Jahr �bergeben wurde
*/
int is_leapyear(int year);

/*
    Prototyp
    Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele
    Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen.
    Schaltjahre werden ber�cksichtigt.
    R�ckgabewerte:
    1-31, wenn ein g�ltiger Monat eingegeben wurde
    -1, wenn ein ung�ltiger Monat oder ein ung�ltiges Jahr eingegeben wurde
*/
int get_days_for_month(int month, int year);

/*
    Prototyp
    Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist.
    Daten vor dem 1.1.1582 sind ung�ltig, genauso wie alle Daten nach dem
    31.12.2400.
    1, wenn g�ltig
    0, wenn ung�ltig
*/
int exists_date(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED
