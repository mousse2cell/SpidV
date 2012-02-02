/*
 * Sphere.h
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Container.h"
#include "CVector.h"


class Sphere: public Container {
public:
	Sphere();
	Sphere(CVector cent,float radius);
	Sphere(std::vector<Cell*> c,CVector cent,float radius);
	virtual ~Sphere();
	void generateRandomCells(int nbcells, float radius);
	float getRadius() const;
	void setRadius(float r);
	CVector getCentroid() const;
	void setCentroid(CVector cv);
	void reduce(const float pix);
	void updateForces();
	void applyForces();
	float getOriginRadius() const;
	void exportToFile(std::string file) const;
private:
	CVector centroid;
	float radius;
	float originRadius;
};

#endif /* SPHERE_H_ */
