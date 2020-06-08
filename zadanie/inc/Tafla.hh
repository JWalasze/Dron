#ifndef TAFLA__HH
#define TAFLA__HH

#include "Przeszkoda.hh"
#include "Plaszczyzna.hh"

class Tafla: public Plaszczyzna, public Przeszkoda
{
    protected:

    double wysokosc;
        
    public:
        Tafla() = delete;
        Tafla(double WymX, double WymY, double WymZ) : Plaszczyzna(WymX,WymY,0,0,WymZ), wysokosc(WymZ) {}
        bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
};


#endif