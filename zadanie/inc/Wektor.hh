#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
#include "LZespolona.hh"

using namespace std;

template <class TYP, int ROZMIAR>
class Wektor {
protected:
    TYP tab[ROZMIAR];

    //static int ilosc_wektorow;
    //static int calkowita_ilosc_wektorow;

  public:

    Wektor();

    Wektor(TYP tablica[]);

    Wektor(TYP x, TYP y, TYP z, TYP a, TYP b);

    Wektor(TYP x, TYP y, TYP z);

    //Wektor(const Wektor<TYP, ROZMIAR> & Wek);

    Wektor<TYP, ROZMIAR> operator + (const Wektor<TYP, ROZMIAR> & W2) const;
    Wektor<TYP, ROZMIAR> operator - (const Wektor<TYP, ROZMIAR> & W2) const;
    Wektor<TYP, ROZMIAR> operator * (TYP l) const;
    TYP operator * (const Wektor<TYP, ROZMIAR> & W2) const; //skalarnie
    Wektor<TYP, ROZMIAR> operator / (TYP l) const;

    double dlugosc() const;

    //static int zwroc_aktualne_wektory(){return ilosc_wektorow;}
    //static int zwroc_liczbe_wszystkich_wektorow(){return calkowita_ilosc_wektorow;}

    bool operator == (const Wektor<TYP, ROZMIAR> & W2) const;
    bool operator != (const Wektor<TYP, ROZMIAR> & W2) const;

    const TYP & operator [] (int index) const;
    TYP & operator [] (int index);

    const Wektor<TYP, ROZMIAR> & zamien_kolumny() const;
    void zamien_kolumny();

    //~Wektor(){--ilosc_wektorow;}
};

template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> operator * (double l, Wektor<TYP,ROZMIAR> W2);

template <class TYP, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, Wektor<TYP, ROZMIAR> &Wek);

template <class TYP, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const Wektor<TYP, ROZMIAR> &Wek);

#endif
