#include "Sruba.hh"

void Sruba::obroc_z_dronem(MacierzOb Nowa_orientacja_drona)
{
    MacOrientacji = Nowa_orientacja_drona * Orientacja_mocowania;
    MacOrientacji = MacOrientacji * MacierzOb(Kat_obrotu_sruby, 'x');
    //Kat_obrotu_sruby += 1;
}

void Sruba::przesun_z_dronem(Wektor<double,3> Nowy_sr_drona, MacierzOb Nowa_orientacja_drona)
{
    Wektor_Srodka = Nowy_sr_drona + Nowa_orientacja_drona * Przesuniecie_mocowania;
}

 Sruba::Sruba(double WspX, double WspY, double WspZ, double WymX, double WymZ) : Graniastoslup(WspX, WspY, WspZ, WymX, WymZ) //Orientacja_mocowania(90,'y')
 {
     Orientacja_mocowania = MacierzOb(0, 'z');
     Kat_obrotu_sruby = 30;
     Przesuniecie_mocowania = Wektor<double,3>(WspX,WspY,WspZ);
 }
