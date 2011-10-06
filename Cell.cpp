#include "Cell.h"
#include <string>
#include <iostream>

using namespace std;
Cell::Cell(void)
{
}

Cell::Cell(int type, double radius, CVector coord):type(type), radius(radius), coord(coord)
{

}

Cell::Cell(int type, double radius, CVector coord,std::vector<Force> forces):type(type), radius(radius), coord(coord), forces(forces)
{

}
Cell::~Cell(void)
{
}

int Cell::getType() const
{
	return this->type;
}

CVector Cell::getCoord() const
{
	return this->coord;
}

double Cell::getRadius() const
{
	return this->radius;
}

void Cell::setRadius(double radius)
{
	this->radius=radius;
}

void Cell::setType(int type)
{
	this->type=type;
}

void Cell::setCoord(CVector coord)
{
	this->coord=coord;
}

void Cell::printCell() const{
	cout<<"coord :"<<this->coord.getX()<<", "<<this->coord.getY()<<", "<<this->coord.getZ()<<endl<<"Adress :"<<this<<endl;
}

