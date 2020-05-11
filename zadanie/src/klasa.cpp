#include "Wektor.hh"
#include "klasa.hh"

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
            Wierzcholki[0] = Wektor_Srodka + Wektor_Przesuniecia1;
            Wierzcholki[1] = Wektor_Srodka + Wektor_Przesuniecia2;
            Wierzcholki[2] = Wektor_Srodka + Wektor_Przesuniecia3;
            Wierzcholki[3] = Wektor_Srodka + Wektor_Przesuniecia4;
            Wierzcholki[4] = Wektor_Srodka + Wektor_Przesuniecia5;
            Wierzcholki[5] = Wektor_Srodka + Wektor_Przesuniecia6;
            Wierzcholki[6] = Wektor_Srodka + Wektor_Przesuniecia7;
            Wierzcholki[7] = Wektor_Srodka + Wektor_Przesuniecia8;
            
        }

void Prostopadloscian::obroc(double kat)
        {
            Mac.set(kat);
            for(int i=0; i<8; ++i)
            {
                Wierzcholki[i] = Mac * ( Wierzcholki[i] );
            }
        }
void Prostopadloscian::przesun_na_wprost(Wektor<double, 3> Wek_Trans)
        {
            for(int i=0; i<8; ++i)
            {
                Wierzcholki[i] = Wierzcholki[i] + Wek_Trans;
            }
        }       
int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
        {
            api->draw_polyhedron(vector<vector<Point3D> > {{
            drawNS::Point3D(0,0,0), drawNS::Point3D(4,0,0), drawNS::Point3D(4,2,0), drawNS::Point3D(0,2,0)
            },{
            drawNS::Point3D(0,0,2), drawNS::Point3D(4,0,2), drawNS::Point3D(4,2,2), drawNS::Point3D(0,2,2)       
            }},"blue");
        }

        