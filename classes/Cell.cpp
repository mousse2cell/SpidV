#include "Cell.h"
#include <math.h>
#include <string>
#include <iostream>


using namespace std;
Cell::Cell(void)
{
	resetBoxCol();
}

Cell::Cell(int t, double r, CVector c):type(t), radius(r), coord(c)
{
	resetBoxCol();
}

Cell::Cell(int t, double r, CVector c,std::vector<Force> f):type(t), radius(r), coord(c), forces(f)
{
	resetBoxCol();
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

void Cell::setForces(std::vector<Force> forces)
{
	this->forces=forces;
}

std::vector<Force> Cell::getForces() const
{
	return this->forces;
}

float Cell::evalDistance(const Cell & c) const
{
	return sqrt(pow(coord.getX()-c.coord.getX(),2.0f)+pow(coord.getY()-c.coord.getY(),2.0f)+pow(coord.getZ()-c.coord.getZ(),2.0f));
}
float Cell::evalOverlap(const Cell & c) const
{
	float dist=evalDistance(c);
	//std::cout<<"dist :"<<dist<<endl;
	float val=this->radius+c.getRadius()-dist;
	return fmax(val,0.0f);
}

void Cell::printCell() const{
	cout<<"coord :"<<this->coord.getX()<<", "<<this->coord.getY()<<", "<<this->coord.getZ()<<endl<<"Adress :"<<this<<endl;
	/*if(forces.size()>0){
		for(unsigned int i=0;i<forces.size();i++){
			cout<<"force : "<<forces[i].getType()<<endl;
		}
	}*/
}

void Cell::checkAndSetForceWith(const Cell & c2)
{
	CellForce f(this,&c2);
	for(int i=1;i<=Force::AVAILABLE_FORCE.size()+1;i++){
		f.setType(i);
		f.evalForce(*this,c2);
		if(!f.getValueXyz().containsOnly(0.0f)){
			this->addForce(f);
		}
	}
}



void Cell::addForce(Force & f)
{
	this->forces.push_back(f);
}

void Cell::applyForces()
{
	bool move=false;
	CVector cv;
	for(unsigned int i=0;i<forces.size();i++){
		move=true;
		cv=cv+forces[i].getValueXyz();
	}
	if((WL && cv.getX()<0) || (WR && cv.getX()>0)) cv.setX(0.0f);
	if((HL && cv.getY()<0) || (HR && cv.getY()>0)) cv.setY(0.0f);
	if((DL && cv.getZ()<0) || (DR && cv.getZ()>0)) cv.setZ(0.0f);
//	this->coord.print();
	//(cv+this->coord).print();
	forces.clear();
	if(move) setCoord(cv+this->coord);
}

void Cell::checkAndSetForceWith(const Box & c)
{
	BoxForce f;
	for(int i=1;i<=Force::AVAILABLE_FORCE.size()+1;i++){
		f.setType(i);
		f.evalForce(*this,c);
		if(!f.getValueXyz().containsOnly(0.0f)){
			this->addForce(f);
		}
	}
}

void Cell::moveTo(float x, float y, float z)
{
	this->coord.setX(x);
	this->coord.setY(y);
	this->coord.setZ(z);
}

bool Cell::isDl() const
{
    return DL;
}

bool Cell::isDr() const
{
    return DR;
}

bool Cell::isHl() const
{
    return HL;
}

bool Cell::isHr() const
{
    return HR;
}

bool Cell::isWl() const
{
    return WL;
}

bool Cell::isWr() const
{
    return WR;
}

void Cell::setDl(bool dl)
{
    DL = dl;
}

void Cell::setDr(bool dr)
{
    DR = dr;
}

void Cell::setHl(bool hl)
{
    HL = hl;
}

void Cell::setHr(bool hr)
{
    HR = hr;
}

void Cell::setWl(bool wl)
{
    WL = wl;
}

void Cell::setWr(bool wr)
{
    WR = wr;
}

void Cell::resetBoxCol()
{
	WR = false;
	WL = false;
	DR = false;
	DL = false;
	HR = false;
	HL = false;
}









