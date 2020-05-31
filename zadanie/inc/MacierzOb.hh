#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"
#include <iostream>
#include <cmath>

#define PI 	3.141592

class MacierzOb: public MacierzKw<double, 3>
{
    public:

    MacierzOb() 
    {
        UstawMacierzObr(0, 'z');
    }
    /*!
    *\brief konstruktor bezparametrowy, tworzy macierz jednostkowa
    */ 

    MacierzOb(double kat, char kierunek)
    {
        UstawMacierzObr(kat, kierunek);
    }
    /*!
    *\brief konstruktor
    *\param kat - kat obrotu macierzy obrotu
    *\param kierunek - kierunek obrotu, czyli osi X,Y lub Z
    */

    MacierzOb(MacierzKw<double,3> Macierz)
    {
        tab[0]=Macierz[0];
        tab[1]=Macierz[1];
        tab[2]=Macierz[2];
    }
    /*!
    *\brief konstruktor
    *\param Macierz - jako parametr przyjmuje MacierzKw
    */

    void UstawMacierzObr(double kat, char kierunek);
    /*!
    *\brief ustawia macierz obrotu
    *\param kat - kat o jaki macierz ma obracac
    *\param kierunek - kierunek obrotu, czyli os X,Y lub Z
    */

};


#endif