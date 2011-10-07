#include "Force.h"
#include <iostream>

Force::Force(void):type(-1)
{
}
Force::Force(const Cell * c1, const Cell * c2):c1(c1),c2(c2)
{
}

Force::~Force(void)
{
}
Force::Force(int t):type(t)
{
}

const std::vector<int> Force::AVAILABLE_FORCE(1,2);

CVector Force::getValueXyz() const
{
    return valueXYZ;
}

void Force::setValueXyz(CVector valueXyz)
{
    valueXYZ = valueXyz;
}

int Force::getType() const
{
    return type;
}



void Force::setType(int type)
{
    this->type = type;
}

void Force::evalForce(const Cell & c1, const Cell & c2)
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

void Force::evalAttractiveForce(const Cell & c1, const Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	cv.setX(c1.getCoord().getX()-c2.getCoord().getX());
	cv.setY(c1.getCoord().getY()-c2.getCoord().getY());
	cv.setZ(c1.getCoord().getZ()-c2.getCoord().getZ());
	cv=cv*0.5*(overlap/eucliDist);
	this->setValueXyz(cv);
}



void Force::evalRepulsiveForce(const Cell & c1, const Cell & c2)
{
	float eucliDist=c1.evalDistance(c2);
	float overlap=c1.evalOverlap(c2);
	CVector cv;
	cv.setX(c2.getCoord().getX()-c1.getCoord().getX());
	cv.setY(c2.getCoord().getY()-c1.getCoord().getY());
	cv.setZ(c2.getCoord().getZ()-c1.getCoord().getZ());
	cv=cv*(overlap/eucliDist);
	this->setValueXyz(cv);
}

const Cell* Force::getC1() const
{
    return c1;
}

void Force::setC1(const Cell* c1)
{
    this->c1 = c1;
}

const Cell* Force::getC2() const
{
    return c2;
}


void Force::setC2(const Cell* c2)
{
    this->c2 = c2;
}













