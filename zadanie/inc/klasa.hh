#ifndef KLASA_HH
#define KLASA_HH

#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class MacierzOb: public MacierzKw<double,3>
{
    protected:

        double kat;

    public:

        MacierzOb(double kat_omega) : kat(kat_omega)
        {
            int i=0;
            tab[i] = {cos(kat), sin(kat), 0};
            tab[++i] = {-sin(kat), cos(kat), 0};
            tab[++i] = {0,0,1};
        }
        
        MacierzOb() 
        {
            int i=0;
            tab[i] = {cos(0), -sin(0), 0};
            tab[++i] = {sin(0), cos(0), 0};
            tab[++i] = {0,0,1};
        }

        void set(double kat_omega){ (*this) = MacierzOb(kat_omega); }
        MacierzOb get(){ return *this; }

};


class Bryla
{
    protected:

        Wektor<double,3> Wektor_Srodka; //Wektor srodka 
        MacierzOb Mac;

    public:

        Bryla() : Wektor_Srodka(0,0,0), Mac() {}
        Bryla(double WspX, double WspY, double WspZ) : Wektor_Srodka(WspX, WspY, WspZ), Mac() {}

        virtual void obroc(double kat) = 0;
        virtual void przesun_na_wprost(Wektor<double, 3> Wek_Trans) = 0;

};


class Prostopadloscian: public Bryla
{
    protected:
        Wektor<double, 3> Wymiary;
        std::vector <Wektor<double, 3>> Wierzcholki = std::vector <Wektor<double, 3>>(8);
    public:

        Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ);

        virtual void obroc(double kat);

        virtual void przesun_na_wprost(Wektor<double, 3> Wek_Trans);

        int rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api);

};


class Graniastoslup6: public Bryla
{
    protected:

    public:






};

class InterfejRysowania: public Prostopadloscian ,public Graniastoslup6
{
    protected:
    //MacierzOb M;

    public:




};



#endif