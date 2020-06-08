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
#include "Tafla.hh"
#include "Dno.hh"

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

  /*PrzeszkodaProst Przeszkoda1(-20,20,-30,8,8,20);
  Przeszkoda1.rysuj(api);
  PrzeszkodaProst Przeszkoda2(20,-30,-10,5,5,60);
  Przeszkoda2.rysuj(api);
  PrzeszkodaProst Przeszkoda3(20,12,-20,20,5,40);
  Przeszkoda3.rysuj(api);
  PrzeszkodaProst Przeszkoda4(-30,-30,-30,5,5,20);
  Przeszkoda4.rysuj(api);*/


  Tafla woda(80,80,40);
  Dno dno(80,80,-40);
  //woda.rysuj(api);
  //dno.rysuj(api);

  //Dron D(0,0,0,20,12,8);
  Sruba G(-5,-1.5,0,1.5,2);
  Sruba G1(-5,1.5,0,1.5,2);

  Sruba G2(-5,-21.5,30,1.5,2);
  Sruba G3(-5,-18.5,30,1.5,2);

  //D.Set_Lewa(G);
  //D.Set_Prawa(G1);
  //D.rysuj(api);
  api->redraw();

  std::shared_ptr<Dron> D = std::make_shared<Dron>(0,0,0,10,6,4);
  std::shared_ptr<Dron> D1 = std::make_shared<Dron>(0,-20,30,10,6,4);
  D1->Set_Lewa(G2);
  D1->Set_Prawa(G3);
  D->Set_Lewa(G);
  D->Set_Prawa(G1);
  D->rysuj(api);
  D1->rysuj(api);
  api->redraw();

  std::shared_ptr<PrzeszkodaProst> P1 = std::make_shared<PrzeszkodaProst>(30,0,10,5,5,20);
  std::shared_ptr<PrzeszkodaProst> P2 = std::make_shared<PrzeszkodaProst>(-20,-10,-35,20,10,10);
  std::shared_ptr<PrzeszkodaProst> P3 = std::make_shared<PrzeszkodaProst>(20,-30,-10,5,5,60);
  std::shared_ptr<PrzeszkodaProst> P4 = std::make_shared<PrzeszkodaProst>(-20,20,-30,8,8,20);
  std::shared_ptr<Tafla> Woda = std::make_shared<Tafla>(80,80,35);
  std::shared_ptr<Dno> Dnoo = std::make_shared<Dno>(80,80,-40);
  P1->rysuj(api);
  P2->rysuj(api);
  P3->rysuj(api);
  P4->rysuj(api);
  Woda->rysuj(api);
  Dnoo->rysuj(api);
  api->redraw();

  kolekcja_przeszkod.push_back(P1);
  kolekcja_przeszkod.push_back(P2);
  kolekcja_przeszkod.push_back(P3);
  kolekcja_przeszkod.push_back(P4);
  kolekcja_przeszkod.push_back(Woda);
  kolekcja_przeszkod.push_back(Dnoo);
  kolekcja_przeszkod.push_back(D1);

  kolekcja_dronow.push_back(D);
  kolekcja_dronow.push_back(D1);

  for (auto elem : kolekcja_przeszkod)
  {
    elem->czy_kolizja(D);
  }

  wait4key();

  char wybor;
  while(wybor!='k')
  {
    //cout << "Aktualna ilosc wektorow: " << Wektor<double,3>::zwroc_aktualne_wektory() << endl;
    //cout << "Calkowita ilosc wektorow: " << Wektor<double,3>::zwroc_liczbe_wszystkich_wektorow() << endl;
    cout << "Dokonaj wyboru: ";
    cin >> wybor;
    cout << endl;
    {
      switch(wybor)
      {
        case 'p' : 
        {
          double kolizja = 0;
          double dlugosc, kat;
          cout << "Podaj odleglosc - ";
          cin >> dlugosc;
          cout << endl;
          cout << "Podaj kat wznoszenia/opadania - ";
          cin >> kat;
          cout << endl;

          double x = dlugosc/100;
          for(int i = 0; i<100; ++i)
          {
            D->obroc_dron(0);
            D->plyn_dronem(x, kat);
            for (auto elem : kolekcja_przeszkod)
            {
              if(elem->czy_kolizja(D))
              {
                D->obroc_dron(0);
                D->plyn_dronem(-x, kat);
                kolizja++;
              }
            }  
            D->rysuj(api);
            api->redraw();
          }
          if(kolizja!=0)
          {
            cout << "Wykryto przeszkode" << endl;
          }
        }
        break;

        case 'o' : 
        {
          double kolizja = 0;
          double kat;
          cout << "Podaj kat obrotu - ";
          cin >> kat;
          cout << endl;

          double x = kat/100;
          for(int i = 0; i<100; ++i)
          {
            D->obroc_dron(x);
            D->plyn_dronem(0,0);
            for (auto elem : kolekcja_przeszkod)
            {
              if(elem->czy_kolizja(D))
              {
                D->obroc_dron(-x);
                D->plyn_dronem(0,0);
                kolizja++;
              }
            }
            D->rysuj(api);
            api->redraw();
          }
          if(kolizja!=0)
          {
            cout << "Wykryto przeszkode" << endl;
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