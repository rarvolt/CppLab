//
// Created by rarvolt on 28.04.17.
//

#ifndef CPP_LAB_PRACOWNIK_H
#define CPP_LAB_PRACOWNIK_H


#include "Data.h"

class Pracownik {
private:
    static int siLiczPrac;

    char *pszImie;
    char *pszNazwisko;
    Data DataUrodzenia;

public:
    Pracownik();
    Pracownik(const char* nowe_imie, const char* nowe_nazwisko, const Data data_urodz);
    Pracownik(const Pracownik &pracownik);
    ~Pracownik();

    Pracownik &operator=(const Pracownik &pracownik);

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
