#include "Wektor.hh"
#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ) : Wymiary(WymX, WymY, WymZ)
        {
            Wektor_Srodka = {WspX, WspY, WspZ};
            Wektor<double, 3> Wektor_Przesuniecia1(-WymX/2, WymY/2, -WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia2( WymX/2, WymY/2, -WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia3(-WymX/2, -WymY/2, -WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia4( WymX/2, -WymY/2, -WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia5(-WymX/2, WymY/2, WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia6( WymX/2, WymY/2, WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia7(-WymX/2, -WymY/2, WymZ/2);
            Wektor<double, 3> Wektor_Przesuniecia8( WymX/2, -WymY/2, WymZ/2);
            WierzcholkiLokalne[0] = Wektor_Przesuniecia1;
            WierzcholkiLokalne[1] = Wektor_Przesuniecia2;
            WierzcholkiLokalne[2] = Wektor_Przesuniecia4;
            WierzcholkiLokalne[3] = Wektor_Przesuniecia3;
            WierzcholkiLokalne[4] = Wektor_Przesuniecia5;
            WierzcholkiLokalne[5] = Wektor_Przesuniecia6;
            WierzcholkiLokalne[6] = Wektor_Przesuniecia8;
            WierzcholkiLokalne[7] = Wektor_Przesuniecia7;
            
        }

void Prostopadloscian::obroc(double kat, char kierunek)
        {
            MacOrientacji = MacOrientacji * MacierzOb(kat,kierunek);
        }
void Prostopadloscian::przesun(Wektor<double, 3> Wek_Trans)
        {
            Wektor_Srodka = Wektor_Srodka + Wek_Trans;
        }       
void Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
        {
            api->erase_shape(ind);
            vector <Wektor<double,3>> WierzcholkiGlob = vector <Wektor<double, 3>>(8);
            for (int i = 0; i < 8; ++i)
            {
                WierzcholkiGlob[i] = MacOrientacji * WierzcholkiLokalne[i] + Wektor_Srodka;
            }
            ind = api->draw_polyhedron(vector<vector<Point3D>> {
            {
                drawNS::Point3D(WierzcholkiGlob[0][0],WierzcholkiGlob[0][1],WierzcholkiGlob[0][2]), 
                drawNS::Point3D(WierzcholkiGlob[1][0],WierzcholkiGlob[1][1],WierzcholkiGlob[1][2]),
                drawNS::Point3D(WierzcholkiGlob[2][0],WierzcholkiGlob[2][1],WierzcholkiGlob[2][2]),
                drawNS::Point3D(WierzcholkiGlob[3][0],WierzcholkiGlob[3][1],WierzcholkiGlob[3][2])},
            {
                drawNS::Point3D(WierzcholkiGlob[4][0],WierzcholkiGlob[4][1],WierzcholkiGlob[4][2]),
                drawNS::Point3D(WierzcholkiGlob[5][0],WierzcholkiGlob[5][1],WierzcholkiGlob[5][2]),
                drawNS::Point3D(WierzcholkiGlob[6][0],WierzcholkiGlob[6][1],WierzcholkiGlob[6][2]), 
                drawNS::Point3D(WierzcholkiGlob[7][0],WierzcholkiGlob[7][1],WierzcholkiGlob[7][2])}
            },"blue");
            
        }

        