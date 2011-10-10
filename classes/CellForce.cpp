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

void CellForce::evalForce(const Cell & c1, const Cell & c2)
{

	switch (type)
	{
		case 1:
		{
			evalAttractiveForce(c1,c2);
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

void CellForce::evalAttractiveForce(const Cell & c1, const Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	cv.setX(c1.getCoord().getX()-c2.getCoord().getX());
	cv.setY(c1.getCoord().getY()-c2.getCoord().getY());
	cv.setZ(c1.getCoord().getZ()-c2.getCoord().getZ());
	cv=cv*ATTRACTIVE_CONST*(overlap/eucliDist);
	this->setValueXyz(cv);
}



void CellForce::evalRepulsiveForce(const Cell & c1, const Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	cv.setX(c2.getCoord().getX()-c1.getCoord().getX());
	cv.setY(c2.getCoord().getY()-c1.getCoord().getY());
	cv.setZ(c2.getCoord().getZ()-c1.getCoord().getZ());
	cv=cv*REPULSIVE_CONST*(overlap/eucliDist);
	this->setValueXyz(cv);
}


