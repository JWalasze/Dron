#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Prostopadloscian: public Bryla
{
    protected:
        Wektor<double, 3> Wymiary;
        /*!
        *\brief wymiary prostopadloscianu
        */
        vector <Wektor<double,3>> WierzcholkiLokalne = vector <Wektor<double,3>>(8);
        /*!
        *\brief wierzcholki lokalne
        */
        //double promien;
    public:
        Prostopadloscian();
        /*!
        *\brief konstruktor bezparametryczny
        */
        Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ);
        /*!
        *\brief konstruktor prostopadloscianu
        *\param WspX - wspolrzedna x srodka 
        *\param WspY - wspolrzedna y srodka
        *\param WspZ - wspolrzedna z srodka
        *\param WymX - wymiar x prostopadloscianu(dlugosc)
        *\param WymY - wymiar y prostopadloscianu(szerokosc)
        *\param WymZ - wymiar z prostopadloscianu(wysokosc)
        */

        void obroc(double kat, char kierunek) override;
        /*!
        *\brief metoda obracania prostopadloscianu
        *\param kat - kat obrotu
        *\param kierunek - kierunek obrotu
        */
        void przesun(Wektor<double, 3> Wek_Trans) override;
        /*!
        *\brief przesuwanie prostop.
        *\param Wek_Trans - wektor na jaki przesuwamy
        */
        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
        /*!
        *\brief rysowanie prostopadloscianu
        *\param api - umozliwia rysowanie w gnuplocie
        */
};

#endif