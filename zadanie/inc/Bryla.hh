#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Bryla
{
    protected:
        Wektor<double,3> Wektor_Srodka;
        /*!
        *\brief srodek bryly
        */
        MacierzOb MacOrientacji;
        /*!
        *\brief aktualna orientacja bryly
        */
        int ind;
        /*!
        *\brief indeks kazdej bryly aby moc latwo jest usuwac
        */
    public:
        virtual void obroc(double kat, char kierunek) = 0;
        /*!
        *\brief wirtualna metoda na obracanie bryly
        *\param kat - obrot o ten kat
        *\param kierunek - obrot o wskazany kierunek
        */
        virtual void przesun(Wektor<double, 3> Wek_Trans) = 0;
        /*!
        *\brief wirtualna metoda na przesuwanie
        *\param Wek_Trans - wektor o jaki bryla sie przesunie
        */
        virtual void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) = 0;
        /*!
        *\brief wirtualna metoda na rysowanie bryly
        *\param api - umozliwia rysowania za pomoca gnuplota
        */
        int get_ind() const {return ind;}
        /*!
        *\brief zwraca indeks bryly
        *\param ind - indeks bryly
        */
};

#endif