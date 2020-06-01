#ifndef PLASZCZYZNA__HH
#define PLASZCZYZNA__HH

#include "InterfejsRysowania.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Plaszczyzna : public InterfejsRysowania
{
    protected:
        double WymiarX;
        double WymiarY;
        //double WymiarZ;
        std::vector<std::vector<drawNS::Point3D>> punkty_plaszczyzny;
        Wektor<double,3> punkt_poczatkowy;
    public:
        Plaszczyzna();
        Plaszczyzna(double WymX, double WymY, double WspX, double Wspy, double WspZ);
        void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;
};


#endif