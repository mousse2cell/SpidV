/*
 * BoxForce.cpp
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#include "BoxForce.h"
#include <math.h>
#include <iostream>
#include "Box.h"
BoxForce::BoxForce() {
	// TODO Auto-generated constructor stub

}

BoxForce::~BoxForce() {
	// TODO Auto-generated destructor stub
}



void BoxForce::evalForce(Cell & c1, const Box & c2)
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

void BoxForce::evalAttractiveForce(Cell & /*c1*/, const Box & /*c2*/)
{

}

void BoxForce::evalRepulsiveForce(Cell & c1, const Box & b)
{
	float overlap_wl=-fmin((c1.getCoord().getX()-c1.getRadius()),0.0f);
	float overlap_wr=-fmin((b.getWidth()-(c1.getCoord().getX()+c1.getRadius())),0.0f);
	float overlap_hl=-fmin((c1.getCoord().getY()-c1.getRadius()),0.0f);
	float overlap_hr=-fmin((b.getHeight()-(c1.getCoord().getY()+c1.getRadius())),0.0f);
	float overlap_dl=-fmin((c1.getCoord().getZ()-c1.getRadius()),0.0f);
	float overlap_dr=-fmin((b.getDepth()-(c1.getCoord().getZ()+c1.getRadius())),0.0f);
	CVector cv;
	//std::cout<<overlap_wl<<"--"<<overlap_wr<<"--"<<overlap_hl<<"--"<<overlap_hr<<"--"<<overlap_dl<<"--"<<overlap_dr<<"--"<<c1.getCoord().getX()<<"---"<<c1.getCoord().getY()<<"-"<<c1.getRadius()<<"-"<<b.getWidth()<<"--"<<b.getDepth()<<std::endl;
	cv.setX(overlap_wl-overlap_wr);
	cv.setY(overlap_hl-overlap_hr);
	cv.setZ(overlap_dl-overlap_dr);
	c1.resetBoxCol();
	if(cv.getX()>0.0f) c1.setWl(true);
	if(cv.getX()<0.0f) c1.setWr(true);
	if(cv.getY()>0.0f) c1.setHl(true);
	if(cv.getY()<0.0f) c1.setHr(true);
	if(cv.getZ()>0.0f) c1.setDl(true);
	if(cv.getZ()<0.0f) c1.setDr(true);
	this->setValueXyz(cv*REPULSIVE_CONST);
}


