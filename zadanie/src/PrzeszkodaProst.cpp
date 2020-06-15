#include "PrzeszkodaProst.hh"

PrzeszkodaProst::PrzeszkodaProst(double WspX, double WspY, double WspZ, double WymX, double WymY, double WymZ) : Prostopadloscian(WspX,WspY,WspZ,WymX,WymY,WymZ)
{
    Wektor_Srodka = {WspX,WspY,WspZ};
    //PromienBledu = (Wymiary[0] + Wymiary[1] + Wymiary[2])/3;
}

void PrzeszkodaProst::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
            vector <Wektor<double,3>> WierzcholkiGlob = vector <Wektor<double, 3>>(8);
            for (int i = 0; i < 8; ++i)
            {
                WierzcholkiGlob[i] = WierzcholkiLokalne[i] + Wektor_Srodka;
            }
            api->draw_polyhedron(vector<vector<Point3D>> {
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
            },"grey");
}

bool PrzeszkodaProst::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    PromienBledu = 1.5;

    if( std::abs(D->zwroc_srodek()[0] - Wektor_Srodka[0] ) <= ( D->zwroc_promien() + Wymiary[0]/2 + PromienBledu ) )
    {
        if( std::abs(D->zwroc_srodek()[1] - Wektor_Srodka[1]) <= ( D->zwroc_promien() + Wymiary[1]/2 ) )
        {
            if( std::abs(D->zwroc_srodek()[2] - Wektor_Srodka[2]) <= ( D->zwroc_promien() + Wymiary[2]/2 - PromienBledu ) )
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