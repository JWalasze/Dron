#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"


class InterfejsRysowania 
{
    protected:
    
    public:
        //void UstawDno(std::shared_ptr<drawNS::Draw3DAPI> & api);
        /*!
        *\brief ustawia dno w gnuplocie
        */
        //void UstawTafle(std::shared_ptr<drawNS::Draw3DAPI> & api);
        /*!
        *\brief ustawia tafle w gnuplocie
        */
       virtual void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) = 0;

       void odswiez_obiekt(std::shared_ptr<drawNS::Draw3DAPI> & api);
       
};

#endif