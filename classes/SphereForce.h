/*
 * SphereForce.h
 *
 *  Created on: 17 oct. 2011
 *      Author: mobilette
 */

#ifndef SPHEREFORCE_H_
#define SPHEREFORCE_H_

#include "Force.h"
#include <math.h>
#include <iostream>


class SphereForce: public Force {
public:
	SphereForce();
	virtual ~SphereForce();
	void evalAttractiveForce(Cell &c1,const Sphere &s);
	void evalRepulsiveForce(Cell &c1,const Sphere &s);
	void evalForce(Cell &c1, const Sphere &s);
};

#endif /* SPHEREFORCE_H_ */
