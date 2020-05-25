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
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-30,30,-30,30,-30,30,1000)); 
  api->change_ref_time_ms(-1);

  wait4key();

  InterfejsRysowania Interfejs;
  Interfejs.UstawDno(api);
  Interfejs.UstawTafle(api);
  api->redraw();

  wait4key();
  
  Dron D(0,0,0,20,12,8);
  Sruba G(-10,-3,0,3,4);
  Sruba G1(-10,3,0,3,4);
  
  D.Set_Lewa(G);
  D.Set_Prawa(G1);
  D.rysuj(api);
  api->redraw();

  wait4key();
  D.obroc_dron(0);
  D.plyn_dronem(5,0);
  D.rysuj(api);
  api->redraw();

  wait4key();

  D.obroc_dron(0);
  D.plyn_dronem(4,0);
  D.rysuj(api);
  api->redraw();

  wait4key();

  D.obroc_dron(40);
  D.plyn_dronem(3,0);
  D.rysuj(api);
  api->redraw();
  
  wait4key();
  
  
}