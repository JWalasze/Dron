#ifndef DNO_HH
#define DNO__HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"

class Dno : public Plaszczyzna, public Przeszkoda
{
    protected:

        double wysokosc;
        
    public:
        Dno() = delete;
        Dno(double WymX, double WymY, double WymZ) : Plaszczyzna(WymX,WymY,0,0,WymZ), wysokosc(WymZ) {}
        bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;
        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
};


#endif