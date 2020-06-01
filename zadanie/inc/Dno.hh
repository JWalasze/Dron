#ifndef DNO_HH
#define DNO__HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"

class Dno : public Plaszczyzna, public Przeszkoda
{
    protected:
        double WymiarZ;
    public:
        Dno() = delete;
        //Dno(double WymX, double WymY, double WymZ) : Plaszczyzna(WymX,WymY), WymiarZ(WymZ){}
        bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
};


#endif