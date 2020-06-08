#include "InterfejsRysowania.hh"

void InterfejsRysowania::odswiez_obiekt(std::shared_ptr<drawNS::Draw3DAPI> & api)
{
	api->redraw();
}
