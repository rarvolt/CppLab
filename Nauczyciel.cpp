//
// Created by rarvolt on 15.05.17.
//

#include <cstring>
#include <iostream>
#include "Nauczyciel.h"

Nauczyciel::Nauczyciel() : Pracownik() {
    strcpy(przedmiot, "");
    staz = 0.0;
}

Nauczyciel::Nauczyciel(const char *nowe_imie, const char *nowe_nazwisko, const Data data_urodz,
                       const char *nowy_przedmiot, double nowy_staz)
        : Pracownik(nowe_imie, nowe_nazwisko, data_urodz){
    strcpy(przedmiot, nowy_przedmiot);
    staz = nowy_staz;
}

void Nauczyciel::Przedmiot(const char *nowy_przedmiot) {
    strcpy(przedmiot, nowy_przedmiot);
}

char *Nauczyciel::Przedmiot() const {
    return przedmiot;
}

void Nauczyciel::Staz(double nowy_staz) {
    staz = nowy_staz;
}

double Nauczyciel::Staz() const {
    return staz;
}

void Nauczyciel::WprowadzDane() {
    using std::cout;
    using std::cin;

    // Wczytywanie danych do klasy bazowej - Pracownik.Wpisz()
    Wpisz();

    cout << "Podaj predmiot: ";
    cin >> przedmiot;

    cout << "Podaj staż: ";
    cin >> staz;
}

char *Nauczyciel::Tabela() {
    char *tab = NULL;
    sprintf(tab, "%s | %s | %s | %s | %lf", Imie(), Nazwisko(), DataUrodz(), przedmiot, staz);
    return tab;
}

char *Nauczyciel::Wizytowka() {
    char *buf = NULL;
    const char *l1 = "Imię i nazwisko:";
    const char *l2 = "Data urodzenia:";
    const char *l3 = "Dane dodatkowe:";
    sprintf(buf, "%s %s %s\n%s %s\n%s %s %lf lat",
        l1, Imie(), Nazwisko(),
        l2, DataUrodz(),
        l3, przedmiot, staz);
    return buf;
}
