//
// Created by rarvolt on 15.05.17.
//

#ifndef CPP_LAB_NAUCZYCIEL_H
#define CPP_LAB_NAUCZYCIEL_H


#include "Pracownik.h"

class Nauczyciel: public Pracownik {
private:
    char *przedmiot;
    double staz;

public:
    Nauczyciel();
    Nauczyciel(const char *nowe_imie, const char* nowe_nazwisko, const Data data_urodz,
               const char *nowy_przedmiot, double nowy_staz);

    void Przedmiot(const char *nowy_przedmiot);
    char *Przedmiot() const;
    void Staz(double nowy_staz);
    double Staz() const;

    void WprowadzDane();
    char *Tabela();
    char *Wizytowka();
};


#endif //CPP_LAB_NAUCZYCIEL_H
