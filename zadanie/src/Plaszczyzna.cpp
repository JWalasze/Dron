#include "Plaszczyzna.hh"

void Plaszczyzna::UstawPunkty()
{
    double x=-0.5*WymiarX, y=-0.5*WymiarY;
    Wektor<double,3> wek1;
    vector<Point3D> Temp;
    for(int i=0; i<=WymiarY/5; ++i)
    {
        Temp.clear();
        for(int j=0; j<=WymiarX/5; ++j)
        {
            wek1=Wektor<double,3>{x,y,0} + PunktPodstawowy;
            Temp.push_back(Point3D(wek1[0],wek1[1],wek1[2]));
            y+=5;
        }
        y=-0.5*WymiarX;
        x+=5;
        punkty.push_back(Temp);
    }    
}  

void Plaszczyzna::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->draw_surface(punkty, "grey");
}

Plaszczyzna::Plaszczyzna(double WymX, double WymY, double X, double Y, double Z) : 
    WymiarX(WymX), WymiarY(WymY), PunktPodstawowy({X,Y,Z})
{
    UstawPunkty();
}

