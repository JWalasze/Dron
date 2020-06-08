#ifndef PRZESZKODAPROST__HH
#define PRZESZKODAPROSTA__HH

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class PrzeszkodaProst : public Prostopadloscian, public Przeszkoda
{
    protected:

        double PromienBledu;
        //double PromienBleduY;
        //double PromienBleduZ;

    public:
        PrzeszkodaProst() = delete;
        PrzeszkodaProst(double WymX, double WymY, double WymZ, double WspX, double WspY, double WspZ);

        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
        bool czy_kolizja(std::shared_ptr<InterfejsDrona> D) override;

};

#endif