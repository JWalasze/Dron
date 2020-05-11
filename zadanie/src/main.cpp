#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "klasa.hh"
#include "cmath"

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
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms

  //api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  //int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  /*MacierzOb M(1.0472);
  cout << M << endl;
  MacierzOb Mac;
  cout << Mac << endl;*/

  Prostopadloscian P(0,0,0,1,2,3);
  int p=P.rysuj(api);
  P.obroc(20);
  api->erase_shape(p);
  P.rysuj(api);
  //api->redraw();

  
  //P.rysuj(api);
  
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
