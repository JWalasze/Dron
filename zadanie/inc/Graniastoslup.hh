#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "Bryla.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Graniastoslup : public Bryla
{
    protected:
        Wektor<double,3> Wymiary;
        /*!
        *\brief wymiary graniastoslupa
        */
        vector <Wektor<double, 3>> WierzcholkiLokalne = vector <Wektor<double, 3>>(12);
        /*!
        *\brief Wierzcholki lokalne graniastoslupa
        */
    public:
        Graniastoslup();
        /*!
        *\brief konstruktor domyslny
        */
        Graniastoslup(double WspX, double WspY, double WspZ, double WymX, double WymZ);
        /*!
        *\brief konstruktor graniastoslupa
        *\param WspX - wspolrzedna x srodka
        *\param WspY - wspolrzedna y srodka
        *\param WspZ - wspolrzedna z srodka
        *\param WymX - dlugosc graniastoslupa
        *\param WymZ - wysokosc graniastoslupa
        */

        void obroc(double kat, char kierunek) override;
        /*!
        *\brief metoda obracania graniastoslupa
        *\param kat - kat obrotu
        *\param kierunek - kierunek obrotu
        */
        void przesun(Wektor<double,3> Wek_Trans) override;
        /*!
        *\brief przesuwanie graniast.
        *\param Wek_Trans - wektor na jaki przesuwamy
        */
        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
        /*!
        *\brief rysowanie graniastoslupa
        *\param api - umozliwia rysowanie w gnuplocie
        */
};

#endif