#ifndef TAFLA__HH
#define TAFLA__HH

#include "Przeszkoda.hh"
#include "Plaszczyzna.hh"

class Tafla: public Plaszczyzna, public Przeszkoda
{
    protected:
        double WymiarZ;
    public:
        Tafla();
        bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
};


#endif