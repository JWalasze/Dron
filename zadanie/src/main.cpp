#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Macierz.hh"
#include "Bryla.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "Sruba.hh"
#include "InterfejsRysowania.hh"
#include "Plaszczyzna.hh"
#include "PrzeszkodaProst.hh"
#include "Przeszkoda.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-40,40,-40,40,-40,40,1000)); 
  api->change_ref_time_ms(-1);

  vector<std::shared_ptr<Dron>> kolekcja_dronow;
  vector<std::shared_ptr<Przeszkoda>> kolekcja_przeszkod;

  PrzeszkodaProst Przeszkoda1(-20,20,-30,8,8,20);
  Przeszkoda1.rysuj(api);
  PrzeszkodaProst Przeszkoda2(20,-30,-10,5,5,60);
  Przeszkoda2.rysuj(api);
  PrzeszkodaProst Przeszkoda3(20,12,-20,20,5,40);
  Przeszkoda3.rysuj(api);
  PrzeszkodaProst Przeszkoda4(-30,-30,-30,5,5,20);
  Przeszkoda4.rysuj(api);


  

  Dron D(0,0,0,20,12,8);
  Sruba G(-10,-3,0,3,4);
  Sruba G1(-10,3,0,3,4);

  D.Set_Lewa(G);
  D.Set_Prawa(G1);
  D.rysuj(api);
  api->redraw();

  wait4key();

  char wybor;
  while(wybor!='k')
  {
    cout << "Dokonaj wyboru: ";
    cin >> wybor;
    cout << endl;
    {
      switch(wybor)
      {
        case 'p' : 
        {
          double dlugosc, kat;
          cout << "Podaj odleglosc - ";
          cin >> dlugosc;
          cout << endl;
          cout << "Podaj kat wznoszenia/opadania - ";
          cin >> kat;
          cout << endl;

          double x = dlugosc/1000;
          for(int i = 0; i<1000; ++i)
          {
            D.obroc_dron(0);
            D.plyn_dronem(x, kat);
            D.rysuj(api);
            api->redraw();
          }
        }
        break;

        case 'o' : 
        {
          double kat;
          cout << "Podaj kat obrotu - ";
          cin >> kat;
          cout << endl;

          double x = kat/1000;
          for(int i = 0; i<1000; ++i)
          {
            D.obroc_dron(x);
            D.plyn_dronem(0,0);
            D.rysuj(api);
            api->redraw();
          }
        }
        break;

        case 'k' : 
        {
          cout << "Koniec dzialania programu" << endl;
        }
        break;

        default : cout << "Niepoprawny wybor" << endl;
      }
    }
  }





}