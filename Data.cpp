//
// Created by rarvolt on 28.04.17.
//

#include <iostream>
#include "Data.h"

/**
 * Zwraca zawartość składowej zmiennej dzien.
 */
int Data::Dzien() const {
    return dzien;
}

/**
 * Zwraca zawartość składowej zmiennej miesiac.
 */
int Data::Miesiac() const {
    return miesiac;
}

/**
 * Zwraca zawartość składowej zmiennej rok.
 */
int Data::Rok() const {
    return rok;
}

/**
 * Ustawia wartości składowych zmiennych podanymi parametrami.
 * Następnie dokonuje korekcji daty za pomocą funkcji koryguj().
 * @param d Dzień
 * @param m Miesiąc
 * @param r Rok
 */
void Data::Ustaw(int d, int m, int r) {
    dzien = d;
    miesiac = m;
    rok = r;

    koryguj();
}

/**
 * Wypisuje datę w formacie dd.mm.rrrr
 */
void Data::Wypisz() const {
    std::cout << dzien << "." << miesiac << "." << rok << std::endl;
}


char *Data::WypiszRR() const {
    char *buf = NULL;
    sprintf(buf, "%2d.%2d.%2d", dzien, miesiac, rok);
    return buf;
}


/**
 * Pobiera od użytkownika dzień, miesiąc i rok,
 * następnie wywołuje unkcję koryguj().
 */
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

/**
 * Uproszczona funkcja korekcji daty.
 * Zamienia nadmiarowe dni w miesiące i nadmiarowe miesiące w lata.
 */
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

/**
 * Porównuje dwie daty
 * @param wzor Data do porównania
 * @return 1 jeśli równe, 0 jeśli różne
 */
int Data::porownaj(const Data &wzor) const {
    return ((dzien == wzor.dzien) &&
            (miesiac == wzor.miesiac) &&
            (rok == wzor.rok));
}

Data::Data() {
    dzien = 0;
    miesiac = 0;
    rok = 0;
}

Data::Data(int d, int m, int r) {
    dzien = d;
    miesiac = m;
    rok = r;
}

Data::~Data() {
}

int Data::operator==(const Data &wzor) {
    long long int dni1, dni2;
    dni1 = (((rok * 12) + miesiac) * 31) + dzien;
    dni2 = (((wzor.rok * 12) + wzor.miesiac) * 31) + wzor.dzien;

    if (dni1 > dni2)
        return 1;
    else if (dni1 < dni2)
        return 2;
    else
        return 0;
}
