#ifndef PRZESZKODAPROST__HH
#define PRZESZKODAPROSTA__HH

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"

class PrzeszkodaProst : public Przeszkoda, public Prostopadloscian
{
    protected:

    public:
        PrzeszkodaProst() = delete;
        PrzeszkodaProst(double WymX, double WymY, double WymZ, double WspX, double WspY, double WspZ);

        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;

};

#endif