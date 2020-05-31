#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Sruba.hh"
#include "InterfejsDrona.hh"

class Dron : public Prostopadloscian, public InterfejsDrona
{
    protected:
        Sruba Lewa;
        /*!
        *\brief lewa sruba wirnika
        */
        Sruba Prawa;
        /*!
        *\brief prawa sruba wirnika
        */
        double Promien;
    public:
        Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ) : Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ){}
        /*!
        *\brief konstruktor sruby
        *\param WspX - wspolrzedna x srodka
        *\param WspY - wspolrzedna y srodka
        *\param WspZ - wspolrzedna z srodka
        *\param WymX - dlugosc drona
        *\param WymZ - wysokosc drona
        *\param WymY - szerokosc drona
        */
        void Set_Lewa(Sruba L) {Lewa = L;}
        /*!
        *\brief ustawia srube lewa
        *\param L - sruba drona
        */
        void Set_Prawa(Sruba P) {Prawa = P;}
        /*!
        *\brief ustawia srube prawa
        *\param L - sruba drona
        */

        void plyn_dronem(double odleglosc, double kat);
        /*!
        *\brief plynie dronem 
        *\param odleglosc - na jaka przesunie sie dron
        *\param kat - na jaki sie wznosi lub opada
        */
        void obroc_dron(double kat);
        /*!
        *\brief obraca dron wzgledem osi Z
        *\param kat - o jaki sie obroci
        */
        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
        /*!
        *\brief rysuje drona wraz z srubami
        */
        double zwroc_promien()const override;

        Wektor<double,3> zwroc_srodek()const override;
};


#endif