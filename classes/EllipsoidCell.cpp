/*
 * EllipsoidCell.cpp
 *
 *  Created on: 19 oct. 2011
 *      Author: mobilette
 */

#include "EllipsoidCell.h"


EllipsoidCell::EllipsoidCell():Cell() {
	// TODO Auto-generated constructor stub
	resetBoxCol();
}
EllipsoidCell::EllipsoidCell(std::string id):Cell(id)
{
}

EllipsoidCell::EllipsoidCell(std::string id, CVector c)
{
	setID(id);
	setCoord(c);
	coord.setEmpty(true);
	origin=coord;
	resetBoxCol();
}
EllipsoidCell::EllipsoidCell(std::string id, int t,  CVector c)
{
	setID(id);
	setType(t);
	setCoord(c);
	resetBoxCol();
}

EllipsoidCell::EllipsoidCell(std::string id, int t, CVector c,std::vector<Force> f)
{
	setID(id);
	setType(t);
	setCoord(c);
	setForces(f);
	resetBoxCol();
}


EllipsoidCell::~EllipsoidCell() {
	// TODO Auto-generated destructor stub
}
float EllipsoidCell::getAxisX() const{
	return axisX;
}
float EllipsoidCell::getAxisY() const{
	return axisY;
}
float EllipsoidCell::getAxisZ() const{
	return axisZ;
}
float EllipsoidCell::getAzimuth() const{
	return azimuth;
}
float EllipsoidCell::getElevation() const{
	return elevation;
}


float EllipsoidCell::evalOverlap(EllipsoidCell & ec){
	//float overlap=overlap_ellipses(coord.getX(),coord.getY(),axisX,axisY,azimuth,ec.getCoord().getX(),ec.getCoord().getY(),ec.getAxisX(),ec.getAxisY(),ec.getAzimuth());
	return ec.getElevation();
}

