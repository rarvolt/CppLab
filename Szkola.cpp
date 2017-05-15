//
// Created by rarvolt on 15.05.17.
//

#include <cstring>
#include <iostream>
#include "Szkola.h"

Szkola::Szkola(const Nauczyciel *nowi_nauczyciele, int nowe_ile, const char *nowa_nazwa_szkoly) {
    for (int i = 0; i < 20; ++i) {
        nauczyciele[i] = NULL;
    }
    for (int i = 0; i < nowe_ile; ++i) {
        Dodaj_nauczyciela(nowi_nauczyciele[i]);
    }

    strcpy(nazwa_szkoly, nowa_nazwa_szkoly);
}

Szkola::Szkola(const char *nowa_nazwa_szkoly) {
    for (int i = 0; i < 20; ++i) {
        nauczyciele[i] = NULL;
    }
    strcpy(nazwa_szkoly, nowa_nazwa_szkoly);
}

Szkola::~Szkola() {
    for (int i = 0; i < 20; ++i) {
        if (nauczyciele[i])
            delete nauczyciele[i];
    }
}

int Szkola::Dodaj_nauczyciela(const Nauczyciel &nauczyciel) {
    for (int i = 0; i < ile; ++i) {
        if (nauczyciele != NULL) {
            nauczyciele[i] = new Nauczyciel(nauczyciel);
            return i;
        }
    }
}

void Szkola::Usun_nauczyciela(int n) {
    if (nauczyciele[n])
        delete nauczyciele[n];
    nauczyciele[n] = NULL;
}

int Szkola::Znajdz(const char *nazwisko) {
    for (int i = 0; i < ile; ++i) {
        if (nauczyciele[i]->SprawdzNazwiko(nazwisko))
            return i;
    }
    return 0;
}

void Szkola::Wyswietl(int n) {
    std::cout << nauczyciele[n]->Tabela() std::endl;
}

void Szkola::Lista() {
    using std::cout;
    using std::endl;

    cout << "Nazwa szkoły: " << nazwa_szkoly << endl;

    for (int i = 0; i < ile; ++i) {
        cout << nauczyciele[i]->Tabela() << endl;
    }
}
