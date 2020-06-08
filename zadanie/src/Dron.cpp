#include "Dron.hh"

void Dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    Prostopadloscian::rysuj(api);
    Lewa.rysuj(api);
    Prawa.rysuj(api);
}

void Dron::obroc_dron(double kat)
{
    MacOrientacji = MacOrientacji * MacierzOb(-kat, 'z');
    Lewa.obroc_z_dronem(MacOrientacji);
    Prawa.obroc_z_dronem(MacOrientacji);
}

void Dron::plyn_dronem(double odleglosc, double kat)
{
    Wektor_Srodka = Wektor_Srodka + MacOrientacji * MacierzOb(-kat, 'y') * Wektor<double,3>(odleglosc,0,0);
    Lewa.przesun_z_dronem(Wektor_Srodka, MacOrientacji);
    Prawa.przesun_z_dronem(Wektor_Srodka, MacOrientacji);
}

double Dron::zwroc_promien()const
{
    return Promien;
}

Wektor<double,3> Dron::zwroc_srodek()const
{
    return Wektor_Srodka;
}

double Dron::zwroc_wymiarX()const
{
    return Wymiary[0];
}

double Dron::zwroc_wymiarY()const
{
    return Wymiary[1];
}

double Dron::zwroc_wymiarZ()const
{
    return Wymiary[2];
}

Dron::Dron(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ) : Prostopadloscian(WspX, WspY, WspZ, WymX, WymY, WymZ)
{
    Promien = sqrt( pow(WymX,2) + pow(WymY,2) + pow(WymZ,2) ) / 2;
    Blad_Promienia = Promien - (Wymiary[0] + Wymiary[1] + Wymiary[2])/6;
}

bool Dron::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if(std::abs(D->zwroc_srodek()[0] - Wektor_Srodka[0] ) <= ( D->zwroc_promien() + this->zwroc_promien() + Blad_Promienia ) )
    {
        if( std::abs(D->zwroc_srodek()[1] - Wektor_Srodka[1]) <= ( D->zwroc_promien() + this->zwroc_promien() + Blad_Promienia ) )
        {
            if( std::abs(D->zwroc_srodek()[2] - Wektor_Srodka[2]) <= ( D->zwroc_promien() + this->zwroc_promien() + Blad_Promienia ) )
            {
                return true;
            }
        }
    }
    else 
    {
        return false;
    }
}


