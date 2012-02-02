/*
 * CellForce.h
 *
 *  Created on: 10 oct. 2011
 *      Author: mobilette
 */

#ifndef CELLFORCE_H_
#define CELLFORCE_H_

#include "Force.h"
#include "Cell.h"

class CellForce: public Force {
public:
	CellForce();
    CellForce(const Cell *c1,const Cell *c2);
	virtual ~CellForce();
	void evalForce(Cell &c1, Cell &c2);
	void evalAttractiveForce(Cell &c1,Cell &c2);
	void evalRepulsiveForce(Cell &c1,Cell &c2);
    const Cell* getC1() const;
    void setC1(const Cell* c1);
    const Cell* getC2() const;
    void setC2(const Cell* c2);
private :
    const Cell* c1;
    const Cell* c2;
};


#endif /* CELLFORCE_H_ */
