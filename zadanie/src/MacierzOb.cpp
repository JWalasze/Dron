#include <iostream>
#include <cmath>
#include "MacierzOb.hh"

void MacierzOb::UstawMacierzObr(double kat, char kierunek)
{
        double alpha = (kat*PI)/180;
        switch (kierunek)
        {
        case 'z':
            tab[0] = {cos(alpha), sin(alpha), 0};
            tab[1] = {-sin(alpha), cos(alpha), 0};
            tab[2] = {0,0,1};
        break;
        case 'y':
            tab[0] = {cos(alpha), 0, -sin(alpha)};
            tab[1] = {0, 1, 0};
            tab[2] = {sin(alpha), 0, cos(alpha)};
        break;
        case 'x':
            tab[0] = {1, 0, 0};
            tab[1] = {0, cos(alpha), sin(alpha)};
            tab[2] = {0,-sin(alpha), cos(alpha)};
        break;
        default : cout << "Niepoprawny kierunek" << endl; 
        break;
        }
}
