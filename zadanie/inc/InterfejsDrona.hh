#ifndef INTERFEJSDRONA__HH
#define INTERFEJSDRONA__HH

#include "Wektor.hh"
#include "Dron.hh"

class InterfejsDrona
{
    protected:

    public:
        virtual double zwroc_promien()const = 0;
        virtual Wektor<double,3> zwroc_srodek()const = 0;
};

#endif