//
// Created by rarvolt on 28.04.17.
//

#ifndef CPP_LAB_PRACOWNIK_H
#define CPP_LAB_PRACOWNIK_H


#include "Data.h"

class Pracownik {
private:
    char pszImie[25];
    char pszNazwisko[30];
    Data DataUrodzenia;

public:
    const char* Imie() const;
    const char* Nazwisko() const;

    void Imie(const char* nowe_imie);
    void Nazwisko(const char* nowe_nazwisko);
    void DataUrodz(int nowy_dzien, int nowy_miesiac, int nowy_rok);

    void Wypisz() const;
    void Wpisz();

    bool SprawdzImie(const char* por_imie) const;
    bool SprawdzNazwiko(const char* por_nazwisko) const;
};


#endif //CPP_LAB_PRACOWNIK_H
