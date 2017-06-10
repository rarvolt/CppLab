//
// Created by rarvolt on 28.04.17.
//

#include <cstring>
#include <iostream>
#include "Pracownik.h"

int Pracownik::siLiczPrac = 0;
int Pracownik::sNumer = 0;

/**
 * Zwraca wartość składowej zmiennej pszImie.
 */
const char *Pracownik::Imie() const {
    return pszImie;
}

/**
 * Zwraca wartość składowej zmiennej pszNazwisko.
 */
const char *Pracownik::Nazwisko() const {
    return pszNazwisko;
}

/**
 * Kopiuje zawartość zmiennej nowe_imie do składowej zmiennej pszImie.
 * @param nowe_imie
 */
void Pracownik::Imie(const char *nowe_imie) {
    strcpy(pszImie, nowe_imie);
}

/**
 * Kopiuje zawartość zmiennej nowe_nazwisko do składowej zmiennej pszNazwisko
 * @param nowe_nazwisko
 */
void Pracownik::Nazwisko(const char *nowe_nazwisko) {
    strcpy(pszNazwisko, nowe_nazwisko);
}

/**
 * Ustawia wartość składowej zmiennej DataUrodz
 * @param nowy_dzien
 * @param nowy_miesiac
 * @param nowy_rok
 */
void Pracownik::DataUrodz(int nowy_dzien, int nowy_miesiac, int nowy_rok) {
    DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

/**
 * Wypisuje na standardowe wyjście dane składowe w postaci:
 * imie     nazwisko    dd.mm.rrrr
 */
void Pracownik::Wypisz() const {
    std::cout << pszImie << "\t\t" << pszNazwisko << "\t\t" << id << "\t";
    DataUrodzenia.Wypisz();
}

/**
 * Pobiera od użytkownika wartości składowych zmiennych.
 */
void Pracownik::Wpisz() {
    using std::cout;
    using std::cin;

    char nowe_imie[50];
    char nowe_nazwisko[50];

    cout << "Podaj imie: ";
    cin >> nowe_imie;
    cout << "Podaj nazwisko: ";
    cin >> nowe_nazwisko;

    Imie(nowe_imie);
    Nazwisko(nowe_nazwisko);

    DataUrodzenia.Wpisz();
}

/**
 * Porównuje imię
 * @param por_imie Imię do porównania
 * @return true jeżeli równe, false w przeciwnym wypadku
 */
bool Pracownik::SprawdzImie(const char *por_imie) const {
    return strcmp(pszImie, por_imie) == 0;
}

/**
 * Porównuje nazwisko
 * @param por_nazwisko Nazwisko do porównania
 * @return true jeżeli równe, false w przeciwnym wypadku
 */
bool Pracownik::SprawdzNazwiko(const char *por_nazwisko) const {
    return strcmp(pszNazwisko, por_nazwisko) == 0;
}

Pracownik::Pracownik()
        : id(sNumer) {
    strcpy(pszImie, "");
    strcpy(pszNazwisko, "");
    DataUrodzenia = Data();
    ++siLiczPrac;
    ++sNumer;
}

Pracownik::Pracownik(const char *nowe_imie, const char *nowe_nazwisko, const Data data_urodz)
        : id(sNumer) {
    strcpy(pszImie, nowe_imie);
    strcpy(pszNazwisko, nowe_nazwisko);
    DataUrodzenia = data_urodz;
    ++siLiczPrac;
    ++sNumer;
}


Pracownik::Pracownik(const Pracownik &pracownik)
        : id(sNumer) {
    strcpy(pszImie, pracownik.pszImie);
    strcpy(pszNazwisko, pracownik.pszNazwisko);
    DataUrodzenia = pracownik.DataUrodzenia;
    ++siLiczPrac;
    ++sNumer;
}

Pracownik::~Pracownik() {
    --siLiczPrac;
    if (!siLiczPrac) {
        std::cout << "Usunięto ostatniego pracownika." << std::endl;
    }
}

Pracownik &Pracownik::operator=(const Pracownik &pracownik) {
    strcpy(pszImie, pracownik.pszImie);
    strcpy(pszNazwisko, pracownik.pszNazwisko);
    DataUrodzenia = pracownik.DataUrodzenia;
    return *this;
}

char *Pracownik::DataUrodz() const {
    return DataUrodzenia.WypiszRR();
}

int Pracownik::ID() {
    return id;
}
