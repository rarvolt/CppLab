//
// Created by rarvolt on 28.04.17.
//

#include <iostream>
#include "Data.h"

int Data::Dzien() const {
    return dzien;
}

int Data::Miesiac() const {
    return miesiac;
}

int Data::Rok() const {
    return rok;
}

void Data::Ustaw(int d, int m, int r) {
    dzien = d;
    miesiac = m;
    rok = r;

    koryguj();
}

void Data::Wypisz() const {
    std::cout << dzien << "." << miesiac << "." << rok << std::endl;
}

void Data::Wpisz() {
    using std::cout;
    using std::cin;
    cout << "Dzien: ";
    cin >> dzien;
    cout << "Miesiac: ";
    cin >> miesiac;
    cout << "Rok: ";
    cin >> rok;

    koryguj();
}

void Data::koryguj() {
    if (dzien > 31) {
        miesiac += dzien / 31;
        dzien %= 31;
    }
    if (miesiac > 12) {
        rok += miesiac / 12;
        miesiac %= 12;
    }
}

int Data::porownaj(const Data &wzor) const {
    return ((dzien == wzor.dzien) &&
            (miesiac == wzor.miesiac) &&
            (rok == wzor.rok));
}
