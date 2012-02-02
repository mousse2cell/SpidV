/*
 * CellForce.cpp
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#include "CellForce.h"


CellForce::CellForce():Force() {
	// TODO Auto-generated constructor stub

}
CellForce::CellForce(const Cell * c1, const Cell * c2):c1(c1),c2(c2)
{
}
CellForce::~CellForce() {
	// TODO Auto-generated destructor stub
}


const Cell* CellForce::getC1() const
{
    return c1;
}

void CellForce::setC1(const Cell* c1)
{
    this->c1 = c1;
}

const Cell* CellForce::getC2() const
{
    return c2;
}

void CellForce::setC2(const Cell* c2)
{
    this->c2 = c2;
}

void CellForce::evalForce(Cell & c1, Cell & c2)
{

	switch (type)
	{
		case 1:
		{
			//evalAttractiveForce(c1,c2);
			break;
		}
		case 2:
		{
			evalRepulsiveForce(c1,c2);
			break;
		}
		default:{std::cout<<"Error, type unknown !"<<std::endl;break;}
	}
}

void CellForce::evalAttractiveForce(Cell & c1, Cell & c2)
{
	float eucliDist=fmax(c1.evalDistance(c2),1.0f);
	//float overlap=c1.evalOverlap(c2);
	float overlap=c1.evalOverlap(c2);
	//radius of the circle made by the intersection
	float intersectRadius=(1/(2*eucliDist))*sqrt(4*pow(eucliDist,2)*pow(c1.getRadius(),2)-pow(pow(eucliDist,2)-pow(c2.getRadius(),2)+pow(c1.getRadius(),2),2));
	CVector cv;
	if(overlap==0.0f){ this->setValueXyz(cv);return;}
	c1.addNeighborhood(&c2);
	cv.setX(c2.getCoord().getX()-c1.getCoord().getX());
	cv.setY(c2.getCoord().getY()-c1.getCoord().getY());
	cv.setZ(c2.getCoord().getZ()-c1.getCoord().getZ());
	cv=cv*ATTRACTIVE_CONST*(M_PI*pow(intersectRadius,2))/(pow(fmin(c1.getRadius(),c2.getRadius()),2)*M_PI);
	//cv.print();
	this->setValueXyz(cv);
	//std::cout<<"ATTdist :"<<eucliDist<<"\nOverlap"<<overlap<<"\nfact :"<<(M_PI*pow(intersectRadius,2))/(pow(fmin(c1.getRadius(),c2.getRadius()),2)*M_PI)<<std::endl;
}



void CellForce::evalRepulsiveForce(Cell & c1, Cell & c2)
{
	//float eucliDist=c1.evalDistance(c2);
	//if(eucliDist>1000) exit(0);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	if(overlap==0.0f){ this->setValueXyz(cv);return;}
	cv=c1.getCoord()/sqrt(pow(c1.getCoord().getX()-c2.getCoord().getX(),2)+pow(c1.getCoord().getY()-c2.getCoord().getY(),2)+pow(c1.getCoord().getZ()-c2.getCoord().getZ(),2));
	/*cv.setX(c1.getCoord().getX()-c2.getCoord().getX());
	cv.setY(c1.getCoord().getY()-c2.getCoord().getY());
	cv.setZ(c1.getCoord().getZ()-c2.getCoord().getZ());*/
	cv=cv*REPULSIVE_CONST*overlap;//(eucliDist/(c1.getRadius()+c2.getRadius()));
	this->setValueXyz(cv);
}


