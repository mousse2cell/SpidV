/*
 * Sphere.cpp
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#include "Sphere.h"
#include <math.h>
#include <iostream>
#include <fstream>

Sphere::Sphere() {
	// TODO Auto-generated constructor stub
	radius=0;
}
Sphere::Sphere(CVector cent,float radius):centroid(cent),radius(radius)
{
	originRadius=radius;
}
Sphere::Sphere(std::vector<Cell*> c,CVector cent,float radius):Container(c),centroid(cent),radius(radius)
{
	originRadius=radius;
}


Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}
float Sphere::getRadius() const{
	return radius;
}
void Sphere::setRadius(float r){
	if(radius==0) originRadius=radius;
	radius=r;
}
CVector Sphere::getCentroid() const{
	return this->centroid;
}
void Sphere::setCentroid(CVector cv){
	this->centroid=cv;
}
float Sphere::getOriginRadius()const {
	return originRadius;
}
void Sphere::generateRandomCells(int nbcells, float r){
	CVector coord;
	for(int i=0;i<nbcells;i++){
		do{
			coord.random(radius);
		}while(coord.distanceTo(0,0,0)>radius);
		Cell* aCell=new Cell(to_string(i+1));
		aCell->setCoord(coord);
		aCell->setRadius(r);
		addCell(aCell);
	}
}

void Sphere::reduce(const float pix){
	radius=radius-pix;
	updateForces();
}

void Sphere::updateForces()
{
	Sphere* tmpb=this;
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->checkAndSetForceWith(*tmpb);
		for(unsigned int j=0;j<cells.size();j++){
			if(i!=j){
				cells[i]->checkAndSetForceWith(*cells[j]);
			}
		}
	}
	applyForces();
	/*for(unsigned int i=0;i<cells.size();i++){
		cells[i]->checkAndSetForceWith(*tmpb);
	}
	applyForces();*/
}

void Sphere::applyForces()
{
	for(unsigned int i=0;i<cells.size();i++){
		cells[i]->applyForces();
	}
}
void Sphere::exportToFile(std::string file) const{
	ofstream myfile;
	myfile.open(file.c_str());
	for(unsigned int i=0;i<cells.size();i++){
		myfile << (to_string(cells[i]->getCoord().getX())+";"+to_string(cells[i]->getCoord().getY())+";"+to_string(cells[i]->getCoord().getZ())+"\n");
	}
	myfile.close();
}
