#ifndef PLASZCZYZNA__HH
#define PLASZCZYZNA__HH

#include "InterfejsRysowania.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Plaszczyzna //: public InterfejsRysowania
{
    protected:
        double WymiarX;
        double WymiarY;
        Wektor<double,3> PunktPodstawowy;
        std::vector<std::vector<drawNS::Point3D>> punkty;
    public:
        Plaszczyzna(double WymX, double WymY, double X, double Y, double Z);
        void UstawPunkty();
        void Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api);
};


#endif