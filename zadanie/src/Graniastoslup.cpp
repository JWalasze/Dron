#include "Graniastoslup.hh"
#include "Wektor.hh"

Graniastoslup::Graniastoslup()
{
    Wektor<double,3> Przesuniecie1(1,0,1);
    Wektor_Srodka = {0,0,0};
    WierzcholkiLokalne[0] = Przesuniecie1;
    double kat1 = 60;
    for (int i = 1; i < 6; ++i)
    {
       WierzcholkiLokalne[i] = MacierzOb(kat1,'x') * Przesuniecie1;
       kat1+=60;
    }
    Wektor<double,3> Przesuniecie2(1,0,1);
    WierzcholkiLokalne[6] = Przesuniecie2;
    double kat2 = 60;
    for (int i = 7; i < 12; ++i)
    {
       WierzcholkiLokalne[i] = MacierzOb(kat2,'x') * Przesuniecie2;
       kat2+=60;
    }
}

Graniastoslup::Graniastoslup(double WspX, double WspY, double WspZ, double WymX, double WymZ)
{
    Wektor<double,3> Przesuniecie1(WymX/2,0,WymZ/2);
    Wektor_Srodka = {WspX, WspY, WspZ};
    WierzcholkiLokalne[0] = Przesuniecie1;
    double kat1 = 60;
    for (int i = 1; i < 6; ++i)
    {
       WierzcholkiLokalne[i] = MacierzOb(kat1,'x') * Przesuniecie1;
       kat1+=60;
    }
    Wektor<double,3> Przesuniecie2(-WymX/2,0,WymZ/2);
    WierzcholkiLokalne[6] = Przesuniecie2;
    double kat2 = 60;
    for (int i = 7; i < 12; ++i)
    {
       WierzcholkiLokalne[i] = MacierzOb(kat2,'x') * Przesuniecie2;
       kat2+=60;
    }
}

void Graniastoslup::obroc(double kat, char kierunek)
{
    MacOrientacji = MacOrientacji * MacierzOb(kat,kierunek);
}

void Graniastoslup::przesun(Wektor<double,3> Wek_Trans)
{
    Wektor_Srodka = Wektor_Srodka + Wek_Trans;
}

void Graniastoslup::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->erase_shape(ind);
    vector <Wektor<double,3>> WierzcholkiGlob = vector <Wektor<double, 3>>(12);
    for (int i = 0; i < 12; ++i)
    {
        WierzcholkiGlob[i] = MacOrientacji * WierzcholkiLokalne[i] + Wektor_Srodka;
    }
    ind = api->draw_polyhedron(vector<vector<Point3D>> {
    {
        drawNS::Point3D(WierzcholkiGlob[0][0],WierzcholkiGlob[0][1],WierzcholkiGlob[0][2]), 
        drawNS::Point3D(WierzcholkiGlob[1][0],WierzcholkiGlob[1][1],WierzcholkiGlob[1][2]),
        drawNS::Point3D(WierzcholkiGlob[2][0],WierzcholkiGlob[2][1],WierzcholkiGlob[2][2]),
        drawNS::Point3D(WierzcholkiGlob[3][0],WierzcholkiGlob[3][1],WierzcholkiGlob[3][2]),
        drawNS::Point3D(WierzcholkiGlob[4][0],WierzcholkiGlob[4][1],WierzcholkiGlob[4][2]),
        drawNS::Point3D(WierzcholkiGlob[5][0],WierzcholkiGlob[5][1],WierzcholkiGlob[5][2])},
    {
        drawNS::Point3D(WierzcholkiGlob[6][0],WierzcholkiGlob[6][1],WierzcholkiGlob[6][2]),
        drawNS::Point3D(WierzcholkiGlob[7][0],WierzcholkiGlob[7][1],WierzcholkiGlob[7][2]),
        drawNS::Point3D(WierzcholkiGlob[8][0],WierzcholkiGlob[8][1],WierzcholkiGlob[8][2]),
        drawNS::Point3D(WierzcholkiGlob[9][0],WierzcholkiGlob[9][1],WierzcholkiGlob[9][2]), 
        drawNS::Point3D(WierzcholkiGlob[10][0],WierzcholkiGlob[10][1],WierzcholkiGlob[10][2]),
        drawNS::Point3D(WierzcholkiGlob[11][0],WierzcholkiGlob[11][1],WierzcholkiGlob[11][2])}
    },"blue");
}

