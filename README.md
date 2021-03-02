## timelib von Nico Nowak
Im Auftrag von Christian Wichmann

## Konstanten
- (Symbolisch) ERROR -1
- (Symbolisch) TRUE 1
- (Symbolisch) FALSE 0

## Strukturen
### struct date
#### int day
#### int month
#### int year
Beinhaltet die Daten und Werte, die für ein Datum notwendig sind. (Tag, Monat, Jahr)

## Funktionen
### int day_of_the_year(struct date)
Berechnet für ein gegebenes Datum des gregorianischen Kalenders die Nummer des Tages.

### void input_date(struct date *)
Übernimmt das Einlesen und Speichern der Nutzereingabe des Datums.
Der Funktion wird ein Pointer einer date-Struktur übergeben.

### int is_leapyear(int)
Überprüft ob ein Jahr ein Schaltjahr ist. Gibt 1 zurück, wenn es ein Schaltjahr ist, 0 wenn nicht, -1 wenn das eingegebene Jahr ungültig ist.
Jahre vor 1582 sind ungültig.

### int get_days_for_month(int, int)
