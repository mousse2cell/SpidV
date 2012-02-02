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
//#include "Box.h"



class BoxForce: public Force {
public:
	BoxForce();
	virtual ~BoxForce();
    void evalAttractiveForce(Cell &c1,const Box &b);
    void evalRepulsiveForce(Cell &c1,const Box &b);
    void evalForce(Cell &c1, const Box &b);
};

#endif /* BOXFORCE_H_ */
