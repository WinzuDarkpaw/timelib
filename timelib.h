#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED
/**

Timelib.h
Header-Datei für timelib.c
Beinhaltet Funktionsprototypen und symbolische Konstanten zum arbeiten mit
Daten.

Autor: Nico Nowak
Erstellungsdatum: 15.02.2021
**/

/**     FUNKTIONSPROTOTYPEN     **/

/*
    Prototyp
    Die Funktion berechnet für ein gegebens Datum des gregorianischen Kalendars
    bestehend aus Tag, Monat und Jahr die Nummer des Tages, gezählt von Jahresbeginn
    (1. Januar) an.
    Schaltjahre werden bei der Berechnung berücksichtigt. Ist das übergebene Datum
    ungültig, beträgt der Rückgabewert -1.
*/
int day_of_the_year(int day, int month, int year);

/*
    Prototyp
    Die Funktion liest 3 Ganzahlwerte (Integer) ein, für Tag, Monat und Jahr.
    Wenn das angegebene Daten ungültig ist, wird erneut eingelesen, solange
    bis ein gültiges Datum eingegeben wurde.
*/
void input_date(int* day, int* month, int* year);

/*
    Prototyp
    Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des
    gregorianischen Kalenders ein Schaltjahr ist. Bei Jahreszahlen
    vor dem Jahr 1582 wird ein Fehler zurückgegeben.
    Rückgabewerte:
    1, wenn übergebenes Jahr ein Schaltjahr ist
    0, wenn übergebenes Jahr kein Schaltjahr ist
    -1, wenn ein ungültiges Jahr übergeben wurde
*/
int is_leapyear(int year);

/*
    Prototyp
    Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele
    Tage der Monat hat. Der Wert des Monats muss zwischen 1 und 12 liegen.
    Schaltjahre werden berücksichtigt.
    Rückgabewerte:
    1-31, wenn ein gültiger Monat eingegeben wurde
    -1, wenn ein ungültiger Monat oder ein ungültiges Jahr eingegeben wurde
*/
int get_days_for_month(int month, int year);

/*
    Prototyp
    Die Funktion überprüft, ob ein eingegebenes Datum gültig ist.
    Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem
    31.12.2400.
    1, wenn gültig
    0, wenn ungültig
*/
int exists_date(int day, int month, int year);

#endif // TIMELIB_H_INCLUDED
