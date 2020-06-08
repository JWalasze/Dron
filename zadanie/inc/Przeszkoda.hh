#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDrona.hh"

class Przeszkoda
{
    public:

        virtual bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) = 0;
        //virtual void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) = 0;

};


#endif