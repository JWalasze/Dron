#include "Plaszczyzna.hh"

void Plaszczyzna::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->draw_surface(punkty_plaszczyzny, "blue");
}

Plaszczyzna::Plaszczyzna(double WymX, double WymY, double WspX, double WspY, double WspZ) : WymiarX(WymX), WymiarY(WymY), punkt_poczatkowy(WspX,WspY,WspZ)
{
    double x=(-0.5)*WymiarX;
    double y=(-0.5)*WymiarY;
    Wektor<double,3> W;
    vector<Point3D> Temp;
    for(int i=0; i<=WymiarX/5; ++i)
    {
        Temp.clear();
        for(int j=0; j<=WymiarY/5; ++j)
        {
            W = Wektor<double,3>{x,y,0} + punkt_poczatkowy;
            Temp.push_back(Point3D(W[0],W[1],W[2]));
            y = y + 10;
        }
        y=-0.5*WymiarX;
        x = x + 10;
        punkty_plaszczyzny.push_back(Temp);
    }    
}

