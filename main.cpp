#include <iostream>
#include "Data.h"

int main() {
    using std::cout;
    using std::endl;

    Data data1;
    Data data2;
    Data data3;

    data1.Ustaw(17, 4, 2017);
    data2.Ustaw(23, 18, 2016);

    cout << "Podaj dzisiejsza date: " << endl;
    data3.Wpisz();

    cout << "data1: ";
    data1.Wypisz();

    cout << "data2: ";
    cout << "d=" << data2.Dzien() << ", m=" << data2.Miesiac() << ", r=" << data3.Rok() << endl;

    cout << "data3: ";
    data3.Wypisz();

    cout << "data1 " << (data1.porownaj(data3) ? "" : "nie ") << "jest rowne data3" << endl;
    cout << "data2 " << (data2.porownaj(data3) ? "" : "nie ") << "jest rowne data3" << endl;

    return 0;
}