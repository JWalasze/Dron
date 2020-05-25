#ifndef INTERFEJSRYSOWANIA_HH
#define INTERFEJSRYSOWANIA_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"


class InterfejsRysowania //: public Prostopadloscian, public Graniastoslup
{
    protected:
    
    public:
        void UstawDno(std::shared_ptr<drawNS::Draw3DAPI> & api);
        /*!
        *\brief ustawia dno w gnuplocie
        */
        void UstawTafle(std::shared_ptr<drawNS::Draw3DAPI> & api);
        /*!
        *\brief ustawia tafle w gnuplocie
        */
};

#endif