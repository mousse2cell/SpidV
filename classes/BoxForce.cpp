/*
 * BoxForce.cpp
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#include "BoxForce.h"
#include <math.h>



BoxForce::BoxForce() {
	// TODO Auto-generated constructor stub

}

BoxForce::~BoxForce() {
	// TODO Auto-generated destructor stub
}



void BoxForce::evalForce(const Cell & c1, const Box & c2)
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

void BoxForce::evalAttractiveForce(const Cell & c1, const Box & c2)
{

}

void BoxForce::evalRepulsiveForce(const Cell & c1, const Box & b)
{
	float overlap_wl=sqrt(pow(c1.getCoord().getX()-c1.getRadius(),2.0f));
	float overlap_wr=sqrt(pow(b.getWidth()-c1.getCoord().getX()+c1.getRadius(),2.0f));
	float overlap_hl=sqrt(pow(c1.getCoord().getY()-c1.getRadius(),2.0f));
	float overlap_hr=sqrt(pow(b.getHeight()-c1.getCoord().getY()+c1.getRadius(),2.0f));
	float overlap_dl=sqrt(pow(c1.getCoord().getZ()-c1.getRadius(),2.0f));
	float overlap_dr=sqrt(pow(b.getDepth()-c1.getCoord().getZ()+c1.getRadius(),2.0f));
	CVector cv;
	cv.setX(overlap_wl-overlap_wr);
	cv.setY(overlap_hl-overlap_hr);
	cv.setZ(overlap_dl-overlap_dr);
	this->setValueXyz(cv*REPULSIVE_CONST);
}


