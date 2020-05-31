#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"


class InterfejsRysowania : public Prostopadloscian, public Graniastoslup
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
       //void AnimacjaRuchu(double odleglosc, double kat);
       //void AnimacjaObrotu(double kat);

       //void rysuj(std::shared_ptr<drawNS::Draw3DAPI> & api) override;

};

#endif