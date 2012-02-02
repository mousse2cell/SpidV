#include "Cell.h"
#include <math.h>
#include <string>
#include <iostream>
#include "Box.h"

using namespace std;
Cell::Cell(void)
{
	coord.setEmpty(true);
	resetBoxCol();
}

Cell::Cell(std::string id):ID(id)
{
	coord.setEmpty(true);
	resetBoxCol();
}

Cell::Cell(std::string id, float r, CVector c):ID(id), radius(r), coord(c)
{
	coord.setEmpty(true);
	origin=coord;
	resetBoxCol();
}
Cell::Cell(std::string id, int t, float r, CVector c):ID(id), type(t), radius(r), coord(c)
{
	resetBoxCol();
}

Cell::Cell(std::string id, int t, float r, CVector c,std::vector<Force> f):ID(id), type(t), radius(r), coord(c), forces(f)
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
CVector Cell::getOrigin() const{
	return this->origin;
}
float Cell::getRadius() const
{
	return this->radius;
}

void Cell::setRadius(float radius)
{
	this->radius=radius;
}

void Cell::setType(int type)
{
	this->type=type;
}

void Cell::setCoord(CVector coord)
{
	if(this->coord.isEmpty()) origin=coord;
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
	return coord.distanceTo(c.getCoord());
}
float Cell::evalOverlap(const Cell & c) const
{
	float dist=evalDistance(c);

	float val=this->radius+c.getRadius()-dist;
	return fmax(val/2.0f,0.0f);
}

void Cell::printCell() const{
	cout<<"coord :"<<this->coord.getX()<<", "<<this->coord.getY()<<", "<<this->coord.getZ()<<endl<<"Adress :"<<this<<endl;
	/*if(forces.size()>0){
		for(unsigned int i=0;i<forces.size();i++){
			cout<<"force : "<<forces[i].getType()<<endl;
		}
	}*/
}

void Cell::checkAndSetForceWith(Cell & c2)
{
	CellForce f(this,&c2);
	for(unsigned int i=1;i<=Force::AVAILABLE_FORCE.size()+1;i++){
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
		//forces[i].getValueXyz().print();
	}
	if((WL && cv.getX()<0) || (WR && cv.getX()>0)) cv.setX(0.0f);
	if((HL && cv.getY()<0) || (HR && cv.getY()>0)) cv.setY(0.0f);
	if((DL && cv.getZ()<0) || (DR && cv.getZ()>0)) cv.setZ(0.0f);
//	this->coord.print();
	//(cv+this->coord).print();
	//cout<<"total "<<this->coord.getX()<<endl;
	//cv.print();
	forces.clear();
	if(move) setCoord(cv+this->coord);
}

void Cell::checkAndSetForceWith(Box & c)
{
	neighborhood.clear();
	BoxForce f;
	for(unsigned int i=1;i<=Force::AVAILABLE_FORCE.size()+1;i++){
		f.setType(i);
		f.evalForce(*this,c);
		if(!f.getValueXyz().containsOnly(0.0f)){
			this->addForce(f);
		}
	}
}

void Cell::checkAndSetForceWith(Sphere & c)
{
	neighborhood.clear();
	SphereForce f;
	for(unsigned int i=1;i<=Force::AVAILABLE_FORCE.size()+1;i++){
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
void Cell::setID(std::string id){
	ID=id;
}
std::string Cell::getID() const {
	return ID;
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




std::vector<Cell*>* Cell::splitIn(int val) const{
	std::vector<Cell*>* daughters=new std::vector<Cell*>;
	if(val==1){ return daughters;}
	if(val % 2) val-=1; // on accepte pas les chiffres impair
	CVector pt1;
	float theta=(float)(rand()%180);//-90;//elevation
	float phi=(float)(rand()%359);//azimuth;
	//on place les nouvelles cellules à un rayon r/2 de la cellule mere
	pt1.setX((radius/2)*sin(theta)*cos(phi));
	pt1.setY((radius/2)*sin(theta)*sin(phi));
	pt1.setZ((radius/2)*cos(theta));
	daughters->push_back(new Cell(ID+".1",radius,pt1+coord));
	pt1.reverseSign();
	daughters->push_back(new Cell(ID+".2",radius,pt1+coord));
	float locphi=phi+180;
	float interval=180/fmax((val-2)/2+1,1.0f);
	for(int i=1;i<=val-2;i+=2){
		locphi-=interval;
		pt1.setX((radius/2)*sin(theta)*cos(locphi));
		pt1.setY((radius/2)*sin(theta)*sin(locphi));
		pt1.setZ((radius/2)*cos(theta));
		daughters->push_back(new Cell(ID+"."+to_string(2+i),radius,pt1+coord));
		pt1.reverseSign();
		daughters->push_back(new Cell(ID+"."+to_string(3+i),radius,pt1+coord));
	}
	return daughters;
}
void Cell::setNeighborhood(const std::vector<Cell*> n){
	neighborhood=n;
}
std::vector<Cell*> Cell::getNeighborhood() const{
	return neighborhood;
}
void Cell::addNeighborhood(Cell* c){
	neighborhood.push_back(c);
}



