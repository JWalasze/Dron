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