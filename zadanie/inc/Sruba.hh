#ifndef SRUBA_HH
#define SRUBA_HH

#include "Graniastoslup.hh"

class Sruba : public Graniastoslup
{
    protected:
        Wektor<double,3> Przesuniecie_mocowania;
        /*!
        *\brief wektor na ktory sruba przesuwa sie wzgledem drona
        */
        MacierzOb Orientacja_mocowania;
        /*!
        *\brief Orientacja sruby wzgledem drona
        */
        double Kat_obrotu_sruby;
        /*!
        *\brief kat o jaki obraca sie sruba wokol wlasnej osi
        */
    public:
        Sruba() : Graniastoslup() {};
        /*!
        *\brief konstruktor domyslny
        */
        Sruba(double WspX, double WspY, double WspZ, double WymX, double WymZ);
        /*!
        *\brief konstruktor sruby
        *\param WspX - wspolrzedna x srodka
        *\param WspY - wspolrzedna y srodka
        *\param WspZ - wspolrzedna z srodka
        *\param WymX - dlugosc sruby
        *\param WymZ - wysokosc sruby
        */

        void obroc_z_dronem(MacierzOb Nowa_orientacja_drona);
        /*!
        *\brief obraca wirnik wzgledem drona
        *\param Nowa_orientacja_drona - nowa orientacja drona
        */
        void przesun_z_dronem(Wektor<double,3> Nowy_sr_drona, MacierzOb Nowa_orientacja_drona);
        /*!
        *\brief przesuwa wirnik wraz z dronem
        *\param Nowy_sr_drona - nowy srodek drona
        *\param Nowa_orientacja_drona - nowa orientacja drona
        */
};


#endif