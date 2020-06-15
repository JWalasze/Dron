#include "Tafla.hh"

bool Tafla::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if(std::abs(D->zwroc_srodek()[2] - wysokosc) == 0 )
    {
        return true;
    }
    else
    {
        if(D->zwroc_srodek()[2] > wysokosc)
        {
            return true;
        }
    }
    return false;
}
