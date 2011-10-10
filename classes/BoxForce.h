/*
 * BoxForce.h
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#ifndef BOXFORCE_H_
#define BOXFORCE_H_

#include "Force.h"
#include "Cell.h"
#include "Box.h"



class BoxForce: public Force {
public:
	BoxForce();
    BoxForce(const Cell *c1,const Box *c2);
	virtual ~BoxForce();
    void evalAttractiveForce(const Cell &c1,const Box &b);
    void evalRepulsiveForce(const Cell &c1,const Box &b);
    void evalForce(const Cell &c1, const Box &b);
};

#endif /* BOXFORCE_H_ */
