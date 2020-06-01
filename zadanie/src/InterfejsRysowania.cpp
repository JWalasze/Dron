#include "InterfejsRysowania.hh"

/*void InterfejsRysowania::UstawDno(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-25,-25,25), drawNS::Point3D(-25,-12.5,25),drawNS::Point3D(-25,0,25), drawNS::Point3D(-25,12.5,25), drawNS::Point3D(-25,25,25)
	  },{
	drawNS::Point3D(-20,-25,21), drawNS::Point3D(-20,-12.5,21),drawNS::Point3D(-20,0,21), drawNS::Point3D(-20,12.5,21), drawNS::Point3D(-20,25,21)       
	  },{
    drawNS::Point3D(-15,-25,25), drawNS::Point3D(-15,-12.5,25),drawNS::Point3D(-15,0,25), drawNS::Point3D(-15,12.5,25), drawNS::Point3D(-15,25,25)       
	  },{
    drawNS::Point3D(-10,-25,21), drawNS::Point3D(-10,-12.5,21),drawNS::Point3D(-10,0,21), drawNS::Point3D(-10,12.5,21), drawNS::Point3D(-10,25,21)       
	  },{
    drawNS::Point3D(-5,-25,25), drawNS::Point3D(-5,-12.5,25),drawNS::Point3D(-5,0,25), drawNS::Point3D(-5,12.5,25), drawNS::Point3D(-5,25,25)       
	  },{
    drawNS::Point3D(0,-25,21), drawNS::Point3D(0,-12.5,21),drawNS::Point3D(0,0,21), drawNS::Point3D(0,12.5,21), drawNS::Point3D(0,25,21)       
	  },{
    drawNS::Point3D(5,-25,25), drawNS::Point3D(5,-12.5,25),drawNS::Point3D(5,0,25), drawNS::Point3D(5,12.5,25), drawNS::Point3D(5,25,25)       
	  },{
	drawNS::Point3D(10,-25,21), drawNS::Point3D(10,-12.5,21),drawNS::Point3D(10,0,21), drawNS::Point3D(10,12.5,21), drawNS::Point3D(10,25,21)      
	  },{
	drawNS::Point3D(15,-25,25), drawNS::Point3D(15,-12.5,25),drawNS::Point3D(15,0,25), drawNS::Point3D(15,12.5,25), drawNS::Point3D(15,25,25)       
	  },{
    drawNS::Point3D(20,-25,21), drawNS::Point3D(20,-12.5,21),drawNS::Point3D(20,0,21), drawNS::Point3D(20,12.5,21), drawNS::Point3D(20,25,21)       
	  },{
	drawNS::Point3D(25,-25,25), drawNS::Point3D(25,-12.5,25), drawNS::Point3D( 25,0,25), drawNS::Point3D(25,12.5,25), drawNS::Point3D(25,25,25)       
	  }},"blue");

    api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-25,-25,-25), drawNS::Point3D(-25,-12.5,-25),drawNS::Point3D(-25,0,-25), drawNS::Point3D(-25,12.5,-25), drawNS::Point3D(-25,25,-25)
	  },{
	drawNS::Point3D(-12.5,-25,-25), drawNS::Point3D(-12.5,-12.5,-25),drawNS::Point3D(-12.5,0,-25), drawNS::Point3D(-12.5,12.5,-25), drawNS::Point3D(-12.5,25,-25)       
	  },{
	drawNS::Point3D(-0,-25,-25), drawNS::Point3D(-0,-12.5,-25),drawNS::Point3D(0,0,-25), drawNS::Point3D(-0,12.5,-25), drawNS::Point3D(0,25,-25)      
	  },{
	drawNS::Point3D(12.5,-25,-25), drawNS::Point3D(12.5,-12.5,-25),drawNS::Point3D(12.5,0,-25), drawNS::Point3D(12.5,12.5,-25), drawNS::Point3D(12.5,25,-25)       
	  },{
	drawNS::Point3D(25,-25,-25), drawNS::Point3D(25,-12.5,-25), drawNS::Point3D( 25,0,-25), drawNS::Point3D(25,12.5,-25), drawNS::Point3D(25,25,-25)       
	  }},"grey");//rysuje szarą powierzchnie
}

void InterfejsRysowania::UstawTafle(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
    api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-25,-25,-25), drawNS::Point3D(-25,-12.5,-25),drawNS::Point3D(-25,0,-25), drawNS::Point3D(-25,12.5,-25), drawNS::Point3D(-25,25,-25)
	  },{
	drawNS::Point3D(-12.5,-25,-25), drawNS::Point3D(-12.5,-12.5,-25),drawNS::Point3D(-12.5,0,-25), drawNS::Point3D(-12.5,12.5,-25), drawNS::Point3D(-12.5,25,-25)       
	  },{
	drawNS::Point3D(-0,-25,-25), drawNS::Point3D(-0,-12.5,-25),drawNS::Point3D(0,0,-25), drawNS::Point3D(-0,12.5,-25), drawNS::Point3D(0,25,-25)      
	  },{
	drawNS::Point3D(12.5,-25,-25), drawNS::Point3D(12.5,-12.5,-25),drawNS::Point3D(12.5,0,-25), drawNS::Point3D(12.5,12.5,-25), drawNS::Point3D(12.5,25,-25)       
	  },{
	drawNS::Point3D(25,-25,-25), drawNS::Point3D(25,-12.5,-25), drawNS::Point3D( 25,0,-25), drawNS::Point3D(25,12.5,-25), drawNS::Point3D(25,25,-25)       
	  }},"grey");//rysuje szarą powierzchnie

    api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-25,-25,25), drawNS::Point3D(-25,-12.5,25),drawNS::Point3D(-25,0,25), drawNS::Point3D(-25,12.5,25), drawNS::Point3D(-25,25,25)
	  },{
	drawNS::Point3D(-20,-25,21), drawNS::Point3D(-20,-12.5,21),drawNS::Point3D(-20,0,21), drawNS::Point3D(-20,12.5,21), drawNS::Point3D(-20,25,21)       
	  },{
    drawNS::Point3D(-15,-25,25), drawNS::Point3D(-15,-12.5,25),drawNS::Point3D(-15,0,25), drawNS::Point3D(-15,12.5,25), drawNS::Point3D(-15,25,25)       
	  },{
    drawNS::Point3D(-10,-25,21), drawNS::Point3D(-10,-12.5,21),drawNS::Point3D(-10,0,21), drawNS::Point3D(-10,12.5,21), drawNS::Point3D(-10,25,21)       
	  },{
    drawNS::Point3D(-5,-25,25), drawNS::Point3D(-5,-12.5,25),drawNS::Point3D(-5,0,25), drawNS::Point3D(-5,12.5,25), drawNS::Point3D(-5,25,25)       
	  },{
    drawNS::Point3D(0,-25,21), drawNS::Point3D(0,-12.5,21),drawNS::Point3D(0,0,21), drawNS::Point3D(0,12.5,21), drawNS::Point3D(0,25,21)       
	  },{
    drawNS::Point3D(5,-25,25), drawNS::Point3D(5,-12.5,25),drawNS::Point3D(5,0,25), drawNS::Point3D(5,12.5,25), drawNS::Point3D(5,25,25)       
	  },{
	drawNS::Point3D(10,-25,21), drawNS::Point3D(10,-12.5,21),drawNS::Point3D(10,0,21), drawNS::Point3D(10,12.5,21), drawNS::Point3D(10,25,21)      
	  },{
	drawNS::Point3D(15,-25,25), drawNS::Point3D(15,-12.5,25),drawNS::Point3D(15,0,25), drawNS::Point3D(15,12.5,25), drawNS::Point3D(15,25,25)       
	  },{
    drawNS::Point3D(20,-25,21), drawNS::Point3D(20,-12.5,21),drawNS::Point3D(20,0,21), drawNS::Point3D(20,12.5,21), drawNS::Point3D(20,25,21)       
	  },{
	drawNS::Point3D(25,-25,25), drawNS::Point3D(25,-12.5,25), drawNS::Point3D( 25,0,25), drawNS::Point3D(25,12.5,25), drawNS::Point3D(25,25,25)       
	  }},"blue");
}*/

void InterfejsRysowania::odswiez_obiekt(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
	api->redraw();
}