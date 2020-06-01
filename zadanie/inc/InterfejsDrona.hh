#ifndef INTERFEJSDRONA__HH
#define INTERFEJSDRONA__HH

#include "Wektor.hh"
#include "Dron.hh"

class InterfejsDrona
{
    protected:

    public:
        virtual void plyn_dronem(double odleglosc, double kat) = 0;
        virtual void obroc_dron(double kat) = 0;
        virtual void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) = 0;
        virtual double zwroc_promien()const = 0;
        virtual Wektor<double,3> zwroc_srodek()const = 0;
};

#endif