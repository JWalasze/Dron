#include "Tafla.hh"

bool Tafla::czy_kolizja(std::shared_ptr<InterfejsDrona> D)
{
    if(std::abs(D->zwroc_srodek()[2] - wysokosc) == 0 )
    {
        return 1;
    }
    else
    {
        if(D->zwroc_srodek()[2] > wysokosc)
        {
            return 1;
        }
    }
    return 0;
}
