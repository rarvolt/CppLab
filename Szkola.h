//
// Created by rarvolt on 15.05.17.
//

#ifndef CPP_LAB_SZKOLA_H
#define CPP_LAB_SZKOLA_H


#include "Nauczyciel.h"

class Szkola {
private:
    Nauczyciel *nauczyciele[20];
    int ile;
    char *nazwa_szkoly;

public:
    Szkola(const Nauczyciel *nauczyciele, int nowe_ile, const char *nowa_nazwa_szkoly);
    Szkola(const char *nowa_nazwa_szkoly);
    ~Szkola();

    int Dodaj_nauczyciela(const Nauczyciel &nauczyciel);
    void Usun_nauczyciela(int n);
    int Znajdz(const char *nazwisko);
    void Wyswietl(int n);
    void Lista();
};


#endif //CPP_LAB_SZKOLA_H
