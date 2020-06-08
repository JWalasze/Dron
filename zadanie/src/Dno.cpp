#include "Dno.hh"

bool Dno::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if(std::abs(D->zwroc_srodek()[2] - wysokosc) <= D->zwroc_wymiarZ() )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void Dno::rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->draw_surface(punkty_plaszczyzny, "grey");
}
