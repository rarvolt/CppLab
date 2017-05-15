//
// Created by rarvolt on 28.04.17.
//

#ifndef CPP_LAB_DATA_H
#define CPP_LAB_DATA_H


class Data {
private:
    int dzien;
    int miesiac;
    int rok;

public:
    Data();
    Data(int d, int m, int r);
    ~Data();

    int operator==(const Data &wzor);

    int Dzien() const;
    int Miesiac() const;
    int Rok() const;

    void Ustaw(int d, int m, int r);
    void Wypisz() const;
    char *WypiszRR() const;
    void Wpisz();
    void koryguj();
    int porownaj(const Data &wzor) const;
};


#endif //CPP_LAB_DATA_H
