/*
 * SphereForce.cpp
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#include "SphereForce.h"
#include "Sphere.h"

SphereForce::SphereForce() {
	// TODO Auto-generated constructor stub

}

SphereForce::~SphereForce() {
	// TODO Auto-generated destructor stub
}


void SphereForce::evalForce(Cell & c1, const Sphere & s)
{

	switch (type)
	{
		case 1:
		{
			evalAttractiveForce(c1,s);
			break;
		}
		case 2:
		{
			evalRepulsiveForce(c1,s);
			break;
		}
		default:{std::cout<<"Error, type unknown !"<<std::endl;break;}
	}
}

void SphereForce::evalAttractiveForce(Cell & /*c1*/, const Sphere & /*c2*/)
{

}

void SphereForce::evalRepulsiveForce(Cell & c1, const Sphere & s)
{
	float overlap=fmax(((c1.getCoord().distanceTo(s.getCentroid())+c1.getRadius())-s.getRadius()),0.0f);
	CVector cv;
	if(overlap==0.0f) {this->setValueXyz(cv);return;}
     std::cout<<c1.getID()<<"---"<<overlap<<std::endl;
	//cv=(c1.getCoord()/fmax(c1.getCoord().getAbsoluteMax(),1))*overlap;
	cv=c1.getCoord();
	cv = cv/sqrt(pow(cv.getX(),2)+pow(cv.getY(),2)+pow(cv.getZ(),2));
	//cv=cv*(overlap/(c1.getCoord().distanceTo(s.getCentroid())+c1.getRadius())); // utiliser fraction de la distance pour scaler
	cv.reverseSign();
	c1.resetBoxCol();
	/*if(strcmp(c1.getID().c_str(),"4")==1){

		std::cout<<c1.getID().c_str()<<"overlap :"<<overlap<<"--"<<c1.getCoord().distanceTo(s.getCentroid())<<"\n fact : "<<(overlap/(c1.getCoord().distanceTo(s.getCentroid())+c1.getRadius()))<<"\nVecteur : "<<std::endl;
		cv.print();
		c1.getCoord().print();
	}*/
	if(cv.getX()>0.0f) c1.setWl(true);
	if(cv.getX()<0.0f) c1.setWr(true);
	if(cv.getY()>0.0f) c1.setHl(true);
	if(cv.getY()<0.0f) c1.setHr(true);
	if(cv.getZ()>0.0f) c1.setDl(true);
	if(cv.getZ()<0.0f) c1.setDr(true);
	this->setValueXyz((cv*overlap*REPULSIVE_CONST));
}
